#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >>t;
    while (t--) {
        int n;
        cin >> n;
        string top, bot;
        cin >> top >> bot;
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int vertical = (top[i - 1] != bot[i - 1]);
            dp[i] = min(dp[i], dp[i - 1] + vertical);
            if (i >= 2) {
                int horizontal =
                    (top[i - 2] != top[i - 1]) +
                    (bot[i - 2] != bot[i - 1]);
                dp[i] = min(dp[i], dp[i - 2] + horizontal);
            }
        }
        cout << dp[n] << '\n';
    }

    return 0;
}
