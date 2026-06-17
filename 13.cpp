#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int mx = 100 * n;
        vector<int> dp(mx + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            int v = 100 / a[i];
            vector<int> ndp(mx + 1, 0);
            for (int s = 0; s <= mx; s++) {
                if (!dp[s]) continue;
                for (int k = 0; k <= a[i]; k++) {
                    int ns = s + k * v;
                    if (ns <= mx) ndp[ns] = 1;
                }}
            dp.swap(ndp);
        }
        bool ok = true;
        for (int s = 0; s <= mx; s++) {
            if (!dp[s]) {
                ok = false;
                break;
            }}

        cout<<(ok ? "Yes" : "No") << '\n';
    }
    return 0;
}
