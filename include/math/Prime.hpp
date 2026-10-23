#pragma once
#include "../base.hpp"

//ミラーラビンの素数判定(int128式)
//https://judge.yosupo.jp/submission/412833

/// @brief ミラーラビンの素数判定
/// @return 素数なら true
/// @note O(log n)
/// @see https://judge.yosupo.jp/submission/412833
/// @see https://drken1215.hatenablog.com/entry/2023/05/23/233000
bool is_prime(int64_t n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    int64_t d = n - 1;
    int s = 0;
    while (!(d & 1)) {
        d >>= 1;
        ++s;
    }
    const int64_t *A;
    static constexpr int64_t A1[] = {2, 7, 61};
    static constexpr int64_t A2[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    int k;
    if (n < 4759123141LL) A = A1, k = 3;
    else A = A2, k = 7;
    for (int i = 0; i < k; i++) {
        int64_t a = A[i];
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

/// @brief エラトステネスの篩
/// @return n 以下の値が素数であるか
/// @pre n >= 0
/// @note O(n log log n)
vector<bool> eratosthenes(int64_t n) {
    vector<bool> res(n + 1, true);
    res[0] = false;
    if (n >= 1) res[1] = false;
    for (int64_t i = 4; i <= n; i += 2) res[i] = false;
    for (int64_t i = 3; i <= n / i; i += 2) {
        if (!res[i]) continue;
        for (int64_t j = i * i; j <= n; j += i * 2) res[j] = false;
    }
    return res;
}

/// @brief 素数リスト
/// @return n 以下の素数一覧
/// @pre n >= 0
/// @note O(n log log n)
vector<int64_t> prime_list(int64_t n) {
    vector<bool> P = eratosthenes(n);
    vector<int64_t> res;
    if (n >= 2) res.push_back(2);
    for (int64_t i = 3; i <= n; i += 2) {
        if (P[i]) res.push_back(i);
    }
    return res;
}