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
 vec<int> a(n),cnt(n+1,0),vis(n+1,0),pre(n+1,0);
 multiset<int>s;
 int mx=-1e9,ans=0;
 map<int,int>mp;
 for(int i=0;i<n;i++) {
    cin>>a[i];
    mp[a[i]]=i;
    mx=max(mx,a[i]);
    if(a[i]==mx) ans++,vis[i]=1;
  else{
    if(i){
        int x=*s.rbegin();
        s.erase(s.find(x));
        if(x>a[i]) vis[i]=2;
        if(s.size()){
            int y=*s.rbegin();
            s.erase(s.find(y));
            if(y>a[i]) vis[i]++;
            s.insert(y);
        }
            s.insert(x);
            if(vis[i]==2) cnt[mp[x]]++;
    }
  }
    s.insert(a[i]);
 }
    int res=0;
 for(int i=0;i<n;i++){
   if(vis[i]==1){
      res=max(res,cnt[i]+ans);
   }
   else res=max(res,ans+1);
 }
 cout<<res;
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