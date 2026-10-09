//!include関連
#include <bits/stdc++.h>
using namespace std;

#if __has_include(<atcoder/all>)
    #include <atcoder/all>
    using namespace atcoder;
    #define HAS_ACL 1
#else
    #define HAS_ACL 0
#endif



//!プロトタイプ宣言
//*vector関連
template <typename T> inline constexpr bool is_vector = false;
template <typename T> inline constexpr bool is_vector<vector<T>> = true;
template <typename T> istream &operator>>(istream &is, vector<T> &v);
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v);
template <typename T> ostream &operator<<(ostream &os, const vector<vector<T>> &v);
template <typename T> ostream &operator<<(ostream &os, const vector<vector<vector<T>>> &v);
template <typename T1, typename T2> requires (!is_vector<T2>) vector<T1> operator+(const vector<T1> &v, const T2 &a);
template <typename T1, typename T2> requires (!is_vector<T2>) vector<T1> operator-(const vector<T1> &v, const T2 &a);
template <typename T1, typename T2> requires (!is_vector<T2>) vector<T1> operator*(const vector<T1> &v, const T2 &a);
template <typename T1, typename T2> requires (!is_vector<T2>) vector<T1> operator/(const vector<T1> &v, const T2 &a);
template <typename T1, typename T2> requires (!is_vector<T2>) vector<T1> operator%(const vector<T1> &v, const T2 &a);
template <typename T1, typename T2> requires (!is_vector<T2>) vector<T1> &operator+=(vector<T1> &v, const T2 &a);
template <typename T1, typename T2> requires (!is_vector<T2>) vector<T1> &operator-=(vector<T1> &v, const T2 &a);
template <typename T1, typename T2> requires (!is_vector<T2>) vector<T1> &operator*=(vector<T1> &v, const T2 &a);
template <typename T1, typename T2> requires (!is_vector<T2>) vector<T1> &operator/=(vector<T1> &v, const T2 &a);
template <typename T1, typename T2> requires (!is_vector<T2>) vector<T1> &operator%=(vector<T1> &v, const T2 &a);
template <typename T> vector<T> &operator++(vector<T> &v);
template <typename T> vector<T> &operator--(vector<T> &v);
template <typename T> vector<T> operator++(vector<T> &v, int);
template <typename T> vector<T> operator--(vector<T> &v, int);
template <typename T> vector<T> operator+(const vector<T> &v1, const vector<T> &v2);
template <typename T> vector<T> operator-(const vector<T> &v1, const vector<T> &v2);
template <typename T> vector<T> operator*(const vector<T> &v1, const vector<T> &v2);
template <typename T> vector<T> operator/(const vector<T> &v1, const vector<T> &v2);
template <typename T> vector<T> operator%(const vector<T> &v1, const vector<T> &v2);
template <typename T> vector<T> &operator+=(vector<T> &v1, const vector<T> &v2);
template <typename T> vector<T> &operator-=(vector<T> &v1, const vector<T> &v2);
template <typename T> vector<T> &operator*=(vector<T> &v1, const vector<T> &v2);
template <typename T> vector<T> &operator/=(vector<T> &v1, const vector<T> &v2);
template <typename T> vector<T> &operator%=(vector<T> &v1, const vector<T> &v2);


//*pair関連
template <typename T> inline constexpr bool is_pair = false;
template <typename T1, typename T2> inline constexpr bool is_pair<pair<T1, T2>> = true;
template <typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p);
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p);
template <typename T1, typename T2, typename T3> requires (!is_pair<T3>) pair<T1, T2> operator+(const pair<T1, T2> &p, const T3 &a);
template <typename T1, typename T2, typename T3> requires (!is_pair<T3>) pair<T1, T2> operator-(const pair<T1, T2> &p, const T3 &a);
template <typename T1, typename T2, typename T3> requires (!is_pair<T3>) pair<T1, T2> operator*(const pair<T1, T2> &p, const T3 &a);
template <typename T1, typename T2, typename T3> requires (!is_pair<T3>) pair<T1, T2> operator/(const pair<T1, T2> &p, const T3 &a);
template <typename T1, typename T2, typename T3> requires (!is_pair<T3>) pair<T1, T2> operator%(const pair<T1, T2> &p, const T3 &a);
template <typename T1, typename T2, typename T3> requires (!is_pair<T3>) pair<T1, T2> &operator+=(pair<T1, T2> &p, const T3 &a);
template <typename T1, typename T2, typename T3> requires (!is_pair<T3>) pair<T1, T2> &operator-=(pair<T1, T2> &p, const T3 &a);
template <typename T1, typename T2, typename T3> requires (!is_pair<T3>) pair<T1, T2> &operator*=(pair<T1, T2> &p, const T3 &a);
template <typename T1, typename T2, typename T3> requires (!is_pair<T3>) pair<T1, T2> &operator/=(pair<T1, T2> &p, const T3 &a);
template <typename T1, typename T2, typename T3> requires (!is_pair<T3>) pair<T1, T2> &operator%=(pair<T1, T2> &p, const T3 &a);
template <typename T1, typename T2> pair<T1, T2> &operator++(pair<T1, T2> &p);
template <typename T1, typename T2> pair<T1, T2> &operator--(pair<T1, T2> &p);
template <typename T1, typename T2> pair<T1, T2> operator++(pair<T1, T2> &p, int);
template <typename T1, typename T2> pair<T1, T2> operator--(pair<T1, T2> &p, int);
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &p1, const pair<T1, T2> &p2);
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &p1, const pair<T1, T2> &p2);
template <typename T1, typename T2> pair<T1, T2> operator*(const pair<T1, T2> &p1, const pair<T1, T2> &p2);
template <typename T1, typename T2> pair<T1, T2> operator/(const pair<T1, T2> &p1, const pair<T1, T2> &p2);
template <typename T1, typename T2> pair<T1, T2> operator%(const pair<T1, T2> &p1, const pair<T1, T2> &p2);
template <typename T1, typename T2> pair<T1, T2> &operator+=(pair<T1, T2> &p1, const pair<T1, T2> &p2);
template <typename T1, typename T2> pair<T1, T2> &operator-=(pair<T1, T2> &p1, const pair<T1, T2> &p2);
template <typename T1, typename T2> pair<T1, T2> &operator*=(pair<T1, T2> &p1, const pair<T1, T2> &p2);
template <typename T1, typename T2> pair<T1, T2> &operator/=(pair<T1, T2> &p1, const pair<T1, T2> &p2);
template <typename T1, typename T2> pair<T1, T2> &operator%=(pair<T1, T2> &p1, const pair<T1, T2> &p2);


//*その他STL関連
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &m);
template <typename T> ostream &operator<<(ostream &os, const set<T> &s);
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &s);
template <typename T1, typename T2> ostream &operator<<(ostream &os, const unordered_map<T1, T2> &m);
template <typename T> ostream &operator<<(ostream &os, const unordered_set<T> &s);
template <typename T> ostream &operator<<(ostream &os, queue<T> q);
template <class T, class Container, class Compare> ostream &operator<<(ostream &os, priority_queue<T, Container, Compare> q);
template <typename T> ostream &operator<<(ostream &os, const deque<T> &q);
template <typename T> ostream &operator<<(ostream &os, stack<T> s);
#if HAS_ACL
    template <int m> istream &operator>>(istream &is, static_modint<m> &i);
    template <int id> istream &operator>>(istream &is, dynamic_modint<id> &i);
    template <int m> ostream &operator<<(ostream &os, const static_modint<m> &i);
    template <int id> ostream &operator<<(ostream &os, const dynamic_modint<id> &i);
#endif



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



//!pair関連
//*入出力
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
    is >> p.first >> p.second;
    return is;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}


//*pairと定数の演算
template <typename T1, typename T2, typename T3>
requires (!is_pair<T3>)
pair<T1, T2> operator+(const pair<T1, T2> &p, const T3 &a) {
    pair<T1, T2> res = p;
    res += a;
    return res;
}
template <typename T1, typename T2, typename T3>
requires (!is_pair<T3>)
pair<T1, T2> operator-(const pair<T1, T2> &p, const T3 &a) {
    pair<T1, T2> res = p;
    res -= a;
    return res;
}
template <typename T1, typename T2, typename T3>
requires (!is_pair<T3>)
pair<T1, T2> operator*(const pair<T1, T2> &p, const T3 &a) {
    pair<T1, T2> res = p;
    res *= a;
    return res;
}
template <typename T1, typename T2, typename T3>
requires (!is_pair<T3>)
pair<T1, T2> operator/(const pair<T1, T2> &p, const T3 &a) {
    pair<T1, T2> res = p;
    res /= a;
    return res;
}
template <typename T1, typename T2, typename T3>
requires (!is_pair<T3>)
pair<T1, T2> operator%(const pair<T1, T2> &p, const T3 &a) {
    pair<T1, T2> res = p;
    res %= a;
    return res;
}

template <typename T1, typename T2, typename T3>
requires (!is_pair<T3>)
pair<T1, T2> &operator+=(pair<T1, T2> &p, const T3 &a) {
    p.first += a;
    p.second += a;
    return p;
}
template <typename T1, typename T2, typename T3>
requires (!is_pair<T3>)
pair<T1, T2> &operator-=(pair<T1, T2> &p, const T3 &a) {
    p.first -= a;
    p.second -= a;
    return p;
}
template <typename T1, typename T2, typename T3>
requires (!is_pair<T3>)
pair<T1, T2> &operator*=(pair<T1, T2> &p, const T3 &a) {
    p.first *= a;
    p.second *= a;
    return p;
}
template <typename T1, typename T2, typename T3>
requires (!is_pair<T3>)
pair<T1, T2> &operator/=(pair<T1, T2> &p, const T3 &a) {
    p.first /= a;
    p.second /= a;
    return p;
}
template <typename T1, typename T2, typename T3>
requires (!is_pair<T3>)
pair<T1, T2> &operator%=(pair<T1, T2> &p, const T3 &a) {
    p.first %= a;
    p.second %= a;
    return p;
}
template <typename T1, typename T2>
pair<T1, T2> &operator++(pair<T1, T2> &p) {
    ++p.first;
    ++p.second;
    return p;
}
template <typename T1, typename T2>
pair<T1, T2> &operator--(pair<T1, T2> &p) {
    --p.first;
    --p.second;
    return p;
}
template <typename T1, typename T2>
pair<T1, T2> operator++(pair<T1, T2> &p, int) {
    pair<T1, T2> old = p;
    ++p;
    return old;
}
template <typename T1, typename T2>
pair<T1, T2> operator--(pair<T1, T2> &p, int) {
    pair<T1, T2> old = p;
    --p;
    return old;
}


//*pair同士の演算
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2> &p1, const pair<T1, T2> &p2) {
    pair<T1, T2> p = p1;
    p += p2;
    return p;
}
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2> &p1, const pair<T1, T2> &p2) {
    pair<T1, T2> p = p1;
    p -= p2;
    return p;
}
template <typename T1, typename T2>
pair<T1, T2> operator*(const pair<T1, T2> &p1, const pair<T1, T2> &p2) {
    pair<T1, T2> p = p1;
    p *= p2;
    return p;
}
template <typename T1, typename T2>
pair<T1, T2> operator/(const pair<T1, T2> &p1, const pair<T1, T2> &p2) {
    pair<T1, T2> p = p1;
    p /= p2;
    return p;
}
template <typename T1, typename T2>
pair<T1, T2> operator%(const pair<T1, T2> &p1, const pair<T1, T2> &p2) {
    pair<T1, T2> p = p1;
    p %= p2;
    return p;
}

template <typename T1, typename T2>
pair<T1, T2> &operator+=(pair<T1, T2> &p1, const pair<T1, T2> &p2) {
    p1.first += p2.first;
    p1.second += p2.second;
    return p1;
}
template <typename T1, typename T2>
pair<T1, T2> &operator-=(pair<T1, T2> &p1, const pair<T1, T2> &p2) {
    p1.first -= p2.first;
    p1.second -= p2.second;
    return p1;
}
template <typename T1, typename T2>
pair<T1, T2> &operator*=(pair<T1, T2> &p1, const pair<T1, T2> &p2) {
    p1.first *= p2.first;
    p1.second *= p2.second;
    return p1;
}
template <typename T1, typename T2>
pair<T1, T2> &operator/=(pair<T1, T2> &p1, const pair<T1, T2> &p2) {
    p1.first /= p2.first;
    p1.second /= p2.second;
    return p1;
}
template <typename T1, typename T2>
pair<T1, T2> &operator%=(pair<T1, T2> &p1, const pair<T1, T2> &p2) {
    p1.first %= p2.first;
    p1.second %= p2.second;
    return p1;
}


//*pairの操作
template<typename T>
void Pswap(pair<T, T> &p) {
    swap(p.first, p.second);
}
template<typename T>
void Pswap(vector<pair<T, T>> &v) {
    for (auto &p : v) swap(p.first, p.second);
}



//!その他STL関連
//*入出力
//map
template <typename T1, typename T2>
void mapcin(map<T1, T2> &m, int n) {
    for (int i = 0; i < n; i++) {
        T1 x; T2 y;
        cin >> x >> y;
        m[x] = y;
    }
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const map<T1, T2> &m) {
    bool first = true;
    for (const auto &[key, val] : m) {
        if (!first) os << " ";
        os << key << ":" << val;
        first = false;
    }
    return os;
}

//set
template <typename T>
void setcin(set<T> &s, int n) {
    for (int i = 0; i < n; i++) {
        T x;
        cin >> x;
        s.insert(x);
    }
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &s) {
    bool first = true;
    for (const auto &x : s) {
        if (!first) os << " ";
        os << x;
        first = false;
    }
    return os;
}

//multiset
template <typename T>
void setcin(multiset<T> &s, int n) {
    for (int i = 0; i < n; i++) {
        T x;
        cin >> x;
        s.insert(x);
    }
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &s) {
    bool first = true;
    for (const auto &x : s) {
        if (!first) os << " ";
        os << x;
        first = false;
    }
    return os;
}

//unordered_map
template <typename T1, typename T2>
void mapcin(unordered_map<T1, T2> &m, int n) {
    for (int i = 0; i < n; i++) {
        T1 x; T2 y;
        cin >> x >> y;
        m[x] = y;
    }
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const unordered_map<T1, T2> &m) {
    bool first = true;
    for (const auto &[key, val] : m) {
        if (!first) os << " ";
        os << key << ":" << val;
        first = false;
    }
    return os;
}

//unordered_set
template <typename T>
void setcin(unordered_set<T> &s, int n) {
    for (int i = 0; i < n; i++) {
        T x;
        cin >> x;
        s.insert(x);
    }
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &s) {
    bool first = true;
    for (const auto &x : s) {
        if (!first) os << " ";
        os << x;
        first = false;
    }
    return os;
}

//queue
template <typename T>
void queuecin(queue<T> &q, int n) {
    for (int i = 0; i < n; i++) {
        T x;
        cin >> x;
        q.push(x);
    }
}
template <typename T>
ostream &operator<<(ostream &os, queue<T> q) {
    bool first = true;
    while (!q.empty()) {
        if (!first) os << " ";
        os << q.front();
        q.pop();
        first = false;
    }
    return os;
}

//priority_queue
template <class T, class Container, class Compare>
void queuecin(priority_queue<T, Container, Compare> &q, int n) {
    for (int i = 0; i < n; i++) {
        T x;
        cin >> x;
        q.push(x);
    }
}
template <class T, class Container, class Compare>
ostream &operator<<(ostream &os, priority_queue<T, Container, Compare> q) {
    bool first = true;
    while (!q.empty()) {
        if (!first) os << " ";
        os << q.top();
        q.pop();
        first = false;
    }
    return os;
}

//deque
template <typename T>
void dequecin(deque<T> &q, int n) {
    for (int i = 0; i < n; i++) {
        T x;
        cin >> x;
        q.push_back(x);
    }
}
template <typename T>
void queuecin(deque<T> &q, int n) {
    dequecin(q, n);
}
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &q) {
    bool first = true;
    for (const auto &x : q) {
        if (!first) os << " ";
        os << x;
        first = false;
    }
    return os;
}

//stack
template <typename T>
void stackcin(stack<T> &s, int n) {
    for (int i = 0; i < n; i++) {
        T x;
        cin >> x;
        s.push(x);
    }
}
template <typename T>
ostream &operator<<(ostream &os, stack<T> s) {
    bool first = true;
    while (!s.empty()) {
        if (!first) os << " ";
        os << s.top();
        s.pop();
        first = false;
    }
    return os;
}

//modint
#if HAS_ACL
    template <int m>
    istream &operator>>(istream &is, static_modint<m> &i) {
        int64_t x;
        is >> x;
        i = x;
        return is;
    }
    template <int id>
    istream &operator>>(istream &is, dynamic_modint<id> &i) {
        int64_t x;
        is >> x;
        i = x;
        return is;
    }
    template <int m>
    ostream &operator<<(ostream &os, const static_modint<m> &i) {
        os << i.val();
        return os;
    }
    template <int id>
    ostream &operator<<(ostream &os, const dynamic_modint<id> &i) {
        os << i.val();
        return os;
    }
#endif



//!小規模群
//*略
using lint = int64_t;
using lint7 = __int128_t; //2^7bit
using ld = long double;
using pll = pair<int64_t, int64_t>;
using plp = pair<int64_t, pair<int64_t, int64_t>>;
using ppl = pair<pair<int64_t, int64_t>, int64_t>;
using ppp = pair<pair<int64_t, int64_t>, pair<int64_t, int64_t>>;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vector<vector<T>>;
template<typename T> using vvv = vector<vector<vector<T>>>;
template<typename T> using vvvv = vector<vector<vector<vector<T>>>>;
using vl = vector<int64_t>;
using vvl = vector<vector<int64_t>>;
using vvvl = vector<vector<vector<int64_t>>>;
using vvvvl = vector<vector<vector<vector<int64_t>>>>;
using vd = vector<long double>;
using vp = vector<pair<int64_t, int64_t>>;
template<typename T> using pq = priority_queue<T, vector<T>>; // 大きい順
template<typename T> using pqg = priority_queue<T, vector<T>, greater<T>>; // 小さい順

#define pb push_back
#define mp make_pair
#define fi first
#define se second


//*マクロ
//ループマクロ
//rrは始点指定 eeは逆順 ppは閉区間
#define     re(n)       for (int64_t r_= 0;            r_<  int64_t(n);r_++)
#define    rep(i, n)    for (int64_t i = 0;            i <  int64_t(n); i++)
#define   repp(i, n)    for (int64_t i = 0;            i <= int64_t(n); i++)
#define   rrep(i, a, b) for (int64_t i = int64_t(a);   i <  int64_t(b); i++)
#define  rrepp(i, a, b) for (int64_t i = int64_t(a);   i <= int64_t(b); i++)
#define   reep(i, n)    for (int64_t i = int64_t(n)-1; i >= 0;          i--)
#define  reepp(i, n)    for (int64_t i = int64_t(n);   i >= 0;          i--)
#define  rreep(i, a, b) for (int64_t i = int64_t(b)-1; i >= int64_t(a); i--)
#define rreepp(i, a, b) for (int64_t i = int64_t(b);   i >= int64_t(a); i--)

//allマクロ
#define all(v) (v).begin(), (v).end()

//sizeをint64_tで取得
#define sz(x) ((int64_t)(x).size())

//nextpermutation
#define next_p(v) next_permutation((v).begin(), (v).end())

//範囲外ならcontinue
#define in_grid(h, w, H, W) { if ((h) < 0 || (w) < 0 || (H) <= (h) || (W) <= (w)) continue; }



//*定数
//無限
constexpr int64_t inf = 1001001001;
constexpr int64_t INF = 4004004004004004004LL;

//MOD
constexpr int64_t MOD  =  998244353;
constexpr int64_t MOD7 = 1000000007;
constexpr int64_t MOD9 = 1000000009;
#if HAS_ACL
    using mint  = modint998244353;
    using mint7 = modint1000000007;
    using mint9 = static_modint<1000000009>;
#endif

//有名数
constexpr long double pi    = 3.14159265358979323846L;
constexpr long double N_pi  = 3.14159265358979323846L;
constexpr long double N_e   = 2.71828182845904523536L;
constexpr long double N_phi = 1.61803398874989484820L;

//グリッド移動
static constexpr int64_t dh[] = {0, -1, 0, 1, -1, -1, 1, 1, 0};
static constexpr int64_t dw[] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
static constexpr char ds[] = "RULD";


//*Yes No出力
#define YES cout << "YES\n"
#define Yes cout << "Yes\n"
#define NO cout << "NO\n"
#define No cout << "No\n"
#define noo cout << "-1\n" //Negative One

void YN(bool b) {
    cout << (b ? "YES\n" : "NO\n");
}
void yn(bool b) {
    cout << (b ? "Yes\n" : "No\n");
}


//*デバッグ出力
#ifdef LOCAL
    template <typename T, typename... Ts>
    void debug(const T &x, const Ts &... xs) {
        cerr << x;
        ((cerr << ' ' << xs), ...);
        cerr << "\n";
    }

    template <typename... Ts>
    void col_dbg(const char *color, const Ts &... xs) {
        cerr << color;
        debug(xs...);
        cerr << "\033[0m";
    }
    #define dbg(...) col_dbg("\033[38;5;208m", __VA_ARGS__)
    #define rdb(...) col_dbg("\033[31m", __VA_ARGS__)
    #define gdb(...) col_dbg("\033[32m", __VA_ARGS__)
    #define ydb(...) col_dbg("\033[33m", __VA_ARGS__)
    #define bdb(...) col_dbg("\033[34m", __VA_ARGS__)
    #define mdb(...) col_dbg("\033[35m", __VA_ARGS__)
    #define cdb(...) col_dbg("\033[36m", __VA_ARGS__)
    #define wdb(...) col_dbg("\033[37m", __VA_ARGS__)
#else
    #define debug(...) ((void)0)
    #define dbg(...) ((void)0)
    #define rdb(...) ((void)0)
    #define gdb(...) ((void)0)
    #define ydb(...) ((void)0)
    #define bdb(...) ((void)0)
    #define mdb(...) ((void)0)
    #define cdb(...) ((void)0)
    #define wdb(...) ((void)0)
#endif


//*経過時間
long double Time () {
    return 1.0L * (clock()) / CLOCKS_PER_SEC;
}


//*値の更新
template <typename T1, typename T2>
bool chmin(T1 &x, const T2 &y) {
    bool b = x > y;
    if (b) x = y;
    return b;
}
template <typename T1, typename T2>
bool chmax(T1 &x, const T2 &y) {
    bool b = x < y;
    if (b) x = y;
    return b;
}
template <typename T1, typename T2>
bool CHMIN(T1 &x, const T2 &y) {
    if (x > y) x = y;
    return x == y;
}
template <typename T1, typename T2>
bool CHMAX(T1 &x, const T2 &y) {
    if (x < y) x = y;
    return x == y;
}



//!セグ木
#if HAS_ACL
    //*定義
    //定数
    static constexpr int64_t seg_mod = 998244353;
    static constexpr int64_t seg_inf = 4'000'000'000'000'000'000LL;
    static constexpr int64_t seg_id = -8'000'000'000'000'000'000LL;

    //モノイドの型 s
    struct seg_siz_s { int64_t val; int siz; };
    struct seg_idx_s { int64_t val; int idx; };
    struct seg_min_max_s {int64_t min, max; };
    struct seg_min_max_idx_s { seg_idx_s min, max; };
    struct seg_all_s { seg_idx_s min, max; int64_t sum; int siz, idx; };
    struct seg_sq_s {int64_t sum, sq; int siz; };

    constexpr seg_idx_s min(seg_idx_s a, seg_idx_s b)
        { if (a.val != b.val) return a.val < b.val ? a : b; return a.idx < b.idx ? a : b;}
    constexpr seg_idx_s max(seg_idx_s a, seg_idx_s b)
        { if (a.val != b.val) return a.val > b.val ? a : b; return a.idx < b.idx ? a : b;} //indexが小さい方を取ってる

    //項演算子 op
    constexpr int64_t sum_op(int64_t a, int64_t b) { return a + b; }
    constexpr int64_t mul_op(int64_t a, int64_t b) { return a * b; }
    constexpr int64_t sum_mod_op(int64_t a, int64_t b) { return (a + b) % seg_mod; }
    constexpr int64_t mul_mod_op(int64_t a, int64_t b) { return (a * b) % seg_mod; }
    constexpr seg_siz_s sum_siz_op(seg_siz_s a, seg_siz_s b) { return {a.val + b.val, a.siz + b.siz}; }
    constexpr seg_siz_s sum_siz_mod_op(seg_siz_s a,seg_siz_s b) { return {(a.val + b.val) % seg_mod, a.siz + b.siz}; }
    constexpr int64_t max_op(int64_t a, int64_t b) { return max(a, b); }
    constexpr int64_t min_op(int64_t a, int64_t b) { return min(a, b); }
    constexpr seg_idx_s min_idx_op(seg_idx_s a, seg_idx_s b) { return min(a, b); }
    constexpr seg_idx_s max_idx_op(seg_idx_s a, seg_idx_s b) { return max(a, b); }
    constexpr seg_min_max_s min_max_op(seg_min_max_s a, seg_min_max_s b) { return {min(a.min, b.min), max(a.max, b.max)}; }
    constexpr seg_min_max_idx_s min_max_idx_op (seg_min_max_idx_s a, seg_min_max_idx_s b)
        { return {min(a.min, b.min), max(a.max, b.max)}; }
    constexpr seg_all_s all_op(seg_all_s a, seg_all_s b)
        {return {min(a.min, b.min), max(a.max, b.max), a.sum + b.sum, a.siz + b.siz, min(a.idx, b.idx)}; }
    constexpr int64_t gcd_op(int64_t a, int64_t b) { return gcd(a, b); }
    constexpr int64_t lcm_op(int64_t a, int64_t b) { return lcm(a, b); }
    constexpr int64_t and_op(int64_t a, int64_t b) { return (a & b); }
    constexpr int64_t or_op(int64_t a, int64_t b) { return (a | b); }
    constexpr int64_t xor_op(int64_t a, int64_t b) { return (a ^ b); }
    constexpr seg_sq_s sq_op(seg_sq_s a, seg_sq_s b) { return {a.sum + b.sum, a.sq + b.sq, a.siz + b.siz}; }
    string txt_op(string a, string b) { return (a + b); }

    //単位元 e
    constexpr int64_t zero_e() { return 0; }
    constexpr seg_siz_s zero_siz_e() { return {0, 0}; }
    constexpr int64_t one_e() { return 1; }
    constexpr int64_t and_e() { return -1; }
    constexpr int64_t min_e() { return seg_inf; }
    constexpr int64_t max_e() { return -seg_inf; }
    constexpr seg_idx_s min_idx_e() { return {seg_inf, -1}; }
    constexpr seg_idx_s max_idx_e() { return {-seg_inf, -1}; }
    constexpr seg_min_max_s min_max_e() { return {seg_inf, -seg_inf}; }
    constexpr seg_min_max_idx_s min_max_idx_e() { return {{seg_inf, -1}, {-seg_inf, -1}}; }
    constexpr seg_all_s all_e() { return {{seg_inf, -1}, {-seg_inf, -1}, 0, 0, INT_MAX}; }
    constexpr seg_sq_s sq_e() { return {0, 0, 0}; }
    string empty_e() {return ""; }

    //写像の型 f
    struct seg_aff_f { int64_t a, b; };

    //ノードの更新 mapping
    constexpr int64_t add_map(int64_t f, int64_t x) { return x + f; }
    constexpr int64_t upd_map(int64_t f, int64_t x) { return f == seg_id ? x : f; }
    constexpr seg_min_max_s aff_min_max_map(seg_aff_f f, seg_min_max_s x) {
        if (x.min == seg_inf && x.max == -seg_inf) return x;
        int64_t a = x.min * f.a + f.b, b = x.max * f.a + f.b;
        return {min(a, b), max(a, b)};
    }
    constexpr seg_siz_s add_siz_map(int64_t f, seg_siz_s x) { x.val += f * x.siz; return x; }
    constexpr seg_siz_s upd_siz_map(int64_t f, seg_siz_s x) { if (f != seg_id) x.val = f * x.siz; return x; }
    constexpr seg_siz_s aff_siz_map(seg_aff_f f, seg_siz_s x) { return {x.val * f.a + f.b * x.siz, x.siz}; }
    constexpr seg_siz_s add_siz_mod_map(int64_t f, seg_siz_s x) { x.val = (x.val + f * x.siz) % seg_mod; return x; }
    constexpr seg_siz_s upd_siz_mod_map(int64_t f, seg_siz_s x) { if (f != seg_id) x.val = f * x.siz % seg_mod; return x; }
    constexpr seg_siz_s aff_siz_mod_map(seg_aff_f f, seg_siz_s x) { return {(x.val * f.a + f.b * x.siz) % seg_mod, x.siz}; }
    constexpr seg_all_s all_map(seg_aff_f f, seg_all_s x) {
        if (x.siz == 0) return x;
        if (f.a == 0) return {{f.b, x.idx}, {f.b, x.idx}, f.b * x.siz, x.siz, x.idx};
        x.min.val = x.min.val * f.a + f.b; x.max.val = x.max.val * f.a + f.b;
        return {min(x.min, x.max), max(x.min, x.max), x.sum * f.a + f.b * x.siz, x.siz, x.idx};
    }
    constexpr seg_sq_s add_sq_map(int64_t f, seg_sq_s x)
        { return {x.sum + f * x.siz, x.sq + 2 * f * x.sum + f * f * x.siz, x.siz}; }
    constexpr seg_sq_s upd_sq_map(int64_t f, seg_sq_s x)
        { if (f == seg_id) return x; return {f * x.siz, f * f * x.siz, x.siz}; }
    constexpr seg_sq_s aff_sq_map(seg_aff_f f, seg_sq_s x)
        { return {x.sum * f.a + f.b * x.siz, x.sq * f.a * f.a + 2 * x.sum * f.a * f.b + f.b * f.b * x.siz, x.siz}; }

    //パラメータの合成 composition
    constexpr int64_t add_com(int64_t f, int64_t g) { return g + f; }
    constexpr int64_t upd_com(int64_t f, int64_t g) { return f == seg_id ? g : f; }
    constexpr seg_aff_f aff_com(seg_aff_f f, seg_aff_f g) {return {g.a * f.a, g.b * f.a + f.b}; }
    constexpr seg_aff_f aff_mod_com(seg_aff_f f, seg_aff_f g) {return {g.a * f.a % seg_mod, (g.b * f.a + f.b) % seg_mod}; }

    //id
    constexpr int64_t zero_id() { return 0; }
    constexpr int64_t upd_id() { return seg_id; }
    constexpr seg_aff_f aff_id() { return {1, 0}; }


    //*シンプルなセグ木
    //区間和
    using sumtree = segtree<int64_t, sum_op, zero_e>;
    //区間積
    using multree = segtree<int64_t, mul_op, one_e>;
    //mod区間和
    using summodtree_base = segtree<int64_t, sum_mod_op, zero_e>;
    struct summodtree : summodtree_base {
        summodtree(int n) : summodtree_base(n) {}
        summodtree(const vector<int64_t> &v) : summodtree_base([&]{
            vector<int64_t> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = (v[i] % seg_mod + seg_mod) % seg_mod;
            return init;
        }()) {}
        void set(int p, int64_t x) { summodtree_base::set(p, (x % seg_mod + seg_mod) % seg_mod); }
    };
    //mod区間積
    using mulmodtree_base = segtree<int64_t, mul_mod_op, one_e>;
    struct mulmodtree : mulmodtree_base {
        mulmodtree(int n) : mulmodtree_base(n) {}
        mulmodtree(const vector<int64_t> &v) : mulmodtree_base([&]{
            vector<int64_t> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = (v[i] % seg_mod + seg_mod) % seg_mod;
            return init;
        }()) {}
        void set(int p, int64_t x) { mulmodtree_base::set(p, (x % seg_mod + seg_mod) % seg_mod); }
    };
    //区間最小
    using mintree = segtree<int64_t, min_op, min_e>;
    //区間最大
    using maxtree = segtree<int64_t, max_op, max_e>;
    //区間最大公約数
    using gcdtree = segtree<int64_t, gcd_op, zero_e>;
    //区間最小公倍数
    using lcmtree = segtree<int64_t, lcm_op, one_e>;
    //区間AND
    using andtree = segtree<int64_t, and_op, and_e>;
    //区間OR
    using ortree = segtree<int64_t, or_op, zero_e>;
    //区間XOR
    using xortree = segtree<int64_t, xor_op, zero_e>;
    //区間でつなげたtxt
    using txttree = segtree<string, txt_op, empty_e>;


    //*シンプルでないセグ木
    //区間最小＆最大
    using minmaxtree_base = segtree<seg_min_max_s, min_max_op, min_max_e>;
    struct minmaxtree : minmaxtree_base {
        minmaxtree (int n) : minmaxtree_base(n) {}
        minmaxtree (const vector<int64_t> &v) : minmaxtree_base([&]{
            vector<seg_min_max_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {v[i], v[i]};
            return init;
        }()) {}
        void set(int p, int64_t x) { minmaxtree_base::set(p, {x, x}); }
        int64_t get(int p) { return minmaxtree_base::get(p).min; }
    };
    //indexが取れる区間最小
    using minidxtree_base = segtree<seg_idx_s, min_idx_op, min_idx_e>;
    struct minidxtree : minidxtree_base {
        minidxtree (int n) : minidxtree_base(n) {}
        minidxtree (const vector<int64_t> &v) : minidxtree_base([&]{
            vector<seg_idx_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {v[i], i};
            return init;
        }()) {}
        void set(int p, int64_t x) { minidxtree_base::set(p, {x, p}); }
        int64_t get(int p) { return minidxtree_base::get(p).val; }
    };
    //indexが取れる区間最大
    using maxidxtree_base = segtree<seg_idx_s, max_idx_op, max_idx_e>;
    struct maxidxtree : maxidxtree_base {
        maxidxtree (int n) : maxidxtree_base(n) {}
        maxidxtree (const vector<int64_t> &v) : maxidxtree_base([&]{
            vector<seg_idx_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {v[i], i};
            return init;
        }()) {}
        void set(int p, int64_t x) { maxidxtree_base::set(p, {x, p}); }
        int64_t get(int p) { return maxidxtree_base::get(p).val; }
    };
    //indexが取れる区間最小＆最大
    using minmaxidxtree_base = segtree<seg_min_max_idx_s, min_max_idx_op, min_max_idx_e>;
    struct minmaxidxtree : minmaxidxtree_base {
        minmaxidxtree (int n) : minmaxidxtree_base(n) {}
        minmaxidxtree (const vector<int64_t> &v) : minmaxidxtree_base([&]{
            vector<seg_min_max_idx_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {{v[i], i}, {v[i], i}};
            return init;
        }()) {}
        void set(int p, int64_t x) { minmaxidxtree_base::set(p, {{x, p}, {x, p}}); }
        int64_t get(int p) { return minmaxidxtree_base::get(p).min.val; }
    };


    //*シンプルな遅延セグ木
    //区間加算・区間最小
    using addmintree = lazy_segtree<int64_t, min_op, min_e, int64_t, add_map, add_com, zero_id>;
    //区間更新・区間最小
    using updmintree = lazy_segtree<int64_t, min_op, min_e, int64_t, upd_map, upd_com, upd_id>;
    //区間加算・区間最大
    using addmaxtree = lazy_segtree<int64_t, max_op, max_e, int64_t, add_map, add_com, zero_id>;
    //区間更新・区間最大
    using updmaxtree = lazy_segtree<int64_t, max_op, max_e, int64_t, upd_map, upd_com, upd_id>;
    //区間加算・区間和
    using addsumtree_base = lazy_segtree<seg_siz_s, sum_siz_op, zero_siz_e, int64_t, add_siz_map, add_com, zero_id>;
    struct addsumtree : addsumtree_base {
        addsumtree (int n) : addsumtree_base(vector<seg_siz_s>(n, {0, 1})) {}
        addsumtree (const vector<int64_t> &v) : addsumtree_base([&]{
            vector<seg_siz_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {v[i], 1};
            return init;
        }()) {}
        int64_t prod(int l, int r) { return addsumtree_base::prod(l, r).val; }
        int64_t all_prod() { return addsumtree_base::all_prod().val; }
        int64_t get(int p) { return addsumtree_base::get(p).val; }
        void set(int p, int64_t x) { addsumtree_base::set(p, {x, 1}); }
    };
    //区間更新・区間和
    using updsumtree_base = lazy_segtree<seg_siz_s, sum_siz_op, zero_siz_e, int64_t, upd_siz_map, upd_com, upd_id>;
    struct updsumtree : updsumtree_base {
        updsumtree (int n) : updsumtree_base(vector<seg_siz_s>(n, {0, 1})) {}
        updsumtree (const vector<int64_t> &v) : updsumtree_base([&]{
            vector<seg_siz_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {v[i], 1};
            return init;
        }()) {}
        int64_t prod(int l, int r) { return updsumtree_base::prod(l, r).val; }
        int64_t all_prod() { return updsumtree_base::all_prod().val; }
        int64_t get(int p) { return updsumtree_base::get(p).val; }
        void set(int p, int64_t x) { updsumtree_base::set(p, {x, 1}); }
    };
    //区間ax+b・区間和
    using affsumtree_base = lazy_segtree<seg_siz_s, sum_siz_op, zero_siz_e, seg_aff_f, aff_siz_map, aff_com, aff_id>;
    struct affsumtree : affsumtree_base {
        affsumtree (int n) : affsumtree_base(vector<seg_siz_s>(n, {0, 1})) {}
        affsumtree (const vector<int64_t> &v) : affsumtree_base([&]{
            vector<seg_siz_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {v[i], 1};
            return init;
        }()) {}
        int64_t prod(int l, int r) { return affsumtree_base::prod(l, r).val; }
        int64_t all_prod() { return affsumtree_base::all_prod().val; }
        int64_t get(int p) { return affsumtree_base::get(p).val; }
        void set(int p, int64_t x) { affsumtree_base::set(p, {x, 1}); }
    };
    //区間加算・mod区間和
    using addsummodtree_base = lazy_segtree<seg_siz_s, sum_siz_mod_op, zero_siz_e, int64_t, add_siz_mod_map, add_com, zero_id>;
    struct addsummodtree : addsummodtree_base {
        addsummodtree (int n) : addsummodtree_base(vector<seg_siz_s>(n, {0, 1})) {}
        addsummodtree (const vector<int64_t> &v) : addsummodtree_base([&]{
            vector<seg_siz_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {(v[i] % seg_mod + seg_mod) % seg_mod, 1};
            return init;
        }()) {}
        int64_t prod(int l, int r) { return addsummodtree_base::prod(l, r).val; }
        int64_t all_prod() { return addsummodtree_base::all_prod().val; }
        int64_t get(int p) { return addsummodtree_base::get(p).val; }
        void set(int p, int64_t x) { addsummodtree_base::set(p, {(x % seg_mod + seg_mod) % seg_mod, 1}); }
        void apply(int l, int r, int64_t f) { addsummodtree_base::apply(l, r, (f % seg_mod + seg_mod) % seg_mod); }
    };
    //区間更新・mod区間和
    using updsummodtree_base = lazy_segtree<seg_siz_s, sum_siz_mod_op, zero_siz_e, int64_t, upd_siz_mod_map, upd_com, upd_id>;
    struct updsummodtree : updsummodtree_base {
        updsummodtree (int n) : updsummodtree_base(vector<seg_siz_s>(n, {0, 1})) {}
        updsummodtree (const vector<int64_t> &v) : updsummodtree_base([&]{
            vector<seg_siz_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {(v[i] % seg_mod + seg_mod) % seg_mod, 1};
            return init;
        }()) {}
        int64_t prod(int l, int r) { return updsummodtree_base::prod(l, r).val; }
        int64_t all_prod() { return updsummodtree_base::all_prod().val; }
        int64_t get(int p) { return updsummodtree_base::get(p).val; }
        void set(int p, int64_t x) { updsummodtree_base::set(p, {(x % seg_mod + seg_mod) % seg_mod, 1}); }
        void apply(int l, int r, int64_t f) { updsummodtree_base::apply(l, r, (f % seg_mod + seg_mod) % seg_mod); }
    };
    //区間ax+b・mod区間和
    using affsummodtree_base = lazy_segtree<seg_siz_s, sum_siz_mod_op, zero_siz_e, seg_aff_f, aff_siz_mod_map, aff_mod_com, aff_id>;
    struct affsummodtree : affsummodtree_base {
        affsummodtree (int n) : affsummodtree_base(vector<seg_siz_s>(n, {0, 1})) {}
        affsummodtree (const vector<int64_t> &v) : affsummodtree_base([&]{
            vector<seg_siz_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {(v[i] % seg_mod + seg_mod) % seg_mod, 1};
            return init;
        }()) {}
        int64_t prod(int l, int r) { return affsummodtree_base::prod(l, r).val; }
        int64_t all_prod() { return affsummodtree_base::all_prod().val; }
        int64_t get(int p) { return affsummodtree_base::get(p).val; }
        void set(int p, int64_t x) { affsummodtree_base::set(p, {(x % seg_mod + seg_mod) % seg_mod, 1}); }
        void apply(int l, int r, seg_aff_f f)
            { affsummodtree_base::apply(l, r, {(f.a % seg_mod + seg_mod) % seg_mod, (f.b % seg_mod + seg_mod) % seg_mod}); }
    };
    //区間加算・二乗和
    using addsqtree_base = lazy_segtree<seg_sq_s, sq_op, sq_e, int64_t, add_sq_map, add_com, zero_id>;
    struct addsqtree : addsqtree_base {
        addsqtree(int n) : addsqtree_base(vector<seg_sq_s>(n, {0, 0, 1})) {}
        addsqtree(const vector<int64_t> &v) : addsqtree_base([&]{
            vector<seg_sq_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {v[i], v[i] * v[i], 1};
            return init;
        }()) {}
        int64_t prod(int l, int r) { return addsqtree_base::prod(l, r).sq; }
        int64_t all_prod() { return addsqtree_base::all_prod().sq; }
        int64_t get(int p) { return addsqtree_base::get(p).sum; }
        void set(int p , int64_t x) {addsqtree_base::set(p, {x, x * x, 1}); }
    };
    //区間更新・二乗和
    using updsqtree_base = lazy_segtree<seg_sq_s, sq_op, sq_e, int64_t, upd_sq_map, upd_com, upd_id>;
    struct updsqtree : updsqtree_base {
        updsqtree(int n) : updsqtree_base(vector<seg_sq_s>(n, {0, 0, 1})) {}
        updsqtree(const vector<int64_t> &v) : updsqtree_base([&]{
            vector<seg_sq_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {v[i], v[i] * v[i], 1};
            return init;
        }()) {}
        int64_t prod(int l, int r) { return updsqtree_base::prod(l, r).sq; }
        int64_t all_prod() { return updsqtree_base::all_prod().sq; }
        int64_t get(int p) { return updsqtree_base::get(p).sum; }
        void set(int p , int64_t x) {updsqtree_base::set(p, {x, x * x, 1}); }
    };
    //区間ax+b・二乗和
    using affsqtree_base = lazy_segtree<seg_sq_s, sq_op, sq_e, seg_aff_f, aff_sq_map, aff_com, aff_id>;
    struct affsqtree : affsqtree_base {
        affsqtree(int n) : affsqtree_base(vector<seg_sq_s>(n, {0, 0, 1})) {}
        affsqtree(const vector<int64_t> &v) : affsqtree_base([&]{
            vector<seg_sq_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {v[i], v[i] * v[i], 1};
            return init;
        }()) {}
        int64_t prod(int l, int r) { return affsqtree_base::prod(l, r).sq; }
        int64_t all_prod() { return affsqtree_base::all_prod().sq; }
        int64_t get(int p) { return affsqtree_base::get(p).sum; }
        void set(int p , int64_t x) {affsqtree_base::set(p, {x, x * x, 1}); }
    };


    //*シンプルでない遅延セグ木
    //区間ax+b・区間最小＆最大
    using affminmaxtree_base = lazy_segtree<seg_min_max_s, min_max_op, min_max_e, seg_aff_f, aff_min_max_map, aff_com, aff_id>;
    struct affminmaxtree : affminmaxtree_base {
        affminmaxtree (int n) : affminmaxtree_base(n) {}
        affminmaxtree (const vector<int64_t> &v) : affminmaxtree_base([&]{
            vector<seg_min_max_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {v[i], v[i]};
            return init;
        }()) {}
        int64_t get(int p) { return affminmaxtree_base::get(p).min; }
        void set(int p, int64_t x) { affminmaxtree_base::set(p, {x, x}); }
    };
    //区間更新＆加算＆乗算＆ax+b・indexが取れる区間最小＆最大＆総和
    using alltree_base = lazy_segtree<seg_all_s, all_op, all_e, seg_aff_f, all_map, aff_com, aff_id>;
    struct alltree : alltree_base {
        alltree (int n) : alltree_base([&]{
            vector<seg_all_s> init(n);
            for (int i = 0; i < n; i++) init[i] = {{0, i}, {0, i}, 0, 1, i};
            return init;
        }()) {}
        alltree (const vector<int64_t> &v) : alltree_base([&]{
            vector<seg_all_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {{v[i], i}, {v[i], i}, v[i], 1, i};
            return init;
        }()) {}
        void set(int p, int64_t x) { alltree_base::set(p, {{x, p}, {x, p}, x, 1, p}); }
        int64_t get(int p) { return alltree_base::get(p).sum; }
        void upd(int l, int r, int64_t x) { alltree_base::apply(l, r, {0, x}); }
        void add(int l, int r, int64_t x) { alltree_base::apply(l, r, {1, x}); }
        void mul(int l, int r, int64_t x) { alltree_base::apply(l, r, {x, 0}); }
    };


    //*＠フリーセグ木
    //区間和の例
    //型
    //?ここで値の型を指定
    using seg_s = int64_t;

    //二項演算
    constexpr seg_s seg_op(seg_s a, seg_s b) {
        //?ここで演算方法を指定
        return a + b;
    }

    //単位元
    constexpr seg_s seg_e() {
        //?操作を行っても変わらない値
        return 0;
    }

    using mysegtree = segtree<seg_s, seg_op, seg_e>;


    //*＠フリー遅延セグ木
    //区間加算区間和の例
    //型
    //?ここで値の型を指定
    struct leg_s {
        int64_t val;
        int siz;
    };

    //二項演算
    constexpr leg_s leg_op(leg_s a, leg_s b) {
        //?ここで演算方法を指定
        return {a.val + b.val, a.siz + b.siz};
    }

    //単位元
    constexpr leg_s leg_e() {
        //?操作を行っても変わらない値
        return {0, 0};
    }

    //写像の型
    //?どういう更新を行うか
    using leg_f = int64_t;

    //mapping
    constexpr leg_s leg_map(leg_f f, leg_s x) {
        //?更新方法
        return {x.val + f * x.siz, x.siz};
    }

    //composition
    constexpr leg_f leg_com(leg_f f, leg_f g) {
        //?gに対しfで更新する
        return g + f;
    }

    //id
    constexpr leg_f leg_id() {
        //?更新の単位元
        return 0;
    }

    using mylazysegtree = lazy_segtree<leg_s, leg_op, leg_e, leg_f, leg_map, leg_com, leg_id>;
#endif



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

//中国剰余の定理 解無しは{0, 0}
pair<int64_t, int64_t> CRT(const vector<int64_t> &b, const vector<int64_t> &m) {
    int64_t r = 0, M = 1;
    for (int64_t i = 0; i < (int64_t)b.size(); i++) {
        int64_t p, q;
        int64_t d = extendedGCD(M, m[i], p, q);
        if (((__int128_t)b[i] - r) % d != 0) return {0, 0};
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



//!データ構造
//*スパーステーブル
template <typename T, typename op>
struct SparseTable {
    int N, K;
    vector<int> log_table;
    vector<vector<T>> table;
    op f;
    SparseTable(const vector<T> &A, op f) : f(f) {
        N = A.size();
        K = 0;
        while ((1LL << (K + 1)) <= N) K++;
        table.resize(K + 1);
        table[0] = A;
        for (int k = 0; k < K; k++) {
            int m = N - (1LL << (k + 1)) + 1;
            table[k + 1].resize(m);
            for (int i = 0; i < m; i++) {
                table[k + 1][i] =f(table[k][i], table[k][i + (1LL << k)]);
            }
        }
        log_table.resize(N + 1);
        for (int k = 0; k <= K; k++) {
            int s = (1LL << k), t =min((1LL << (k + 1)) - 1, (long long)N);
            for (int i = s; i <= t; i++) {
                log_table[i] = k;
            }
        }
    }
    T query(int L, int R) const {
        assert(0 <= L && L < R && R <= N);
        int k = log_table[R - L];
        return f(table[k][L], table[k][R - (1LL << k)]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
