#include <bits/stdc++.h>
// #define int long long
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
void solve() {
   int n, x, y, k;cin >> n >> k >> x >> y; 
//    cout<<k<<" ";
        string res = "No";
        if (abs(x) == abs(y) && abs(x) == 1) {
            if (2 * (n + 1) <= k)  res = "Yes";
        } 
        else if (abs(x) == abs(y)) {
            if (abs(x) * (2 * n + 1) + abs(y) <= k)  res = "Yes";
        } else {
            if (2 * n * (max(abs(x), abs(y)) - 1) + abs(x) + abs(y) <= k) res = "Yes";
        }
        
        cout << res ;
}
signed main()
{
   Moageza
    int t = 1;
     cin >> t;
    while (t--) {   
        solve();
        cout <<nl;
    }
    return 0;
}