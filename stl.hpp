#pragma once
#include "prototype.hpp"

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