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
//////////////////////////////////////////////////////
const int MOD = 1e9 + 7;

int power(int x, int y, int p) {
    int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
void solve(){
  int n;cin >> n;
    vec<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int ans = 0;
    for (int j = 0; j < n; j++) {
        int temp = (-a[j]) ;
        temp = temp * power((1 - a[j]) , j, MOD) % MOD;
        temp = temp * power(2, n - j - 1, MOD) % MOD;
        ans = (ans + temp+MOD) % MOD;
    }
    cout << ans ;
}

signed main() {
    Moageza
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << nl;
    }
    return 0;
}