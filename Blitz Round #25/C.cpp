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
void solve(){
  int n,q;cin>>n>>q;
  vec<vec<int>>pre(n+1,vec<int>(201,0));
  for(int i=1;i<=n;i++){
    int x;cin>>x;
    for(int j=2;j*j<=x;j++){
        while(x%j==0){
            pre[i][j]++,x/=j;
            // cout<<j<<" ";
        }
    }
    if(x>1)pre[i][x]++;
    for(int j=2;j<=200;j++)pre[i][j]+=pre[i-1][j];
  }
  while(q--){
    int l,r,ans=0;cin>>l>>r;
    for(int j=2;j<=200;j++){
        if(pre[r][j]-pre[l-1][j]){
           ans=gcd(ans,pre[r][j]-pre[l-1][j]);
        }
    }
    cout<<ans<<nl;
  }
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