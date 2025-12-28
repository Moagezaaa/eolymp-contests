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
int help(int x,int y){
    x%=mod,y%=mod;
    return (x*y)%mod;

}
void solve() {
  int a,b,ans=0;cin>>a>>b;
  vec<int>sum1(32,0),sum2(32,0),q(32,0),w(32,0);
  for(int i=a;i<=b;i++){
    for(int j=0;j<32;j++){
      if((i>>j)&1)sum1[j]++,q[j]+=i;
      else w[j]+=i,sum2[j]++;
    }
  }
 for(int i=a;i<=b;i++){
    for(int j=0;j<32;j++){
      if((i>>j)&1)sum1[j]--,q[j]-=i;
        else sum2[j]--,w[j]-=i;
    }
     for(int j=0;j<32;j++){
      if((i>>j)&1){
      ans+=help((1LL<<j),q[j]-(sum1[j]*i));
      ans%=mod;
    //   cout<<help(sum1[j]*(1LL<<j),q[j]-(sum1[j]*i))<<" ";
      ans+=help((1LL<<j),w[j]-(sum2[j]*i));
    //   cout<<help((1LL<<j),w[j]-(sum2[j]*i))<<" ";
      ans%=mod;
    }
    else{
      ans+=help((1LL<<j),q[j]-(sum1[j]*i));
    //   ans%=mod;
    }
    // cout<<ans<<" ";
  }
    // cout<<ans<<" ";
  }
    cout<<ans;
}
signed main()
{
    Moageza
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << nl;
    }
    return 0;
}