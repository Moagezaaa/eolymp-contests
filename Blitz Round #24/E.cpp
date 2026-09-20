#include <bits/stdc++.h>
#define int long long
#define ld long double
#define nl "\n"
#define ull unsigned long long
#define rv return void
#define str string
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define vec vector
#define fixed(n) fixed << setprecision(n)
#define Moageza ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;
//////////////////////////////////////////////////////
void solve(){
   int n;
    cin >> n;
 
    vector<int> h(n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        m = max(m, h[i]);
    }
 
    int L = -1, R = -1;
    for (int i = 0; i < n; i++) {
        if (h[i] == m) {
            if (L == -1) L = i;
            R = i;
        }
    }
 
    bool valid = true;
    for (int i = 1; i <= L; i++) {
        if (h[i] < h[i - 1])
            valid = false;
    }
    for (int i = L; i <= R; i++) {
        if (h[i] != m)
            valid = false;
    }
    for (int i = R + 1; i < n; i++) {
        if (h[i] > h[i - 1])
            valid = false;
    }
 
    if (!valid) {
        cout << 0 << "\n";
        return;
    }
 
    int ans = 1;
    for (int i = 1; i <= L; i++) {
        if (h[i] == h[i - 1]) {
            ans = (ans * h[i]) % MOD;
        }
    }
 
    for (int i = L + 1; i < R; i++) {
        ans = (ans * m) % MOD;
    }
 
    for (int i = R + 1; i < n; i++) {
        if (h[i] == h[i - 1]) {
            ans = (ans * h[i]) % MOD;
        }
    }
 
    cout << ans << "\n";
}
signed main()
{
   Moageza
    int t = 1;
     cin >> t;
    while (t--) {
        solve();
        cout << nl;
    }
    return 0;
}