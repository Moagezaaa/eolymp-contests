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
void solve() {
  int n,k;cin>>n>>k;
  int ans=n;k--;
  for(int i=60;i>=0;i--){
    int res=(1LL<<i);
    if(res-1<=n&&k){
        ans|=res-1,k--;
    break;
    }
  }
    cout<<ans;
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