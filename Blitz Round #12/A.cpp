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
    int n;cin>>n;
   str s;cin>>s;
   int c=0,d=0;
   for(auto i:s){
    if(i=='6')c=1;
    if(i=='7')d=1;
   }
   if(c&&d)cout<<"NO";
   else cout<<"YES";
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