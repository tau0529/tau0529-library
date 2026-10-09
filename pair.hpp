#pragma once
#include "prototype.hpp"

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