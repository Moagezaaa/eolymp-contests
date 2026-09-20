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
void solve(){
 int m, n, s;
    cin >> m >> n >> s;
    
   int first_row = (s + m - 1) / m;
    int last_row = ((s + n - 1) + m - 1) / m;
    
    int ans = last_row - first_row + 1;
    cout << ans << "\n";
}
signed main()
{
   Moageza
    int t = 1;
    cin >> t;    
    while (t--) {
        solve();
    }
    return 0;
}