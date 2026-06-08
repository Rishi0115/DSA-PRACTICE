#include <bits/stdc++.h>
using namespace std;

bool can(long long x, long long m) {
    if (x == m) return true;
    if (x < m) return false;
    if (x % 3) return false;

    return can(x / 3, m) || can(2 * x / 3, m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, m;
        cin >> n >> m;

        cout << (can(n, m) ? "YES" : "NO") << '\n';
    }

    return 0;
}
