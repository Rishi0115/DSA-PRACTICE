#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) cin >> p[i];
        string s;
        cin >> s;
        s = " " + s;
        vector<int> ans(n + 1, 0);
        vector<int> vis(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            vector<int> cycle;
            int cur = i;
            while (!vis[cur]) {
                vis[cur] = 1;
                cycle.push_back(cur);
                cur = p[cur];
            }
            int black = 0;
            for (int x : cycle) {
                if (s[x] == '0') black++;
            }

            for (int x : cycle) {
                ans[x] = black;
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}
