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
  vec<int> a(n);
  map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    int f=0;
    while(mp[f]){
        f++;
    }
    vec<int>ans(n+1,1e9);
    ans[n-mp[0]]=0;
    for(int i=1;i<=f;i++){
      ans[n-mp[i]]=min(ans[n-mp[i]],i);
    }
    ans[n]=f;
    for(int i=n-1;i>=0;i--){
        ans[i]=min(ans[i],ans[i+1]);
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
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