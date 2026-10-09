#pragma once
#include "base.hpp"

//!数学系
//*基本
int64_t nPr(int64_t n, int64_t r) {
    if (r < 0 || n < r) return 0;
    int64_t res = 1;
    for (int64_t i = 0; i < r; i++) res *= n - i;
    return res;
}

int64_t nCr(int64_t n, int64_t r) {
    if (r < 0 || n < r) return 0;
    r = min(r, n - r);
    int64_t res = 1;
    for (int64_t i = 0; i < r; i++) res = res * (n - i) / (i + 1);
    return res;
}

int64_t power(int64_t a, int64_t b) {
    int64_t res = 1;
    while (b > 0) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

//MOD累乗
int64_t modpow(int64_t a, int64_t b, int64_t mod) {
    int64_t res = 1 % mod;
    a %= mod;
    if (a < 0) a += mod;
    if (mod < INT_MAX) {
        while (b > 0) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
    }
    else {
        while (b > 0) {
            if (b & 1) res = (__int128_t)res * a % mod;
            a = (__int128_t)a * a % mod;
            b >>= 1;
        }
    }
    return res;
}

int64_t factorial(int64_t n) {
    int64_t res = 1;
    for (int64_t i = 2; i <= n; i++) res *= i;
    return res;
}

//10進数右からk桁目
int64_t digit(int64_t x, int k) {
    while (k--) x /= 10;
    return x % 10;
}


//*MOD関連
struct ModMath {
    int64_t mod;
    vector<int64_t> inv_, fact_, ifact_;

    ModMath(int64_t n = 0, int64_t m = 998244353) {
        init(n, m);
    }

    //初期化
    void init(int64_t n, int64_t m = 998244353) {
        mod = m;
        assert(2 <= mod && mod < INT_MAX && 0 <= n && n < mod);
        inv_.assign(n + 1, 0);
        fact_.assign(n + 1, 1);
        ifact_.assign(n + 1, 1);
        for (int64_t i = 1; i <= n; i++) {
            if (i == 1) inv_[1] = 1;
            else inv_[i] = mod - (mod / i) * inv_[mod % i] % mod;
            fact_[i] = fact_[i - 1] * i % mod;
            ifact_[i] = ifact_[i - 1] * inv_[i] % mod;
        }
    }

    //逆元
    int64_t inv(int64_t n) const {
        assert(1 <= n && n < (int64_t)inv_.size());
        return inv_[n];
    }

    //階乗
    int64_t fact(int64_t n) const {
        assert(0 <= n && n < (int64_t)fact_.size());
        return fact_[n];
    }

    //階乗の逆元
    int64_t ifact(int64_t n) const {
        assert(0 <= n && n < (int64_t)ifact_.size());
        return ifact_[n];
    }

    //nPr
    int64_t nPr(int64_t n, int64_t r) const {
        if (r < 0 || n < r) return 0;
        return fact_[n] * ifact_[n - r] % mod;
    }

    //nCr
    int64_t nCr(int64_t n, int64_t r) const {
        if (r < 0 || n < r) return 0;
        return fact_[n] * ifact_[r] % mod * ifact_[n - r] % mod;
    }
};


//*素数系
//ミラーラビンの素数判定(int128式)
bool is_prime(int64_t n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    int64_t d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d >>= 1;
        ++s;
    }
    const vector<int64_t> A = n < 4759123141LL ? vector<int64_t>{2, 7, 61}
        : vector<int64_t>{2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (int64_t a : A) {
        if (n <= a) return true;
        int64_t b = d, t, x = 1;
        while (b > 0) {
            if (b & 1) x = (__int128_t)x * a % n;
            a = (__int128_t)a * a % n;
            b >>= 1;
        }
        if (x == 1) continue;
        for (t = 0; t < s; ++t) {
            if (x == n - 1) break;
            x = (__int128_t)x * x % n;
        }
        if (t == s) return false;
    }
    return true;
}

//エラトステネスの篩
vector<bool> eratosthenes(int64_t n) {
    vector<bool> res(n + 1, true);
    res[0] = false;
    if (n >= 1) res[1]= false;
    if (n >= 2) {
        for (int64_t i = 4; i <= n; i += 2) res[i] = false;
    }
    for (int64_t i = 3; i <= n / i; i += 2) {
        if (!res[i]) continue;
        for (int64_t j = i * i; j <= n; j += i) res[j] = false;
    }
    return res;
}

//素数列挙
vector<int64_t> prime_list(int64_t n) {
    vector<bool> P = eratosthenes(n);
    vector<int64_t> res;
    if (n >= 2) res.push_back(2);
    for (int64_t i = 3; i <= n; i += 2) {
        if (P[i]) res.push_back(i);
    }
    return res;
}


//*素因数分解系
//素因数分解(指数まとめ)
vector<pair<int64_t, int64_t>> primell(int64_t n) {
    vector<pair<int64_t, int64_t>> res;
    int64_t c = 0;
    while (n % 2 == 0) {
        n /= 2;
        c++;
    }
    if (c) res.push_back({2, c});
    for (int64_t p = 3; p <= n / p; p += 2) {
        if (n % p != 0) continue;
        c = 0;
        while (n % p == 0) {
            n /= p;
            c++;
        }
        res.push_back({p, c});
    }
    if (n > 1) res.push_back({n, 1});
    return res;
}

//素因数一覧
vector<int64_t> primel(int64_t n) {
    vector<int64_t> res;
    for (auto [p, c] : primell(n)) {
        for (int64_t i = 0; i < c; i++) res.push_back(p);
    }
    return res;
}

//素因数の個数
int64_t primec(int64_t n) {
    int64_t res = 0;
    for (auto [p, c] : primell(n)) res += c;
    return res;
}

//約数列挙
vector<int64_t> factorl(int64_t n) {
    vector<int64_t> res = {1};
    for (auto [p, c] : primell(n)) {
        int64_t m = res.size(), x = 1;
        for (int64_t i = 1; i <= c; i++) {
            x *= p;
            for (int64_t j = 0; j < m; j++) {
                res.push_back(res[j] * x);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}

//約数の個数
int64_t factorc(int64_t n) {
    int64_t res = 1;
    for (auto [p, c] : primell(n)) res *= c + 1;
    return res;
}


//*線形篩
struct LinearSieve {
    vector<int64_t> spf, primes;

    LinearSieve(int64_t n = 0) {
        init(n);
    }

    //初期化
    void init(int64_t n) {
        spf.assign(n + 1, 0);
        primes.clear();
        for (int64_t i = 2; i <= n; i++) {
            if (spf[i] == 0) {
                spf[i] = i;
                primes.push_back(i);
            }
            for (int64_t p : primes) {
                if (p > spf[i] || p > n / i) break;
                spf[i * p] = p;
            }
        }
    }

    //素数判定
    bool is_prime(int64_t n) const {
        return n >= 2 && n < (int64_t)spf.size() && spf[n] == n;
    }

    //素因数分解(指数まとめ)
    vector<pair<int64_t, int64_t>> primell(int64_t n) const {
        vector<pair<int64_t, int64_t>> res;
        while (n > 1) {
            int64_t p = spf[n], c = 0;
            while (n % p == 0) {
                n /= p;
                c++;
            }
            res.push_back({p, c});
        }
        return res;
    }

    //素因数一覧
    vector<int64_t> primel(int64_t n) const {
        vector<int64_t> res;
        while (n > 1) {
            int64_t p = spf[n];
            res.push_back(p);
            n /= p;
        }
        return res;
    }

    //素因数の個数
    int64_t primec(int64_t n) const {
        int64_t res = 0;
        while (n > 1) {
            n /= spf[n];
            res++;
        }
        return res;
    }

    //約数列挙
    vector<int64_t> factorl(int64_t n) const {
        vector<int64_t> res = {1};
        for (auto [p, c] : primell(n)) {
            int64_t m = res.size(), x = 1;
            for (int64_t i = 1; i <= c; i++) {
                x *= p;
                for (int64_t j = 0; j < m; j++) {
                    res.push_back(res[j] * x);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }

    //約数の個数
    int64_t factorc(int64_t n) const {
        int64_t res = 1;
        for (auto [p, c] : primell(n)) res *= c + 1;
        return res;
    }
};


//*拡張ユークリッドの互除法
//拡張ユークリッドの互除法
int64_t extendedGCD(int64_t a, int64_t b, int64_t &x, int64_t &y) {
    int64_t s = a, t = b, xs = 1, ys = 0, xt = 0, yt = 1;
    while (t) {
        int64_t u = s / t;
        s -= t * u;
        xs -= xt * u;
        ys -= yt * u;
        swap(s, t);
        swap(xs, xt);
        swap(ys, yt);
    }
    x = xs;
    y = ys;
    return s;
}
pair<int64_t, int64_t> extGCD(int64_t a, int64_t b) {
    int64_t x, y;
    extendedGCD(a, b, x, y);
    return {x, y};
}

//中国剰余の定理 解無しは{0, -1}
pair<int64_t, int64_t> CRT(const vector<int64_t> &b, const vector<int64_t> &m) {
    int64_t r = 0, M = 1;
    for (int64_t i = 0; i < (int64_t)b.size(); i++) {
        int64_t p, q;
        int64_t d = extendedGCD(M, m[i], p, q);
        if (((__int128_t)b[i] - r) % d != 0) return {0, -1};
        int64_t md = m[i] / d;
        int64_t t = ((__int128_t)b[i] - r) / d * p % md;
        r = ((__int128_t)r + (__int128_t)M * t) % ((__int128_t)M * md);
        M *= md;
        if (r < 0) r += M;
    }
    return {r, M};
}

//逆元
int64_t modinv(int64_t a, int64_t mod) {
    a %= mod;
    if (a < 0) a += mod;
    int64_t x, y;
    if (extendedGCD(a, mod, x, y) != 1) return -1;
    x %= mod;
    if (x < 0) x += mod;
    return x;
}