#pragma once
#include "../base.hpp"

/// @brief a の b 乗
/// @pre b >= 0
/// @note O(log b)
int64_t power(int64_t a, int64_t b) {
    assert(b >= 0);
    int64_t res = 1;
    while (b > 0) {
        if (b & 1) res *= a;
        b >>= 1;
        if (b) a *= a;
    }
    return res;
}

/// @brief 階乗
/// @pre n >= 0
/// @note O(n)
int64_t factorial(int64_t n) {
    assert(n >= 0);
    int64_t res = 1;
    for (int64_t i = 2; i <= n; i++) res *= i;
    return res;
}

/// @brief 愚直なnPr
/// @pre n >= 0, r >= 0;
/// @note O(r)
int64_t nPr(int64_t n, int64_t r) {
    if (r < 0 || n < r) return 0;
    int64_t res = 1;
    for (int64_t i = 0; i < r; i++) res *= n - i;
    return res;
}

/// @brief 愚直なnCr
/// @note O(min(r, n - r))
int64_t nCr(int64_t n, int64_t r) {
    if (r < 0 || n < r) return 0;
    r = min(r, n - r);
    int64_t res = 1;
    for (int64_t i = 0; i < r; i++) res = res * (n - i) / (i + 1);
    return res;
}

/// @brief mod上の a の b 乗
/// @pre b >= 0, mod > 0
/// @note O(log b)
int64_t power(int64_t a, int64_t b, int64_t mod) {
    assert(b >= 0 && mod > 0);
    int64_t res = 1 % mod;
    a %= mod;
    if (a < 0) a += mod;
    if (mod < INT_MAX) {
        while (b > 0) {
            if (b & 1) res = res * a % mod;
            b >>= 1;
            if (b) a = a * a % mod;
        }
    }
    else {
        while (b > 0) {
            if (b & 1) res = (__int128_t)res * a % mod;
            b >>= 1;
            if (b) a = (__int128_t)a * a % mod;
        }
    }
    return res;
}

/// @brief mod上の階乗
/// @pre n >= 0, mod > 0
/// @note O(n)
int64_t factorial(int64_t n, int64_t mod) {
    assert(n >= 0 && mod > 0);
    if (n >= mod) return 0;
    int64_t res = 1 % mod;
    if (mod < INT_MAX) {
        for (int64_t i = 2; i <= n; i++) {
            res = res * i % mod;
        }
    }
    else {
        for (int64_t i = 2; i <= n; i++) {
            res = (__int128_t)res * i % mod;
        }
    }
    return res;
}

/// @brief mod上の愚直なnPr
/// @pre n >= 0, mod > 0
/// @note O(r)
int64_t nPr(int64_t n, int64_t r, int64_t mod) {
    assert(mod > 0);
    if (r < 0 || n < r) return 0;
    int64_t res = 1 % mod;
    if (res == 0 || r >= mod) return 0;
    if (mod < INT_MAX) {
        if (n < INT_MAX) {
            for (int64_t i = 0; i < r; i++) {
                res = res * (n - i) % mod;
            }
        }
        else {
            for (int64_t i = 0; i < r; i++) {
                res = res * ((n - i) % mod) % mod;
            }
        }
    }
    else {
        for (int64_t i = 0; i < r; i++) {
            res = (__int128_t)res * (n - i) % mod;
        }
    }
    return res;
}

/// @brief mod上の愚直なnCr
/// @pre mod は素数
/// @pre r < mod
/// @note O(min(r, n - r) + log mod)
int64_t nCr(int64_t n, int64_t r, int64_t mod) {
    if (r < 0 || n < r) return 0;
    assert(mod >= 2);
    r = min(r, n - r);
    assert(r < mod);
    int64_t a = 1 % mod, b = 1;
    if (mod < INT_MAX) {
        if (n < INT_MAX) {
            for (int64_t i = 0; i < r; i++) {
                a = a * (n - i) % mod;
                b = b * (i + 1) % mod;
            }
        }
        else {
            for (int64_t i = 0; i < r; i++) {
                a = a * ((n - i) % mod) % mod;
                b = b * (i + 1) % mod;
            }
        }
        if (a == 0) return 0;
        return a * power(b, mod - 2, mod) % mod;
    }
    for (int64_t i = 0; i < r; i++) {
        a = (__int128_t)a * (n - i) % mod;
        b = (__int128_t)b * (i + 1) % mod;
    }
    if (a == 0) return 0;
    return (__int128_t)a * power(b, mod - 2, mod) % mod;
}

/// @brief 10進数の右から k 桁目を返す
/// @pre x >= 0, k >= 0
/// @note O(k)
int64_t digit(int64_t x, int k) {
    assert(x >= 0 && k >= 0);
    while (k--) x /= 10;
    return x % 10;
}