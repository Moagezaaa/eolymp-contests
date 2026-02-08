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
 int n;cin>>n;
 vec<int>ans(n+5,LLONG_MAX),v(n),vis(n+5,0);
  for(int i=0;i<n;i++){
    cin>>v[i];
    vis[v[i]]=i;
  }
 for(int i=0;i<n;i++){
    for(int j=v[i]+1;j<=min(n,v[i]+100);j++){
        int diff=abs(v[i]-j),idx=abs(vis[j]-vis[v[i]]);
        ans[i]=min(diff*idx,ans[i]);
        ans[vis[j]]=min(diff*idx,ans[vis[j]]);
    }
     for(int j=i+1;j<min(n,i+100);j++){
        int diff=abs(v[i]-v[j]),idx=abs(i-j);
        ans[i]=min(diff*idx,ans[i]);
        ans[j]=min(diff*idx,ans[j]);
    }
 }
 for(int i=0;i<n;i++){
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
        cout <<nl;
    }
    return 0;
}