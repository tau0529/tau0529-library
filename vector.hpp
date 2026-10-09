#pragma once
#include "prototype.hpp"

//!vector関連
//*入出力
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (T &x : v) is >> x;
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    bool first = true;
    for (const auto &x : v) {
        if (!first) os << " ";
        os << x;
        first = false;
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
    bool first = true;
    for (const auto &x : v) {
        if (!first) os << "\n";
        os << x;
        first = false;
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<vector<vector<T>>> &v) {
    bool first = true;
    for (const auto &x : v) {
        if (!first) os << "\n\n";
        os << x;
        first = false;
    }
    return os;
}

//複数ベクター同時受け取り (各行にAi Biが書かれてるタイプ)
template <typename T, typename... Ts>
void vcin(vector<T> &first, vector<Ts> &... rest) {
    assert(((rest.size() == first.size()) && ...));
    for (int i = 0; i < (int)first.size(); i++) {
        cin >> first[i], (cin >> ... >> rest[i]);
    }
}

//ジャグ配列
template <typename T>
void jagcin(vector<vector<T>> &vv) {
    for (auto &v : vv) {
        int k;
        cin >> k;
        v.resize(k);
        cin >> v;
    }
}


//*vectorと定数の演算
template <typename T1, typename T2>
requires (!is_vector<T2>)
vector<T1> operator+(const vector<T1> &v, const T2 &a) {
    vector<T1> res = v;
    res += a;
    return res;
}
template <typename T1, typename T2>
requires (!is_vector<T2>)
vector<T1> operator-(const vector<T1> &v, const T2 &a) {
    vector<T1> res = v;
    res -= a;
    return res;
}
template <typename T1, typename T2>
requires (!is_vector<T2>)
vector<T1> operator*(const vector<T1> &v, const T2 &a) {
    vector<T1> res = v;
    res *= a;
    return res;
}
template <typename T1, typename T2>
requires (!is_vector<T2>)
vector<T1> operator/(const vector<T1> &v, const T2 &a) {
    vector<T1> res = v;
    res /= a;
    return res;
}
template <typename T1, typename T2>
requires (!is_vector<T2>)
vector<T1> operator%(const vector<T1> &v, const T2 &a) {
    vector<T1> res = v;
    res %= a;
    return res;
}

template <typename T1, typename T2>
requires (!is_vector<T2>)
vector<T1> &operator+=(vector<T1> &v, const T2 &a) {
    for (auto &x : v) x += a;
    return v;
}
template <typename T1, typename T2>
requires (!is_vector<T2>)
vector<T1> &operator-=(vector<T1> &v, const T2 &a) {
    for (auto &x : v) x -= a;
    return v;
}
template <typename T1, typename T2>
requires (!is_vector<T2>)
vector<T1> &operator*=(vector<T1> &v, const T2 &a) {
    for (auto &x : v) x *= a;
    return v;
}
template <typename T1, typename T2>
requires (!is_vector<T2>)
vector<T1> &operator/=(vector<T1> &v, const T2 &a) {
    for (auto &x : v) x /= a;
    return v;
}
template <typename T1, typename T2>
requires (!is_vector<T2>)
vector<T1> &operator%=(vector<T1> &v, const T2 &a) {
    for (auto &x : v) x %= a;
    return v;
}
template <typename T>
vector<T> &operator++(vector<T> &v) {
    for (auto &x : v) ++x;
    return v;
}
template <typename T>
vector<T> &operator--(vector<T> &v) {
    for (auto &x : v) --x;
    return v;
}
template <typename T>
vector<T> operator++(vector<T> &v, int) {
    vector<T> res = v;
    ++v;
    return res;
}
template <typename T>
vector<T> operator--(vector<T> &v, int) {
    vector<T> res = v;
    --v;
    return res;
}


//*vector同士の演算
template <typename T>
vector<T> operator+(const vector<T> &v1, const vector<T> &v2) {
    vector<T> v = v1;
    v += v2;
    return v;
}
template <typename T>
vector<T> operator-(const vector<T> &v1, const vector<T> &v2) {
    vector<T> v = v1;
    v -= v2;
    return v;
}
template <typename T>
vector<T> operator*(const vector<T> &v1, const vector<T> &v2) {
    vector<T> v = v1;
    v *= v2;
    return v;
}
template <typename T>
vector<T> operator/(const vector<T> &v1, const vector<T> &v2) {
    vector<T> v = v1;
    v /= v2;
    return v;
}
template <typename T>
vector<T> operator%(const vector<T> &v1, const vector<T> &v2) {
    vector<T> v = v1;
    v %= v2;
    return v;
}

template <typename T>
vector<T> &operator+=(vector<T> &v1, const vector<T> &v2) {
    assert(v1.size() == v2.size());
    for (int i = 0; i < (int)v1.size(); i++) v1[i] += v2[i];
    return v1;
}
template <typename T>
vector<T> &operator-=(vector<T> &v1, const vector<T> &v2) {
    assert(v1.size() == v2.size());
    for (int i = 0; i < (int)v1.size(); i++) v1[i] -= v2[i];
    return v1;
}
template <typename T>
vector<T> &operator*=(vector<T> &v1, const vector<T> &v2) {
    assert(v1.size() == v2.size());
    for (int i = 0; i < (int)v1.size(); i++) v1[i] *= v2[i];
    return v1;
}
template <typename T>
vector<T> &operator/=(vector<T> &v1, const vector<T> &v2) {
    assert(v1.size() == v2.size());
    for (int i = 0; i < (int)v1.size(); i++) v1[i] /= v2[i];
    return v1;
}
template <typename T>
vector<T> &operator%=(vector<T> &v1, const vector<T> &v2) {
    assert(v1.size() == v2.size());
    for (int i = 0; i < (int)v1.size(); i++) v1[i] %= v2[i];
    return v1;
}


//*リストの操作
//小さい順
template <typename T>
void Vsort(T &v) {
    sort(v.begin(), v.end());
}

//大きい順
template <typename T>
void Vsortg(T &v) {
    sort(v.rbegin(), v.rend());
}

//リバース
template <typename T>
void Vreverse(T &v) {
    reverse(v.begin(), v.end());
}

//重複の削除 ソート必須！
template <typename T>
void Vunique(T &v) {
    v.erase(unique(v.begin(), v.end()), v.end());
}

//上下反転
template <typename T>
void UDflip(vector<T> &v) {
    reverse(v.begin(), v.end());
}

//左右反転
template <typename T>
void LRflip(vector<T> &v) {
    for (auto &x : v) reverse(x.begin(), x.end());
}

//左シフト
template <typename T>
void Vrotate(T &v, int64_t n) {
    if (v.empty()) return;
    n %= (int64_t)v.size();
    if (n < 0) n += (int64_t)v.size();
    rotate(v.begin(), v.begin() + n, v.end());
}

//最小値
template <typename T>
auto Vmin(const T &v) {
    assert(!v.empty());
    return *min_element(v.begin(), v.end());
}

//最大値
template <typename T>
auto Vmax(const T &v) {
    assert(!v.empty());
    return *max_element(v.begin(), v.end());
}

//総和
template <typename T>
T Vsum(const vector<T> &v) {
    return accumulate(v.begin(), v.end(), T(0));
}

//ソートしたindexを取得
template <typename T>
vector<int> Vargsort(const vector<T> &v) {
    vector<int> res(v.size());
    iota(res.begin(), res.end(), 0);
    sort(res.begin(), res.end(), [&](int i, int j) {
        if (v[i] != v[j]) return v[i] < v[j];
        return i < j;
    });
    return res;
}
//大きい順ソートしたindexを取得
template <typename T>
vector<int> Vargsortg(const vector<T> &v) {
    vector<int> res(v.size());
    iota(res.begin(), res.end(), 0);
    sort(res.begin(), res.end(), [&](int i, int j) {
        if (v[i] != v[j]) return v[i] > v[j];
        return i < j;
    });
    return res;
}

//右回転
template <typename T>
void VVrotate(vector<vector<T>> &v) {
    if (v.empty() || v[0].empty()) return;
    int H = v.size();
    int W = v[0].size();
    vector<vector<T>> res(W, vector<T>(H));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            res[j][H - i - 1] = v[i][j];
        }
    }
    v = move(res);
}
void VVrotate(vector<string> &v) {
    if (v.empty() || v[0].empty()) return;
    int H = v.size();
    int W = v[0].size();
    vector<string> res(W, string(H, ' '));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            res[j][H - i - 1] = v[i][j];
        }
    }
    v = move(res);
}

//左回転
template <typename T>
void VVrotateg(vector<vector<T>> &v) {
    if (v.empty() || v[0].empty()) return;
    int H = v.size();
    int W = v[0].size();
    vector<vector<T>> res(W, vector<T>(H));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            res[W - j - 1][i] = v[i][j];
        }
    }
    v = move(res);
}
void VVrotateg(vector<string> &v) {
    if (v.empty() || v[0].empty()) return;
    int H = v.size();
    int W = v[0].size();
    vector<string> res(W, string(H, ' '));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            res[W - j - 1][i] = v[i][j];
        }
    }
    v = move(res);
}