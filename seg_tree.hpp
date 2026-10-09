#pragma once
#include "base.hpp"

//!セグ木
#if HAS_ACL
    //*定義
    //定数
    static constexpr int64_t seg_mod = 998244353;
    static constexpr int64_t seg_inf = 4'000'000'000'000'000'000LL;
    static constexpr int64_t seg_id = -8'000'000'000'000'000'000LL;

    //モノイドの型 s
    struct seg_siz_s { int64_t val; int siz; };
    struct seg_idx_s { int64_t val; int idx; };
    struct seg_min_max_s {int64_t min, max; };
    struct seg_min_max_idx_s { seg_idx_s min, max; };
    struct seg_all_s { seg_idx_s min, max; int64_t sum; int siz, idx; };
    struct seg_sq_s {int64_t sum, sq; int siz; };

    constexpr seg_idx_s min(seg_idx_s a, seg_idx_s b)
        { if (a.val != b.val) return a.val < b.val ? a : b; return a.idx < b.idx ? a : b;}
    constexpr seg_idx_s max(seg_idx_s a, seg_idx_s b)
        { if (a.val != b.val) return a.val > b.val ? a : b; return a.idx < b.idx ? a : b;} //indexが小さい方を取ってる

    //項演算子 op
    constexpr int64_t sum_op(int64_t a, int64_t b) { return a + b; }
    constexpr int64_t mul_op(int64_t a, int64_t b) { return a * b; }
    constexpr int64_t sum_mod_op(int64_t a, int64_t b) { return (a + b) % seg_mod; }
    constexpr int64_t mul_mod_op(int64_t a, int64_t b) { return (a * b) % seg_mod; }
    constexpr seg_siz_s sum_siz_op(seg_siz_s a, seg_siz_s b) { return {a.val + b.val, a.siz + b.siz}; }
    constexpr seg_siz_s sum_siz_mod_op(seg_siz_s a,seg_siz_s b) { return {(a.val + b.val) % seg_mod, a.siz + b.siz}; }
    constexpr int64_t max_op(int64_t a, int64_t b) { return max(a, b); }
    constexpr int64_t min_op(int64_t a, int64_t b) { return min(a, b); }
    constexpr seg_idx_s min_idx_op(seg_idx_s a, seg_idx_s b) { return min(a, b); }
    constexpr seg_idx_s max_idx_op(seg_idx_s a, seg_idx_s b) { return max(a, b); }
    constexpr seg_min_max_s min_max_op(seg_min_max_s a, seg_min_max_s b) { return {min(a.min, b.min), max(a.max, b.max)}; }
    constexpr seg_min_max_idx_s min_max_idx_op (seg_min_max_idx_s a, seg_min_max_idx_s b)
        { return {min(a.min, b.min), max(a.max, b.max)}; }
    constexpr seg_all_s all_op(seg_all_s a, seg_all_s b)
        {return {min(a.min, b.min), max(a.max, b.max), a.sum + b.sum, a.siz + b.siz, min(a.idx, b.idx)}; }
    constexpr int64_t gcd_op(int64_t a, int64_t b) { return gcd(a, b); }
    constexpr int64_t lcm_op(int64_t a, int64_t b) { return lcm(a, b); }
    constexpr int64_t and_op(int64_t a, int64_t b) { return (a & b); }
    constexpr int64_t or_op(int64_t a, int64_t b) { return (a | b); }
    constexpr int64_t xor_op(int64_t a, int64_t b) { return (a ^ b); }
    constexpr seg_sq_s sq_op(seg_sq_s a, seg_sq_s b) { return {a.sum + b.sum, a.sq + b.sq, a.siz + b.siz}; }
    string txt_op(string a, string b) { return (a + b); }

    //単位元 e
    constexpr int64_t zero_e() { return 0; }
    constexpr seg_siz_s zero_siz_e() { return {0, 0}; }
    constexpr int64_t one_e() { return 1; }
    constexpr int64_t and_e() { return -1; }
    constexpr int64_t min_e() { return seg_inf; }
    constexpr int64_t max_e() { return -seg_inf; }
    constexpr seg_idx_s min_idx_e() { return {seg_inf, -1}; }
    constexpr seg_idx_s max_idx_e() { return {-seg_inf, -1}; }
    constexpr seg_min_max_s min_max_e() { return {seg_inf, -seg_inf}; }
    constexpr seg_min_max_idx_s min_max_idx_e() { return {{seg_inf, -1}, {-seg_inf, -1}}; }
    constexpr seg_all_s all_e() { return {{seg_inf, -1}, {-seg_inf, -1}, 0, 0, INT_MAX}; }
    constexpr seg_sq_s sq_e() { return {0, 0, 0}; }
    string empty_e() {return ""; }

    //写像の型 f
    struct seg_aff_f { int64_t a, b; };

    //ノードの更新 mapping
    constexpr int64_t add_map(int64_t f, int64_t x) { return x + f; }
    constexpr int64_t upd_map(int64_t f, int64_t x) { return f == seg_id ? x : f; }
    constexpr seg_min_max_s aff_min_max_map(seg_aff_f f, seg_min_max_s x) {
        if (x.min == seg_inf && x.max == -seg_inf) return x;
        int64_t a = x.min * f.a + f.b, b = x.max * f.a + f.b;
        return {min(a, b), max(a, b)};
    }
    constexpr seg_siz_s add_siz_map(int64_t f, seg_siz_s x) { x.val += f * x.siz; return x; }
    constexpr seg_siz_s upd_siz_map(int64_t f, seg_siz_s x) { if (f != seg_id) x.val = f * x.siz; return x; }
    constexpr seg_siz_s aff_siz_map(seg_aff_f f, seg_siz_s x) { return {x.val * f.a + f.b * x.siz, x.siz}; }
    constexpr seg_siz_s add_siz_mod_map(int64_t f, seg_siz_s x) { x.val = (x.val + f * x.siz) % seg_mod; return x; }
    constexpr seg_siz_s upd_siz_mod_map(int64_t f, seg_siz_s x) { if (f != seg_id) x.val = f * x.siz % seg_mod; return x; }
    constexpr seg_siz_s aff_siz_mod_map(seg_aff_f f, seg_siz_s x) { return {(x.val * f.a + f.b * x.siz) % seg_mod, x.siz}; }
    constexpr seg_all_s all_map(seg_aff_f f, seg_all_s x) {
        if (x.siz == 0) return x;
        if (f.a == 0) return {{f.b, x.idx}, {f.b, x.idx}, f.b * x.siz, x.siz, x.idx};
        x.min.val = x.min.val * f.a + f.b; x.max.val = x.max.val * f.a + f.b;
        return {min(x.min, x.max), max(x.min, x.max), x.sum * f.a + f.b * x.siz, x.siz, x.idx};
    }
    constexpr seg_sq_s add_sq_map(int64_t f, seg_sq_s x)
        { return {x.sum + f * x.siz, x.sq + 2 * f * x.sum + f * f * x.siz, x.siz}; }
    constexpr seg_sq_s upd_sq_map(int64_t f, seg_sq_s x)
        { if (f == seg_id) return x; return {f * x.siz, f * f * x.siz, x.siz}; }
    constexpr seg_sq_s aff_sq_map(seg_aff_f f, seg_sq_s x)
        { return {x.sum * f.a + f.b * x.siz, x.sq * f.a * f.a + 2 * x.sum * f.a * f.b + f.b * f.b * x.siz, x.siz}; }

    //パラメータの合成 composition
    constexpr int64_t add_com(int64_t f, int64_t g) { return g + f; }
    constexpr int64_t upd_com(int64_t f, int64_t g) { return f == seg_id ? g : f; }
    constexpr seg_aff_f aff_com(seg_aff_f f, seg_aff_f g) {return {g.a * f.a, g.b * f.a + f.b}; }
    constexpr seg_aff_f aff_mod_com(seg_aff_f f, seg_aff_f g) {return {g.a * f.a % seg_mod, (g.b * f.a + f.b) % seg_mod}; }

    //id
    constexpr int64_t zero_id() { return 0; }
    constexpr int64_t upd_id() { return seg_id; }
    constexpr seg_aff_f aff_id() { return {1, 0}; }


    //*シンプルなセグ木
    //区間和
    using sumtree = segtree<int64_t, sum_op, zero_e>;
    //区間積
    using multree = segtree<int64_t, mul_op, one_e>;
    //mod区間和
    using summodtree_base = segtree<int64_t, sum_mod_op, zero_e>;
    struct summodtree : summodtree_base {
        summodtree(int n) : summodtree_base(n) {}
        summodtree(const vector<int64_t> &v) : summodtree_base([&]{
            vector<int64_t> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = (v[i] % seg_mod + seg_mod) % seg_mod;
            return init;
        }()) {}
        void set(int p, int64_t x) { summodtree_base::set(p, (x % seg_mod + seg_mod) % seg_mod); }
    };
    //mod区間積
    using mulmodtree_base = segtree<int64_t, mul_mod_op, one_e>;
    struct mulmodtree : mulmodtree_base {
        mulmodtree(int n) : mulmodtree_base(n) {}
        mulmodtree(const vector<int64_t> &v) : mulmodtree_base([&]{
            vector<int64_t> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = (v[i] % seg_mod + seg_mod) % seg_mod;
            return init;
        }()) {}
        void set(int p, int64_t x) { mulmodtree_base::set(p, (x % seg_mod + seg_mod) % seg_mod); }
    };
    //区間最小
    using mintree = segtree<int64_t, min_op, min_e>;
    //区間最大
    using maxtree = segtree<int64_t, max_op, max_e>;
    //区間最大公約数
    using gcdtree = segtree<int64_t, gcd_op, zero_e>;
    //区間最小公倍数
    using lcmtree = segtree<int64_t, lcm_op, one_e>;
    //区間AND
    using andtree = segtree<int64_t, and_op, and_e>;
    //区間OR
    using ortree = segtree<int64_t, or_op, zero_e>;
    //区間XOR
    using xortree = segtree<int64_t, xor_op, zero_e>;
    //区間でつなげたtxt
    using txttree = segtree<string, txt_op, empty_e>;


    //*シンプルでないセグ木
    //区間最小＆最大
    using minmaxtree_base = segtree<seg_min_max_s, min_max_op, min_max_e>;
    struct minmaxtree : minmaxtree_base {
        minmaxtree (int n) : minmaxtree_base(n) {}
        minmaxtree (const vector<int64_t> &v) : minmaxtree_base([&]{
            vector<seg_min_max_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {v[i], v[i]};
            return init;
        }()) {}
        void set(int p, int64_t x) { minmaxtree_base::set(p, {x, x}); }
        int64_t get(int p) { return minmaxtree_base::get(p).min; }
    };
    //indexが取れる区間最小
    using minidxtree_base = segtree<seg_idx_s, min_idx_op, min_idx_e>;
    struct minidxtree : minidxtree_base {
        minidxtree (int n) : minidxtree_base(n) {}
        minidxtree (const vector<int64_t> &v) : minidxtree_base([&]{
            vector<seg_idx_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {v[i], i};
            return init;
        }()) {}
        void set(int p, int64_t x) { minidxtree_base::set(p, {x, p}); }
        int64_t get(int p) { return minidxtree_base::get(p).val; }
    };
    //indexが取れる区間最大
    using maxidxtree_base = segtree<seg_idx_s, max_idx_op, max_idx_e>;
    struct maxidxtree : maxidxtree_base {
        maxidxtree (int n) : maxidxtree_base(n) {}
        maxidxtree (const vector<int64_t> &v) : maxidxtree_base([&]{
            vector<seg_idx_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {v[i], i};
            return init;
        }()) {}
        void set(int p, int64_t x) { maxidxtree_base::set(p, {x, p}); }
        int64_t get(int p) { return maxidxtree_base::get(p).val; }
    };
    //indexが取れる区間最小＆最大
    using minmaxidxtree_base = segtree<seg_min_max_idx_s, min_max_idx_op, min_max_idx_e>;
    struct minmaxidxtree : minmaxidxtree_base {
        minmaxidxtree (int n) : minmaxidxtree_base(n) {}
        minmaxidxtree (const vector<int64_t> &v) : minmaxidxtree_base([&]{
            vector<seg_min_max_idx_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {{v[i], i}, {v[i], i}};
            return init;
        }()) {}
        void set(int p, int64_t x) { minmaxidxtree_base::set(p, {{x, p}, {x, p}}); }
        int64_t get(int p) { return minmaxidxtree_base::get(p).min.val; }
    };


    //*シンプルな遅延セグ木
    //区間加算・区間最小
    using addmintree = lazy_segtree<int64_t, min_op, min_e, int64_t, add_map, add_com, zero_id>;
    //区間更新・区間最小
    using updmintree = lazy_segtree<int64_t, min_op, min_e, int64_t, upd_map, upd_com, upd_id>;
    //区間加算・区間最大
    using addmaxtree = lazy_segtree<int64_t, max_op, max_e, int64_t, add_map, add_com, zero_id>;
    //区間更新・区間最大
    using updmaxtree = lazy_segtree<int64_t, max_op, max_e, int64_t, upd_map, upd_com, upd_id>;
    //区間加算・区間和
    using addsumtree_base = lazy_segtree<seg_siz_s, sum_siz_op, zero_siz_e, int64_t, add_siz_map, add_com, zero_id>;
    struct addsumtree : addsumtree_base {
        addsumtree (int n) : addsumtree_base(vector<seg_siz_s>(n, {0, 1})) {}
        addsumtree (const vector<int64_t> &v) : addsumtree_base([&]{
            vector<seg_siz_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {v[i], 1};
            return init;
        }()) {}
        int64_t prod(int l, int r) { return addsumtree_base::prod(l, r).val; }
        int64_t all_prod() { return addsumtree_base::all_prod().val; }
        int64_t get(int p) { return addsumtree_base::get(p).val; }
        void set(int p, int64_t x) { addsumtree_base::set(p, {x, 1}); }
    };
    //区間更新・区間和
    using updsumtree_base = lazy_segtree<seg_siz_s, sum_siz_op, zero_siz_e, int64_t, upd_siz_map, upd_com, upd_id>;
    struct updsumtree : updsumtree_base {
        updsumtree (int n) : updsumtree_base(vector<seg_siz_s>(n, {0, 1})) {}
        updsumtree (const vector<int64_t> &v) : updsumtree_base([&]{
            vector<seg_siz_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {v[i], 1};
            return init;
        }()) {}
        int64_t prod(int l, int r) { return updsumtree_base::prod(l, r).val; }
        int64_t all_prod() { return updsumtree_base::all_prod().val; }
        int64_t get(int p) { return updsumtree_base::get(p).val; }
        void set(int p, int64_t x) { updsumtree_base::set(p, {x, 1}); }
    };
    //区間ax+b・区間和
    using affsumtree_base = lazy_segtree<seg_siz_s, sum_siz_op, zero_siz_e, seg_aff_f, aff_siz_map, aff_com, aff_id>;
    struct affsumtree : affsumtree_base {
        affsumtree (int n) : affsumtree_base(vector<seg_siz_s>(n, {0, 1})) {}
        affsumtree (const vector<int64_t> &v) : affsumtree_base([&]{
            vector<seg_siz_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {v[i], 1};
            return init;
        }()) {}
        int64_t prod(int l, int r) { return affsumtree_base::prod(l, r).val; }
        int64_t all_prod() { return affsumtree_base::all_prod().val; }
        int64_t get(int p) { return affsumtree_base::get(p).val; }
        void set(int p, int64_t x) { affsumtree_base::set(p, {x, 1}); }
    };
    //区間加算・mod区間和
    using addsummodtree_base = lazy_segtree<seg_siz_s, sum_siz_mod_op, zero_siz_e, int64_t, add_siz_mod_map, add_com, zero_id>;
    struct addsummodtree : addsummodtree_base {
        addsummodtree (int n) : addsummodtree_base(vector<seg_siz_s>(n, {0, 1})) {}
        addsummodtree (const vector<int64_t> &v) : addsummodtree_base([&]{
            vector<seg_siz_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {(v[i] % seg_mod + seg_mod) % seg_mod, 1};
            return init;
        }()) {}
        int64_t prod(int l, int r) { return addsummodtree_base::prod(l, r).val; }
        int64_t all_prod() { return addsummodtree_base::all_prod().val; }
        int64_t get(int p) { return addsummodtree_base::get(p).val; }
        void set(int p, int64_t x) { addsummodtree_base::set(p, {(x % seg_mod + seg_mod) % seg_mod, 1}); }
        void apply(int l, int r, int64_t f) { addsummodtree_base::apply(l, r, (f % seg_mod + seg_mod) % seg_mod); }
    };
    //区間更新・mod区間和
    using updsummodtree_base = lazy_segtree<seg_siz_s, sum_siz_mod_op, zero_siz_e, int64_t, upd_siz_mod_map, upd_com, upd_id>;
    struct updsummodtree : updsummodtree_base {
        updsummodtree (int n) : updsummodtree_base(vector<seg_siz_s>(n, {0, 1})) {}
        updsummodtree (const vector<int64_t> &v) : updsummodtree_base([&]{
            vector<seg_siz_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {(v[i] % seg_mod + seg_mod) % seg_mod, 1};
            return init;
        }()) {}
        int64_t prod(int l, int r) { return updsummodtree_base::prod(l, r).val; }
        int64_t all_prod() { return updsummodtree_base::all_prod().val; }
        int64_t get(int p) { return updsummodtree_base::get(p).val; }
        void set(int p, int64_t x) { updsummodtree_base::set(p, {(x % seg_mod + seg_mod) % seg_mod, 1}); }
        void apply(int l, int r, int64_t f) { updsummodtree_base::apply(l, r, (f % seg_mod + seg_mod) % seg_mod); }
    };
    //区間ax+b・mod区間和
    using affsummodtree_base = lazy_segtree<seg_siz_s, sum_siz_mod_op, zero_siz_e, seg_aff_f, aff_siz_mod_map, aff_mod_com, aff_id>;
    struct affsummodtree : affsummodtree_base {
        affsummodtree (int n) : affsummodtree_base(vector<seg_siz_s>(n, {0, 1})) {}
        affsummodtree (const vector<int64_t> &v) : affsummodtree_base([&]{
            vector<seg_siz_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {(v[i] % seg_mod + seg_mod) % seg_mod, 1};
            return init;
        }()) {}
        int64_t prod(int l, int r) { return affsummodtree_base::prod(l, r).val; }
        int64_t all_prod() { return affsummodtree_base::all_prod().val; }
        int64_t get(int p) { return affsummodtree_base::get(p).val; }
        void set(int p, int64_t x) { affsummodtree_base::set(p, {(x % seg_mod + seg_mod) % seg_mod, 1}); }
        void apply(int l, int r, seg_aff_f f)
            { affsummodtree_base::apply(l, r, {(f.a % seg_mod + seg_mod) % seg_mod, (f.b % seg_mod + seg_mod) % seg_mod}); }
    };
    //区間加算・二乗和
    using addsqtree_base = lazy_segtree<seg_sq_s, sq_op, sq_e, int64_t, add_sq_map, add_com, zero_id>;
    struct addsqtree : addsqtree_base {
        addsqtree(int n) : addsqtree_base(vector<seg_sq_s>(n, {0, 0, 1})) {}
        addsqtree(const vector<int64_t> &v) : addsqtree_base([&]{
            vector<seg_sq_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {v[i], v[i] * v[i], 1};
            return init;
        }()) {}
        int64_t prod(int l, int r) { return addsqtree_base::prod(l, r).sq; }
        int64_t all_prod() { return addsqtree_base::all_prod().sq; }
        int64_t get(int p) { return addsqtree_base::get(p).sum; }
        void set(int p , int64_t x) {addsqtree_base::set(p, {x, x * x, 1}); }
    };
    //区間更新・二乗和
    using updsqtree_base = lazy_segtree<seg_sq_s, sq_op, sq_e, int64_t, upd_sq_map, upd_com, upd_id>;
    struct updsqtree : updsqtree_base {
        updsqtree(int n) : updsqtree_base(vector<seg_sq_s>(n, {0, 0, 1})) {}
        updsqtree(const vector<int64_t> &v) : updsqtree_base([&]{
            vector<seg_sq_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {v[i], v[i] * v[i], 1};
            return init;
        }()) {}
        int64_t prod(int l, int r) { return updsqtree_base::prod(l, r).sq; }
        int64_t all_prod() { return updsqtree_base::all_prod().sq; }
        int64_t get(int p) { return updsqtree_base::get(p).sum; }
        void set(int p , int64_t x) {updsqtree_base::set(p, {x, x * x, 1}); }
    };
    //区間ax+b・二乗和
    using affsqtree_base = lazy_segtree<seg_sq_s, sq_op, sq_e, seg_aff_f, aff_sq_map, aff_com, aff_id>;
    struct affsqtree : affsqtree_base {
        affsqtree(int n) : affsqtree_base(vector<seg_sq_s>(n, {0, 0, 1})) {}
        affsqtree(const vector<int64_t> &v) : affsqtree_base([&]{
            vector<seg_sq_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {v[i], v[i] * v[i], 1};
            return init;
        }()) {}
        int64_t prod(int l, int r) { return affsqtree_base::prod(l, r).sq; }
        int64_t all_prod() { return affsqtree_base::all_prod().sq; }
        int64_t get(int p) { return affsqtree_base::get(p).sum; }
        void set(int p , int64_t x) {affsqtree_base::set(p, {x, x * x, 1}); }
    };


    //*シンプルでない遅延セグ木
    //区間ax+b・区間最小＆最大
    using affminmaxtree_base = lazy_segtree<seg_min_max_s, min_max_op, min_max_e, seg_aff_f, aff_min_max_map, aff_com, aff_id>;
    struct affminmaxtree : affminmaxtree_base {
        affminmaxtree (int n) : affminmaxtree_base(n) {}
        affminmaxtree (const vector<int64_t> &v) : affminmaxtree_base([&]{
            vector<seg_min_max_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {v[i], v[i]};
            return init;
        }()) {}
        int64_t get(int p) { return affminmaxtree_base::get(p).min; }
        void set(int p, int64_t x) { affminmaxtree_base::set(p, {x, x}); }
    };
    //区間更新＆加算＆乗算＆ax+b・indexが取れる区間最小＆最大＆総和
    using alltree_base = lazy_segtree<seg_all_s, all_op, all_e, seg_aff_f, all_map, aff_com, aff_id>;
    struct alltree : alltree_base {
        alltree (int n) : alltree_base([&]{
            vector<seg_all_s> init(n);
            for (int i = 0; i < n; i++) init[i] = {{0, i}, {0, i}, 0, 1, i};
            return init;
        }()) {}
        alltree (const vector<int64_t> &v) : alltree_base([&]{
            vector<seg_all_s> init(v.size());
            for (int i = 0; i < (int)v.size(); i++) init[i] = {{v[i], i}, {v[i], i}, v[i], 1, i};
            return init;
        }()) {}
        void set(int p, int64_t x) { alltree_base::set(p, {{x, p}, {x, p}, x, 1, p}); }
        int64_t get(int p) { return alltree_base::get(p).sum; }
        void upd(int l, int r, int64_t x) { alltree_base::apply(l, r, {0, x}); }
        void add(int l, int r, int64_t x) { alltree_base::apply(l, r, {1, x}); }
        void mul(int l, int r, int64_t x) { alltree_base::apply(l, r, {x, 0}); }
    };


    //*＠フリーセグ木
    //区間和の例
    //型
    //?ここで値の型を指定
    using seg_s = int64_t;

    //二項演算
    constexpr seg_s seg_op(seg_s a, seg_s b) {
        //?ここで演算方法を指定
        return a + b;
    }

    //単位元
    constexpr seg_s seg_e() {
        //?操作を行っても変わらない値
        return 0;
    }

    using mysegtree = segtree<seg_s, seg_op, seg_e>;


    //*＠フリー遅延セグ木
    //区間加算区間和の例
    //型
    //?ここで値の型を指定
    struct leg_s {
        int64_t val;
        int siz;
    };

    //二項演算
    constexpr leg_s leg_op(leg_s a, leg_s b) {
        //?ここで演算方法を指定
        return {a.val + b.val, a.siz + b.siz};
    }

    //単位元
    constexpr leg_s leg_e() {
        //?操作を行っても変わらない値
        return {0, 0};
    }

    //写像の型
    //?どういう更新を行うか
    using leg_f = int64_t;

    //mapping
    constexpr leg_s leg_map(leg_f f, leg_s x) {
        //?更新方法
        return {x.val + f * x.siz, x.siz};
    }

    //composition
    constexpr leg_f leg_com(leg_f f, leg_f g) {
        //?gに対しfで更新する
        return g + f;
    }

    //id
    constexpr leg_f leg_id() {
        //?更新の単位元
        return 0;
    }

    using mylazysegtree = lazy_segtree<leg_s, leg_op, leg_e, leg_f, leg_map, leg_com, leg_id>;
#endif