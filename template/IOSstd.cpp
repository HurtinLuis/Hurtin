#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using i64 = long long;
using u64 = unsigned long long;

#define siz(p) int(p.size())
#define all(p) p.begin(), p.end()

template<typename T> void chmin(T& a, const T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, const T b) { if (a < b) a = b; }

#ifdef LOCAL
#include "D:/Hurtin/debug.h"
#else
#define debug(...) 42
#endif

// ------------------------- MAIN -------------------------
using namespace std;

void solve() {

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

/** ---------- ✨ THINGS TO CHECK ✨ ----------
 *  ① int overflow or i64 memory need
 *  ② 1-idx or 0-idx, [l, r] or [l, r)
 *  ③ = or ==, > or >=, < or <=, n or m, i or j, p1 or p2...
 *  ④ operator priority
 *  ⑤ Init
 *  ⑥ Loop/dp/binary search/dfs bounds
 *  ⑦ Keep it simple and stupid
 *  ⑧ Do not delete, use "//" instead
 *  ⑨ Special cases(n = 1, 2), corner cases
 *  ⑩ Output format
 *  ? Is there anything extra to check
**/
