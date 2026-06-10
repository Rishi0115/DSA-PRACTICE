#include <bits/stdc++.h>
using namespace std;

long long k;
unordered_map<long long,int> dp;

int dfs(long long x) {
    if (x == k) return 0;
    if (x < k) return 1e9;

    if (dp.count(x)) return dp[x];

    int res = 1 + min(
        dfs(x / 2),
        dfs((x + 1) / 2)
    );

    return dp[x] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long n;
        cin >> n >> k;

        dp.clear();

        int ans = dfs(n);

        if (ans >= 1e9) cout << -1 << '\n';
        else cout << ans << '\n';
    }

    return 0;
}
