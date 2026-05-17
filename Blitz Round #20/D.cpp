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
  int n;cin>>n;
  vec<int>v(n),f(32,n+5),l(32,0),cnt(32,0);
  int ans=0;
  for(int i=0;i<n;i++){
    cin>>v[i];
    ans|=v[i];
    bitset<32>bs(v[i]);
    for(int j=0;j<31;j++){
      if(bs[j]){
        f[j]=min(f[j],i);
        l[j]=max(l[j],i);
        cnt[j]++;
      }
    }
  }
  int res=1e18;
   for(int i=0;i<n;i++){
    int sum=0,mx=1e9;
    for(int j=31;j>=0;j--){
        if(f[j]==i){
          if(l[j]-f[j]+1==cnt[j]){
            if(!sum)mx=l[j],sum|=(1LL<<j);
            else {
                if(l[j]==mx){
                    sum|=(1LL<<j);
                }
            }
          }
        }
    }
    res=min(res,ans^sum);
   }
    cout<<res;
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