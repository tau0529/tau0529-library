#pragma once
#include "../base.hpp"

/// @brief 重み付きUnion-Find
/// @tparam T 重みの型
/// @see https://judge.yosupo.jp/submission/411086
template <typename T = int64_t>
struct WeightedUnionFind {
    vector<int> L;
    vector<T> W;

    /// @brief n 個の要素で初期化
    /// @param n 要素数
    /// @note O(N)
    WeightedUnionFind(int n) : L(n, -1), W(n, 0) {}

    /// @brief 頂点の根を返す
    /// @param u 頂点のインデックス
    /// @return 根のインデックス
    /// @note 償却 O(α(N))
    int leader(int u) {
        if (L[u] < 0) return u;
        int p = L[u];
        L[u] = leader(p);
        W[u] += W[p];
        return L[u];
    }

    /// @brief 頂点の根からの重みの差を返す
    /// @param u 頂点のインデックス
    /// @return 根の重みを0とした時の頂点 u の相対的な重み
    /// @note 償却 O(α(N))
    T potential(int u) {
        leader(u);
        return W[u];
    }

    /// @brief 2頂点を重み w でマージする
    /// @param u 頂点1のインデックス
    /// @param v 頂点2のインデックス
    /// @param w (v の重み) - (u の重み)
    /// @return 矛盾しなかった場合 true
    /// @note 償却 O(α(N))
    bool merge(int u, int v, T w) {
        w += potential(u) - potential(v);
        u = leader(u);
        v = leader(v);
        if (u == v) return w == 0;
        if (L[u] > L[v]) {
            swap(u, v);
            w = -w;
        }
        L[u] += L[v];
        L[v] = u;
        W[v] = w;
        return true;
    }

    /// @brief 2頂点が同じ集合に属するか判定
    /// @param u 頂点1のインデックス
    /// @param v 頂点2のインデックス
    /// @return 同じ集合なら true
    /// @note 償却 O(α(N))
    bool same(int u, int v) {
        return leader(u) == leader(v);
    }

    /// @brief 頂点 u の含まれる集合の要素数
    /// @param u 頂点のインデックス
    /// @return 頂点の含まれる集合の要素数
    /// @note 償却 O(α(N))
    int size(int u) {
        return -L[leader(u)];
    }

    /// @brief 2頂点の重みの差
    /// @param u 頂点1のインデックス
    /// @param v 頂点2のインデックス
    /// @return (v の重み) - (u の重み)
    /// @pre 2頂点が同じ集合であること
    /// @note 償却 O(α(N))
    T diff(int u, int v) {
        assert(same(u, v));
        return potential(v) - potential(u);
    }

    /// @brief 連結成分に分けた情報を返す
    /// @return 連結成分に分けた情報を返す
    /// @note O(Nα(N))
    vector<vector<int>> groups() {
        vector<vector<int>> res(L.size());
        for (int u = 0; u < (int)L.size(); u++) {
            res[leader(u)].push_back(u);
        }
        vector<vector<int>> ans;
        for (auto &v : res) {
            if (!v.empty()) ans.push_back(v);
        }
        return ans;
    }
};