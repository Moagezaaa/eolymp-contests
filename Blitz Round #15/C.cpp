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
const int mod = 1e9 + 7;
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
  int m,n;cin>>m>>n;
  vec<int>vis(11,0);
  for(int i=0;i<m;i++){
    int x;cin>>x;
    vis[x]=1;
  }
  int ans=m;
  if(vis[0])ans=m-1;
  for(int i=2;i<=m;i++){
    ans*=m;
    ans%=mod;
  }
  cout<<power(ans,n,mod);
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