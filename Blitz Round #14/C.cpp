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
bool com(pair<int,int>a,pair<int,int>b){
  if(a.first==b.first)return a.second<b.second;
  return a.first>b.first;
}
void solve(){
 int n,m;cin>>n>>m;
 vec<int>ans(n,-1);
 vec<pair<int,int>>v;
 for(int i=0;i<n;i++){
  int x;cin>>x;
  v.push_back({x,i});
 }
 sort(all(v),com);
 vec<vec<int>>adj(n);
 for(int i=0;i<n;i++){
  int x;cin>>x;
  for(int j=0;j<x;j++){
   int y;cin>>y;
   adj[i].push_back(y-1);
  }
 }
 vec<int>b(m),c(m);
  for(int i=0;i<m;i++)cin>>b[i];
  for(int i=0;i<m;i++)cin>>c[i];
  for(int i=0;i<n;i++){
    int s=v[i].second;
    for(int j=0;j<adj[s].size();j++){
      int idx=adj[s][j];
      // cout<<b[idx]<<" "<<v[i].first<<" "<<c[idx]<<nl;
       if(b[idx]<v[i].first&&c[idx]){
        ans[s]=idx+1;
        c[idx]--;
        break;
       }
    }
    }
  for(int i=0;i<n;i++)cout<<ans[i]<<" ";
}
signed main()
{
   Moageza
    int t = 1;
     cin >> t;
    while (t--) {
        solve();
        cout <<endl;
    }
    return 0;
}