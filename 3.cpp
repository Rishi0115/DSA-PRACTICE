#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
            sort(a[i].begin(), a[i].end());
        }

        vector<int> pos(n, -1);
        bool ok = true;

        for (int i = 0; i < n; i++) {
            int r = a[i][0] % n;

            for (int x : a[i]) {
                if (x % n != r) {
                    ok = false;
                    break;
                }
            }

            if (!ok) break;

            if (pos[r] != -1) {
                ok = false;
                break;
            }

            pos[r] = i + 1; 
        }

        for (int r = 0; r < n; r++) {
            if (pos[r] == -1) ok = false;
        }

        if (!ok) {
            cout << -1 << '\n';
        } else {
            for (int r = 0; r < n; r++) {
                cout << pos[r] << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}
