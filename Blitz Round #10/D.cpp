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
  int n,q;cin>>n>>q; 
  int res=0,lvl=0;
  vec<int>v(60,0),sum(60,0);
  for(int i=0;i<60;i++){
    int f=(1LL<<i);
    f=2*f-1;
    if(f<=n)res=f,lvl=i,v[i]=(1LL<<i);
    else break;
  }
  if(res<n){
    lvl++;
    v[lvl]=n-res;
  }
  sum[0]=v[0];
  for(int i=1;i<=lvl;i++){
    sum[i]=sum[i-1]+v[i];
  }
  while(q--){
    int a,b,c,d;cin>>a>>b>>c>>d;
    int ans=0;
    for(int i=0;i<=lvl;i++){
        if(i>=a&&i<=b){
          if(c<=lvl){
            int h=max(i,c);
            if(h<=lvl&&h<=d){
                if(h)ans+=sum[min(lvl,d)]-sum[h-1];
                else ans+=sum[min(lvl,d)];
            }
          }
      }
    }
    cout<<ans<<nl;
    
    }
}

signed main()
{
    Moageza
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
        cout << nl;
    }
    return 0;
}