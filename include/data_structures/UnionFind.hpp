#pragma once
#include "../base.hpp"

/// @brief Union-Find
/// @see https://judge.yosupo.jp/submission/411591
struct UnionFind {
    vector<int> L;

    /// @brief n 個の要素で初期化
    /// @param n 要素数
    /// @note O(N)
    UnionFind(int n) : L(n, -1) {}

    /// @brief 頂点の根を返す
    /// @param u 頂点のインデックス
    /// @return 根のインデックス
    /// @note 償却 O(α(N))
    int leader(int u) {
        if (L[u] < 0) return u;
        return L[u] = leader(L[u]);
    }

    /// @brief 2頂点をマージする
    /// @param u 頂点1のインデックス
    /// @param v 頂点2のインデックス
    /// @return マージした場合 true
    /// @note 償却 O(α(N))
    bool merge(int u, int v) {
        u = leader(u);
        v = leader(v);
        if (u == v) return false;
        if (L[u] > L[v]) swap(u, v);
        L[u] += L[v];
        L[v] = u;
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