#pragma once
#include "../base.hpp"

/// @brief SparseTable
/// @tparam T 型
/// @tparam op 二項演算
/// @pre 結合律を満たして、べき等であること
/// @see https://judge.yosupo.jp/submission/412288
template <typename T, typename op>
struct SparseTable {
    int n;
    vector<int> log_table;
    vector<vector<T>> table;
    op f;

    /// @brief 配列 v で初期化
    /// @param v 配列
    /// @param f 二項演算
    /// @note O(NlogN)
    SparseTable(const vector<T> &v, op f) : n(v.size()), f(f) {
        log_table.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            log_table[i] = log_table[i >> 1] + 1;
        }
        int k = n ? log_table[n] + 1 : 0;
        table.resize(k);
        if (!n) return;
        table[0] = v;
        for (int j = 0; j < k - 1; j++) {
            int len = 1 << (j + 1);
            int m = n - len + 1;
            table[j + 1].resize(m);
            for (int i = 0; i < m; i++) {
                table[j + 1][i] = f(table[j][i], table[j][i + (len >> 1)]);
            }
        }
    }

    /// @brief [l, r) 区間の値を返す
    /// @param l 左端
    /// @param r 右端
    /// @return 区間の演算結果
    /// @note O(1)
    T prod(int l, int r) const {
        assert(0 <= l && l < r && r <= n);
        int k = log_table[r - l];
        return f(table[k][l], table[k][r - (1LL << k)]);
    }
};