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
void solve(){
   int p, x, y, z;cin >> p >> x >> y >> z;
        if (z > x)rv(cout << -1);
        int mx = (x * y) / z;
        cout << (p + mx - 1) / mx;
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