#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n), c(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) cin >> c[i];

        vector<int> ab(n, 0), bc(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i] >= b[j]) {
                    int x = (j - i + n) % n;
                    ab[x]++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (b[i] >= c[j]) {
                    int x = (j - i + n) % n;
                    bc[x]++;
                }
            }
        }

        long long a1 = 0, b1 = 0;

        for (int i = 0; i < n; i++) {
            if (ab[i] == 0) a1++;
            if (bc[i] == 0) b1++;
        }

        cout << 1LL * n * a1 * b1 << '\n';
    }

    return 0;
}
