#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    vector<pair<int, int>> v; 
    int ans = 30, pos = 0;
    
    for (int i = 1; i <= n; i++) {
        vector<pair<int, int>> u;
        u.push_back({a[i], 1});
        
        for (auto [x, c] : v) {
            int g = (x | a[i]);
            if (g == u.back().first) {
                u.back().second = c;
            } else {
                u.push_back({g, c});
            }
        }
        
        v = u;
        
        for (auto [x, c] : v) {
            int cnt = (x ^ k);
            int res = __builtin_popcount(cnt);
            if (res <= ans) {
                ans = res;
                pos = cnt;
            }
        }
    }
    
    cout << ans << "\n";
    for (int i = 0; i < 30; i++) {
        if (pos & (1 << i)) {
            cout << i << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }
    return 0;
}