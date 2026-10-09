#pragma once

//!include関連
#include <bits/stdc++.h>
using namespace std;

#if __has_include(<atcoder/all>)
    #include <atcoder/all>
    using namespace atcoder;
    #define HAS_ACL 1
#else
    #define HAS_ACL 0
#endif