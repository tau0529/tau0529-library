#pragma once
#include "base.hpp"

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