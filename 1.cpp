#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >>n>>k;
        vector<int> a(n), b;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        b = a;
        sort(b.begin(), b.end());
        map<int, int> pos;
        for(int i = 0; i < n; i++) {
            pos[b[i]] = i;
        }
        int c= 1;
        for(int i = 0; i < n - 1; i++) {
            if(pos[a[i + 1]] != pos[a[i]] + 1) {
                c++;
            }}
        if(c <= k) cout << "YES\n";
        else cout << "NO\n";
    }
}