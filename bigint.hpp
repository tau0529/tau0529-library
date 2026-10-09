#pragma once
#include "base.hpp"

//!多倍長整数
//10億進数で行う
struct llint {
    static constexpr int64_t BASE = 1000000000LL;
    static constexpr int64_t NTT_BASE = 1000000LL;
    static constexpr int BASE_DIGITS = 9;

    vector<int64_t> blocks;
    bool sign = true;

    //コンストラクタ
    llint() {
        *this = 0;
    }
    llint(int64_t x) {
        *this = x;
    }
    llint(const string &x) {
        *this = x;
    }
    template <size_t n>
    llint(const char (&x)[n]) {
        *this = string(x);
    }

    //代入
    llint &operator=(int64_t x) {
        sign = x >= 0;
        uint64_t u = sign ? x : -(uint64_t)x;
        blocks.clear();
        if (u == 0) blocks.push_back(0);
        while (u > 0) {
            blocks.push_back(u % BASE);
            u /= BASE;
        }
        return *this;
    }
    llint &operator=(const string &x) {
        sign = true;
        blocks.clear();
        int n = x.size();
        int start = 0;
        if (n > 0 && x[0] == '-') sign = false;
        if (n > 0 && (x[0] == '-' || x[0] == '+')) start = 1;
        while (start < n && x[start] == '0') start++;
        int index = n;
        if (index == start) blocks.push_back(0);
        while (index > start) {
            int s = max(start, index - BASE_DIGITS);
            int64_t sum = 0;
            for (int i = s; i < index; i++) {
                sum = sum * 10 + x[i] - '0';
            }
            blocks.push_back(sum);
            index = s;
        }
        if (blocks.size() == 1 && blocks[0] == 0) sign = true;
        return *this;
    }
    template <size_t n>
    llint &operator=(const char (&x)[n]) {
        return *this = string(x);
    }

    //入力
    friend istream &operator>>(istream &is, llint &x) {
        string s;
        if (is >> s) x = s;
        return is;
    }
    //出力
    string to_string() const {
        string res;
        int n = blocks.size();
        if (!sign) res += '-';
        res += std::to_string(blocks[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            string s = std::to_string(blocks[i]);
            res += string(BASE_DIGITS - s.size(), '0') + s;
        }
        return res;
    }
    friend string to_string(const llint &x) {
        return x.to_string();
    }
    friend ostream &operator<<(ostream &os, const llint &x) {
        os << x.to_string();
        return os;
    }

    //繰り上がり等の処理
    void normalize() {
        int n = blocks.size();
        for (int i = 0; i < n; i++) {
            if (blocks[i] >= BASE) {
                if (i + 1 == n) {
                    blocks.push_back(0);
                    n++;
                }
                int64_t x = blocks[i] / BASE;
                blocks[i + 1] += x;
                blocks[i] -= BASE * x;
            }
            if (blocks[i] < 0) {
                assert(i + 1 < n);
                int64_t x = (BASE - 1 - blocks[i]) / BASE;
                blocks[i + 1] -= x;
                blocks[i] += BASE * x;
            }
        }
        while (blocks.size() > 1 && blocks.back() == 0) blocks.pop_back();
        if (blocks.size() == 1 && blocks[0] == 0) sign = true;
    }

    //加算
    friend llint operator+(const llint &a, const llint &b) {
        llint x;
        int n = a.blocks.size();
        int m = b.blocks.size();
        if (a.sign == b.sign) {
            x = a;
            if (n < m) x.blocks.resize(m, 0);
            for (int i = 0; i < m; i++) x.blocks[i] += b.blocks[i];
        }
        else {
            if (abs_less(a, b)) {
                x = b;
                for (int i = 0; i < n; i++) x.blocks[i] -= a.blocks[i];
            }
            else {
                x = a;
                for (int i = 0; i < m; i++) x.blocks[i] -= b.blocks[i];
            }
        }
        x.normalize();
        return x;
    }
    llint &operator+=(const llint &x) {
        *this = *this + x;
        return *this;
    }
    llint &operator++() {
        *this += 1;
        return *this;
    }
    llint operator++(int) {
        llint res = *this;
        ++(*this);
        return res;
    }

    //減算
    friend llint operator-(const llint &a, const llint &b) {
        return a + (-b);
    }
    llint &operator-=(const llint &x) {
        *this = *this - x;
        return *this;
    }
    llint &operator--() {
        *this -= 1;
        return *this;
    }
    llint operator--(int) {
        llint res = *this;
        --(*this);
        return res;
    }

    //符号反転
    friend llint operator-(llint x) {
        if (x.blocks.size() != 1 || x.blocks[0] != 0) x.sign = !x.sign;
        return x;
    }

    //2-mod convolution
    static vector<long long> convolution_ll2(const vector<long long> &a, const vector<long long> &b) {
        static constexpr int64_t MOD1 = 2113929217LL;
        static constexpr int64_t MOD2 = 2130706433LL;
        static constexpr int64_t INV = 127; //MOD1^{-1} mod MOD2
        auto c1 = convolution<2113929217>(a, b);
        auto c2 = convolution<2130706433>(a, b);
        vector<long long> c(c1.size());
        for (int i = 0; i < (int)c.size(); i++) {
            int64_t x1 = c1[i];
            int64_t x2 = c2[i];
            int64_t d = x2 - x1;
            if (d < 0) d += MOD2;
            int64_t t = d * INV % MOD2;
            c[i] = x1 + MOD1 * t;
        }
        return c;
    }

    //乗算
    friend llint operator*(const llint &a, const llint &b) {
        int n = a.blocks.size();
        int m = b.blocks.size();
        if (min(n, m) <= 150) {
            llint res;
            res.sign = a.sign == b.sign;
            res.blocks.assign(n + m, 0);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int64_t x = res.blocks[i + j] + a.blocks[i] * b.blocks[j];
                    res.blocks[i + j + 1] += x / BASE;
                    res.blocks[i + j] = x % BASE;
                }
            }
            while (res.blocks.size() > 1 && res.blocks.back() == 0) res.blocks.pop_back();
            if (res.blocks.size() == 1 && res.blocks[0] == 0) res.sign = true;
            return res;
        }
        vector<long long> na(3 * (n + 1) / 2), nb(3 * (m + 1) / 2);
        for (int i = 0; i < (n + 1) / 2; i++) {
            int64_t x = a.blocks[i * 2];
            if (i * 2 + 1 < n) x += a.blocks[i * 2 + 1] * BASE;
            for (int j = 0; j < 3; j++) {
                na[3 * i + j] = x % NTT_BASE;
                x /= NTT_BASE;
            }
        }
        while (na.size() > 1 && na.back() == 0) na.pop_back();
        for (int i = 0; i < (m + 1) / 2; i++) {
            int64_t x = b.blocks[i * 2];
            if (i * 2 + 1 < m) x += b.blocks[i * 2 + 1] * BASE;
            for (int j = 0; j < 3; j++) {
                nb[3 * i + j] = x % NTT_BASE;
                x /= NTT_BASE;
            }
        }
        while (nb.size() > 1 && nb.back() == 0) nb.pop_back();
        vector<long long> nc;
        #if HAS_ACL
            nc = convolution_ll2(na, nb);
        #else
            nc.resize(na.size() + nb.size() - 1);
            for (int i = 0; i < (int)na.size(); i++) {
                for (int j = 0; j < (int)nb.size(); j++) {
                    nc[i + j] += na[i] * nb[j];
                }
            }
        #endif
        int l = nc.size();
        for (int i = 0; i < l; i++) {
            if (nc[i] >= NTT_BASE) {
                if (i + 1 == l) {
                    nc.push_back(0);
                    l++;
                }
                nc[i + 1] += nc[i] / NTT_BASE;
                nc[i] %= NTT_BASE;
            }
        }
        while (l % 3 != 0) {
            nc.push_back(0);
            l++;
        }
        llint res;
        res.sign = a.sign == b.sign;
        res.blocks.resize(2 * nc.size() / 3);
        for (int i = 0; i < l / 3; i++) {
            int64_t x = 0;
            x += nc[i * 3];
            x += nc[i * 3 + 1] * NTT_BASE;
            x += nc[i * 3 + 2] * NTT_BASE * NTT_BASE;
            res.blocks[i * 2] = x % BASE;
            res.blocks[i * 2 + 1] = x / BASE;
        }
        while (res.blocks.size() > 1 && res.blocks.back() == 0) res.blocks.pop_back();
        if (res.blocks.size() == 1 && res.blocks[0] == 0) res.sign = true;
        return res;
    }
    llint &operator*=(const llint &x) {
        *this = *this * x;
        return *this;
    }

    //逆数の近似値 BASE^(size+n)倍
    llint inverse(int n) const {
        int m = blocks.size();
        assert(m != 1 || blocks[0] != 0);
        llint x;
        if (m == 1) x = BASE * BASE / blocks[0];
        else {
            int64_t head = blocks.back() * BASE + blocks.end()[-2];
            x = (__int128_t)BASE * BASE * BASE / head;
        }
        int k = 1;
        while (k < n) {
            int nk = min(2 * k, n);
            int l = min(nk + 2, m);
            llint h;
            h.blocks.assign(blocks.end() - l, blocks.end());
            llint y;
            if (l < k) y = h * x * x;
            else y = x * x * h;
            x = (x + x).mul_base(nk - k) - (y).div_base(l + 2 * k - nk);
            k = nk;
        };
        return x;
    }

    //BASE^k倍
    llint mul_base(int k) const {
        if (blocks.size() == 1 && blocks[0] == 0) return 0;
        llint res;
        res.sign = sign;
        res.blocks.assign(k, 0);
        res.blocks.insert(res.blocks.end(), blocks.begin(), blocks.end());
        return res;
    }

    //BASE^kで除算
    llint div_base(int k) const {
        if (k >= (int)blocks.size()) return 0;
        llint res;
        res.sign = sign;
        res.blocks.assign(blocks.begin() + k, blocks.end());
        return res;
    }

    //除算
    friend llint operator/(const llint &a, const llint &b) {
        if (abs_less(a, b)) return 0;
        llint aa = abs(a);
        llint bb = abs(b);
        int n = aa.blocks.size() - bb.blocks.size() + 1;
        llint x = (aa * bb.inverse(n)).div_base(bb.blocks.size() + n);
        llint c = x * bb;
        if (aa >= c + bb) x++;
        if (aa < c) x--;
        x.sign = a.sign == b.sign;
        return x;
    }
    llint &operator/=(const llint &x) {
        *this = *this / x;
        return *this;
    }
    friend llint operator%(const llint &a, const llint &b) {
        return a - b * (a / b);
    }
    llint &operator%=(const llint &x) {
        *this = *this % x;
        return *this;
    }

    //大小比較
    friend bool abs_less(const llint &a, const llint &b) {
        int n = a.blocks.size();
        int m = b.blocks.size();
        if (n != m) return n < m;
        for (int i = n - 1; i >= 0; i--) if (a.blocks[i] != b.blocks[i]) return a.blocks[i] < b.blocks[i];
        return false;
    }
    friend bool operator<(const llint &a, const llint &b) {
        if (a.sign != b.sign) return b.sign;
        if (a.sign) return abs_less(a, b);
        return abs_less(b, a);
    }
    friend bool operator>(const llint &a, const llint &b) {
        return b < a;
    }
    friend bool operator<=(const llint &a, const llint &b) {
        return !(a > b);
    }
    friend bool operator>=(const llint &a, const llint &b) {
        return !(a < b);
    }
    friend bool operator==(const llint &a, const llint &b) {
        if (a.sign != b.sign) return false;
        if (a.blocks != b.blocks) return false;
        return true;
    }
    friend bool operator!=(const llint &a, const llint &b) {
        return !(a == b);
    }

    //絶対値
    friend llint abs(llint x) {
        x.sign = true;
        return x;
    }

    //桁数
    int digits() const {
        int res = BASE_DIGITS * (blocks.size() - 1);
        int64_t x = blocks.back();
        do {
            res++;
            x /= 10;
        } while (x > 0);
        return res;
    }
};