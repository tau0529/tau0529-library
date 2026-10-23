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
        n = max(2, n);
        mod = m;
        assert(2 <= mod && mod < INT_MAX && 0 <= n && n < mod);
        inv_.assign(n + 1, 1);
        fact_.assign(n + 1, 1);
        ifact_.assign(n + 1, 1);
        for (int64_t i = 2; i <= n; i++) {
            inv_[i] = mod - (mod / i) * inv_[mod % i] % mod;
            fact_[i] = fact_[i - 1] * i % mod;
            ifact_[i] = ifact_[i - 1] * inv_[i] % mod;
        }
    }

    /// @brief 事前計算範囲の拡張
    /// @param n 事前計算する最大値
    /// @pre n < mod
    /// @note 拡張時 O(n - 現在の最大値) 非拡張時 O(1)
    void extend(int n) {
        assert(0 <= n && n < mod);
        n = max(2, n);
        int old = fact_.size();
        if (n < old) return;
        inv_.resize(n + 1);
        fact_.resize(n + 1);
        ifact_.resize(n + 1);
        for (int64_t i = old; i <= n; i++) {
            inv_[i] = mod - (mod / i) * inv_[mod % i] % mod;
            fact_[i] = fact_[i - 1] * i % mod;
            ifact_[i] = ifact_[i - 1] * inv_[i] % mod;
        }
    }

    /// @brief 逆元
    /// @pre n >= 1
    /// @note O(1)（非拡張時）
    int64_t inv(int n) {
        assert(n >= 1);
        extend(n);
        return inv_[n];
    }

    /// @brief 階乗
    /// @pre n >= 0
    /// @note O(1)（非拡張時）
    int64_t fact(int n) {
        assert(n >= 0);
        extend(n);
        return fact_[n];
    }

    /// @brief 階乗の逆元
    /// @pre n >= 0
    /// @note O(1)（非拡張時）
    int64_t ifact(int n) {
        assert(n >= 0);
        extend(n);
        return ifact_[n];
    }

    /// @brief nPr
    /// @pre n >= 0
    /// @note O(1)（非拡張時）
    int64_t nPr(int n, int r) {
        assert(n >= 0);
        if (r < 0 || n < r) return 0;
        extend(n);
        return fact_[n] * ifact_[n - r] % mod;
    }

    /// @brief nCr
    /// @pre n >= 0
    /// @note O(1)（非拡張時）
    int64_t nCr(int n, int r) {
        assert(n >= 0);
        if (r < 0 || n < r) return 0;
        extend(n);
        return fact_[n] * ifact_[r] % mod * ifact_[n - r] % mod;
    }

    /// @brief nHr
    /// @pre n >= 0, r >= 0
    /// @note O(1)（非拡張時）
    int64_t nHr(int n, int r) {
        assert(n >= 0 && r >= 0);
        if (n == 0) return r == 0;
        return nCr(n + r - 1, r);
    }

    /// @brief 多項係数
    /// @param v 各項の個数
    /// @pre すべての項は0以上であること
    /// @note O(v.size()) (非拡張時)
    template <typename T>
    int64_t multinomial(const vector<T> &v) {
        int64_t n = 0;
        for (auto x : v) {
            assert(x >= 0);
            n += x;
        }
        extend(n);
        int64_t res = fact_[n];
        for (auto x : v) res = res * ifact_[x] % mod;
        return res;
    }
};