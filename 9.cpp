#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int x = i;

        while (x > 0) {
            int d = x % 10;

            if (d != 0) {
                dp[i] = min(dp[i], dp[i - d] + 1);
            }

            x /= 10;
        }
    }

    cout << dp[n] << '\n';
    return 0;
}
