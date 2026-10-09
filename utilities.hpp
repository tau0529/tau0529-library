#pragma once
#include "base.hpp"

//!小規模群
//*略
using lint = int64_t;
using lint7 = __int128_t; //2^7bit
using ld = long double;
using pll = pair<int64_t, int64_t>;
using plp = pair<int64_t, pair<int64_t, int64_t>>;
using ppl = pair<pair<int64_t, int64_t>, int64_t>;
using ppp = pair<pair<int64_t, int64_t>, pair<int64_t, int64_t>>;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vector<vector<T>>;
template<typename T> using vvv = vector<vector<vector<T>>>;
template<typename T> using vvvv = vector<vector<vector<vector<T>>>>;
using vl = vector<int64_t>;
using vvl = vector<vector<int64_t>>;
using vvvl = vector<vector<vector<int64_t>>>;
using vvvvl = vector<vector<vector<vector<int64_t>>>>;
using vd = vector<long double>;
using vp = vector<pair<int64_t, int64_t>>;
template<typename T> using pq = priority_queue<T, vector<T>>; // 大きい順
template<typename T> using pqg = priority_queue<T, vector<T>, greater<T>>; // 小さい順

#define pb push_back
#define mp make_pair
#define fi first
#define se second


//*マクロ
//ループマクロ
//rrは始点指定 eeは逆順 ppは閉区間
#define     re(n)       for (int64_t r_= 0;            r_<  int64_t(n);r_++)
#define    rep(i, n)    for (int64_t i = 0;            i <  int64_t(n); i++)
#define   repp(i, n)    for (int64_t i = 0;            i <= int64_t(n); i++)
#define   rrep(i, a, b) for (int64_t i = int64_t(a);   i <  int64_t(b); i++)
#define  rrepp(i, a, b) for (int64_t i = int64_t(a);   i <= int64_t(b); i++)
#define   reep(i, n)    for (int64_t i = int64_t(n)-1; i >= 0;          i--)
#define  reepp(i, n)    for (int64_t i = int64_t(n);   i >= 0;          i--)
#define  rreep(i, a, b) for (int64_t i = int64_t(b)-1; i >= int64_t(a); i--)
#define rreepp(i, a, b) for (int64_t i = int64_t(b);   i >= int64_t(a); i--)

//allマクロ
#define all(v) (v).begin(), (v).end()

//sizeをint64_tで取得
#define sz(x) ((int64_t)(x).size())

//nextpermutation
#define next_p(v) next_permutation((v).begin(), (v).end())

//範囲外ならcontinue
#define in_grid(h, w, H, W) { if ((h) < 0 || (w) < 0 || (H) <= (h) || (W) <= (w)) continue; }



//*定数
//無限
constexpr int64_t inf = 1001001001;
constexpr int64_t INF = 4004004004004004004LL;

//MOD
constexpr int64_t MOD  =  998244353;
constexpr int64_t MOD7 = 1000000007;
constexpr int64_t MOD9 = 1000000009;
#if HAS_ACL
    using mint  = modint998244353;
    using mint7 = modint1000000007;
    using mint9 = static_modint<1000000009>;
#endif

//有名数
constexpr long double pi    = 3.14159265358979323846L;
constexpr long double N_pi  = 3.14159265358979323846L;
constexpr long double N_e   = 2.71828182845904523536L;
constexpr long double N_phi = 1.61803398874989484820L;

//グリッド移動
static constexpr int64_t dh[] = {0, -1, 0, 1, -1, -1, 1, 1, 0};
static constexpr int64_t dw[] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
static constexpr char ds[] = "RULD";


//*Yes No出力
#define YES cout << "YES\n"
#define Yes cout << "Yes\n"
#define NO cout << "NO\n"
#define No cout << "No\n"
#define noo cout << "-1\n" //Negative One

void YN(bool b) {
    cout << (b ? "YES\n" : "NO\n");
}
void yn(bool b) {
    cout << (b ? "Yes\n" : "No\n");
}


//*デバッグ出力
#ifdef LOCAL
    template <typename T, typename... Ts>
    void debug(const T &x, const Ts &... xs) {
        cerr << x;
        ((cerr << ' ' << xs), ...);
        cerr << "\n";
    }

    template <typename... Ts>
    void col_dbg(const char *color, const Ts &... xs) {
        cerr << color;
        debug(xs...);
        cerr << "\033[0m";
    }
    #define dbg(...) col_dbg("\033[38;5;208m", __VA_ARGS__)
    #define rdb(...) col_dbg("\033[31m", __VA_ARGS__)
    #define gdb(...) col_dbg("\033[32m", __VA_ARGS__)
    #define ydb(...) col_dbg("\033[33m", __VA_ARGS__)
    #define bdb(...) col_dbg("\033[34m", __VA_ARGS__)
    #define mdb(...) col_dbg("\033[35m", __VA_ARGS__)
    #define cdb(...) col_dbg("\033[36m", __VA_ARGS__)
    #define wdb(...) col_dbg("\033[37m", __VA_ARGS__)
#else
    #define debug(...) ((void)0)
    #define dbg(...) ((void)0)
    #define rdb(...) ((void)0)
    #define gdb(...) ((void)0)
    #define ydb(...) ((void)0)
    #define bdb(...) ((void)0)
    #define mdb(...) ((void)0)
    #define cdb(...) ((void)0)
    #define wdb(...) ((void)0)
#endif


//*経過時間
long double Time () {
    return 1.0L * (clock()) / CLOCKS_PER_SEC;
}


//*値の更新
template <typename T1, typename T2>
bool chmin(T1 &x, const T2 &y) {
    bool b = x > y;
    if (b) x = y;
    return b;
}
template <typename T1, typename T2>
bool chmax(T1 &x, const T2 &y) {
    bool b = x < y;
    if (b) x = y;
    return b;
}
template <typename T1, typename T2>
bool CHMIN(T1 &x, const T2 &y) {
    if (x > y) x = y;
    return x == y;
}
template <typename T1, typename T2>
bool CHMAX(T1 &x, const T2 &y) {
    if (x < y) x = y;
    return x == y;
}