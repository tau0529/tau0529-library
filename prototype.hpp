#pragma once
#include "base.hpp"

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