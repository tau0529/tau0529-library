#pragma once
#include "base.hpp"

//!演算
//*プロトタイプ宣言
//vector
template <typename T> inline constexpr bool is_vector = false;
template <typename T> inline constexpr bool is_vector<vector<T>> = true;
template <typename T1, typename T2> requires (!is_vector<T2>) vector<T1> operator+(const vector<T1> &v, const T2 &a);
template <typename T1, typename T2> requires (!is_vector<T2>) vector<T1> operator-(const vector<T1> &v, const T2 &a);
template <typename T1, typename T2> requires (!is_vector<T2>) vector<T1> operator*(const vector<T1> &v, const T2 &a);
template <typename T1, typename T2> requires (!is_vector<T2>) vector<T1> operator/(const vector<T1> &v, const T2 &a);
template <typename T1, typename T2> requires (!is_vector<T2>) vector<T1> operator%(const vector<T1> &v, const T2 &a);
template <typename T1, typename T2> requires (!is_vector<T1>) vector<T2> operator+(const T1 &a, const vector<T2> &v);
template <typename T1, typename T2> requires (!is_vector<T1>) vector<T2> operator-(const T1 &a, const vector<T2> &v);
template <typename T1, typename T2> requires (!is_vector<T1>) vector<T2> operator*(const T1 &a, const vector<T2> &v);
template <typename T1, typename T2> requires (!is_vector<T1>) vector<T2> operator/(const T1 &a, const vector<T2> &v);
template <typename T1, typename T2> requires (!is_vector<T1>) vector<T2> operator%(const T1 &a, const vector<T2> &v);
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

//pair
template <typename T> inline constexpr bool is_pair = false;
template <typename T1, typename T2> inline constexpr bool is_pair<pair<T1, T2>> = true;
template <typename T1, typename T2, typename T3> requires (!is_pair<T3>) pair<T1, T2> operator+(const pair<T1, T2> &p, const T3 &a);
template <typename T1, typename T2, typename T3> requires (!is_pair<T3>) pair<T1, T2> operator-(const pair<T1, T2> &p, const T3 &a);
template <typename T1, typename T2, typename T3> requires (!is_pair<T3>) pair<T1, T2> operator*(const pair<T1, T2> &p, const T3 &a);
template <typename T1, typename T2, typename T3> requires (!is_pair<T3>) pair<T1, T2> operator/(const pair<T1, T2> &p, const T3 &a);
template <typename T1, typename T2, typename T3> requires (!is_pair<T3>) pair<T1, T2> operator%(const pair<T1, T2> &p, const T3 &a);
template <typename T1, typename T2, typename T3> requires (!is_pair<T1>) pair<T2, T3> operator+(const T1 &a, const pair<T2, T3> &p);
template <typename T1, typename T2, typename T3> requires (!is_pair<T1>) pair<T2, T3> operator-(const T1 &a, const pair<T2, T3> &p);
template <typename T1, typename T2, typename T3> requires (!is_pair<T1>) pair<T2, T3> operator*(const T1 &a, const pair<T2, T3> &p);
template <typename T1, typename T2, typename T3> requires (!is_pair<T1>) pair<T2, T3> operator/(const T1 &a, const pair<T2, T3> &p);
template <typename T1, typename T2, typename T3> requires (!is_pair<T1>) pair<T2, T3> operator%(const T1 &a, const pair<T2, T3> &p);
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
requires (!is_vector<T1>)
vector<T2> operator+(const T1 &a, const vector<T2> &v) {
    return v + a;
}
template <typename T1, typename T2>
requires (!is_vector<T1>)
vector<T2> operator-(const T1 &a, const vector<T2> &v) {
    vector<T2> res = v;
    for (auto &x : res) x = a - x;
    return res;
}
template <typename T1, typename T2>
requires (!is_vector<T1>)
vector<T2> operator*(const T1 &a, const vector<T2> &v) {
    return v * a;
}
template <typename T1, typename T2>
requires (!is_vector<T1>)
vector<T2> operator/(const T1 &a, const vector<T2> &v) {
    vector<T2> res = v;
    for (auto &x : res) x = a / x;
    return res;
}
template <typename T1, typename T2>
requires (!is_vector<T1>)
vector<T2> operator%(const T1 &a, const vector<T2> &v) {
    vector<T2> res = v;
    for (auto &x : res) x = a % x;
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
requires (!is_pair<T1>)
pair<T2, T3> operator+(const T1 &a, const pair<T2, T3> &p) {
    return p + a;
}
template <typename T1, typename T2, typename T3>
requires (!is_pair<T1>)
pair<T2, T3> operator-(const T1 &a, const pair<T2, T3> &p) {
    pair<T2, T3> res = p;
    res.first = a - res.first;
    res.second = a - res.second;
    return res;
}
template <typename T1, typename T2, typename T3>
requires (!is_pair<T1>)
pair<T2, T3> operator*(const T1 &a, const pair<T2, T3> &p) {
    return p * a;
}
template <typename T1, typename T2, typename T3>
requires (!is_pair<T1>)
pair<T2, T3> operator/(const T1 &a, const pair<T2, T3> &p) {
    pair<T2, T3> res = p;
    res.first = a / res.first;
    res.second = a / res.second;
    return res;
}
template <typename T1, typename T2, typename T3>
requires (!is_pair<T1>)
pair<T2, T3> operator%(const T1 &a, const pair<T2, T3> &p) {
    pair<T2, T3> res = p;
    res.first = a % res.first;
    res.second = a % res.second;
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