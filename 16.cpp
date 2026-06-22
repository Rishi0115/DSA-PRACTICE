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
        vector<int> a(n);

        for (int i = 0; i < n; i++) cin >> a[i];

        int ans = 0;
        int last = -1;

        for (int x : a) {
            if (x > last + 1) {
                ans++;
                last = x;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
