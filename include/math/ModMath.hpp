#pragma once
#include "../base.hpp"

/// @brief mod上の計算
/// @pre modは素数
struct ModMath {
    int64_t mod;
    vector<int64_t> inv_, fact_, ifact_;

    /// @brief 初期化
    /// @param n 事前計算する最大値
    /// @param m 法
    /// @pre 0 <= n < m
    /// @pre m は素数
    /// @note O(n)
    ModMath(int n = 0, int64_t m = 998244353) {
        init(n, m);
    }

    /// @brief 初期化
    /// @param n 事前計算する最大値
    /// @param m 法
    /// @pre 0 <= n < m
    /// @pre m は素数
    /// @note O(n)
    void init(int n, int64_t m = 998244353) {
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

    /// @brief 逆元
    /// @pre 1 <= n <= 事前計算した最大値
    /// @note O(1)
    int64_t inv(int n) const {
        assert(1 <= n && n < (int)inv_.size());
        return inv_[n];
    }

    /// @brief 階乗
    /// @pre 0 <= n <= 事前計算した最大値
    /// @note O(1)
    int64_t fact(int n) const {
        assert(0 <= n && n < (int)fact_.size());
        return fact_[n];
    }

    /// @brief 階乗の逆元
    /// @pre 0 <= n <= 事前計算した最大値
    /// @note O(1)
    int64_t ifact(int n) const {
        assert(0 <= n && n < (int)ifact_.size());
        return ifact_[n];
    }

    /// @brief nPr
    /// @pre 0 <= n <= 事前計算した最大値
    /// @note O(1)
    int64_t nPr(int n, int r) const {
        assert(0 <= n && n < (int)fact_.size());
        if (r < 0 || n < r) return 0;
        return fact_[n] * ifact_[n - r] % mod;
    }

    /// @brief nCr
    /// @pre 0 <= n <= 事前計算した最大値
    /// @note O(1)
    int64_t nCr(int n, int r) const {
        assert(0 <= n && n < (int)fact_.size());
        if (r < 0 || n < r) return 0;
        return fact_[n] * ifact_[r] % mod * ifact_[n - r] % mod;
    }
};