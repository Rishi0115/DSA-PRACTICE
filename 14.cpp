#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<string> s(k);
        for (int i = 0; i < k; i++) cin >> s[i];

        vector<int> mask(n, 0);

        for (int j = 0; j < n; j++) {
            int m = 0;
            for (int i = 0; i < k; i++) {
                m |= (1 << (s[i][j] - 'a'));
            }
            mask[j] = m;
        }

        vector<int> divs;
        for (int d = 1; d * d <= n; d++) {
            if (n % d == 0) {
                divs.push_back(d);
                if (d * d != n) divs.push_back(n / d);
            }
        }
        sort(divs.begin(), divs.end());

        int best = n;
        string ans;

        for (int d : divs) {
            vector<int> cur(d, (1 << 26) - 1);
            bool ok = true;

            for (int r = 0; r < d; r++) {
                int x = (1 << 26) - 1;

                for (int p = r; p < n; p += d) {
                    x &= mask[p];
                }

                if (x == 0) {
                    ok = false;
                    break;
                }

                cur[r] = x;
            }

            if (!ok) continue;

            best = d;
            ans.resize(n);

            for (int r = 0; r < d; r++) {
                char ch = 'a';
                for (int b = 0; b < 26; b++) {
                    if (cur[r] & (1 << b)) {
                        ch = char('a' + b);
                        break;
                    }
                }

                for (int p = r; p < n; p += d) {
                    ans[p] = ch;
                }
            }

            break;
        }
        cout << ans << '\n';
    }
    return 0;
}
