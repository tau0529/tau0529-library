#pragma once
#include "../base.hpp"

/// @brief SegmentTree
/// @tparam S 型
/// @tparam op 二項演算
/// @tparam e 単位元
/// @tparam Commutative 可換なら true
/// @note 配列長さ2N
/// @see https://judge.yosupo.jp/submission/411772
/// @see https://hackmd.io/@tatyam-prime/rkA5wJMdo
template <typename S, auto op, auto e, bool Commutative = false>
struct SegmentTree {
    int n;
    vector<S> seg;

    /// @brief n 個の要素で初期化
    /// @param n 要素数
    /// @note O(N)
    SegmentTree(int n) : n(n), seg(n << 1, e()) {}

    /// @brief 配列 v で初期化
    /// @param v 配列
    /// @note O(N)
    SegmentTree (const vector<S> &v) : n(v.size()), seg(n * 2) {
        copy(v.begin(), v.end(), seg.begin() + n);
        for (int i = n - 1; i > 0; i--) {
            seg[i] = op(seg[i << 1], seg[i << 1 | 1]);
        }
    }

    /// @brief i 番目に x を代入
    /// @param i インデックス
    /// @param x 値
    /// @note O(logN)
    void set(int i, S x) {
        i += n;
        seg[i] = x;
        while (i >>= 1) seg[i] = op(seg[i << 1], seg[i << 1 | 1]);
    }

    /// @brief i 番目の値を取得します
    /// @param i インデックス
    /// @return 値
    /// @note O(1)
    S get(int i) const {
        return seg[i + n];
    }

    /// @brief i 番目の値を取得します
    /// @param i インデックス
    /// @return 値
    /// @note O(1)
    S operator[](int i) const {
        return seg[i + n];
    }

    /// @brief [l, r)区間の値を返します
    /// @param l 左端
    /// @param r 右端
    /// @return 値
    /// @note O(logN)
    S prod(int l, int r) const {
        S ans_l = e(), ans_r = e();
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) ans_l = op(ans_l, seg[l++]);
            if(r & 1) ans_r = op(seg[--r], ans_r);
        }
        return op(ans_l, ans_r);
    }

    /// @brief [0, N)区間の値を返します
    /// @return 値
    /// @note 可換の場合 O(1)
    /// @note でない場合 O(logN)
    S all_prod() const {
        if constexpr (Commutative) return n ? seg[1] : e();
        else return prod(0, n);
    }

    /// @brief 左端 l を固定し true から false に判定結果の変わる境界の1つを返す
    /// @param l 左端
    /// @param f 判定関数
    /// @return 右端のインデックス
    /// @pre f(e()) が true であること
    /// @note O(logN)
    int max_right(int l, auto f) const {
        assert(f(e()));
        int i = n + l, w = 1;
        S ans_l = e();
        for (; l + w <= n; i >>= 1, w <<= 1) if (i & 1) {
            if (not f(op(ans_l, seg[i]))) break;
            ans_l = op(ans_l, seg[i++]);
            l += w;
        }
        while (i <<= 1, w >>= 1) {
            if (l + w <= n && f(op(ans_l, seg[i]))) {
                ans_l = op(ans_l, seg[i++]);
                l += w;
            }
        }
        return l;
    }

    /// @brief 右端 r を固定し true から false に判定結果の変わる境界の1つを返す
    /// @param r 右端
    /// @param f 判定関数
    /// @return 左端のインデックス
    /// @pre f(e()) が true であること
    /// @note O(logN)
    int min_left(int r, auto f) const {
        assert(f(e()));
        int i = n + r, w = 1;
        S ans_r = e();
        for (; r - w >= 0; i >>= 1, w <<= 1) if (i & 1) {
            if (not f(op(seg[i - 1], ans_r))) break;
            ans_r = op(seg[--i], ans_r);
            r -= w;
        }
        while (i <<= 1, w >>= 1) {
            if (r - w >= 0 && f(op(seg[i - 1], ans_r))) {
                ans_r = op(seg[--i], ans_r);
                r -= w;
            }
        }
        return r;
    }
};