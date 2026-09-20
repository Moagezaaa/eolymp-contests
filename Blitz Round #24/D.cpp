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
  int n,m,k;cin>>n>>m>>k;
  vec<vec<int>>v(n+1);
  vec<int>vis(n+1,0);
  int ans=0;
  for(int i=0;i<m;i++){
    int x,y;cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
    vis[x]++,vis[y]++;
    ans+=3;
  }
  vec<int>f;
  for(int i=1;i<=n;i++){
    f.push_back(vis[i]);
  }
  sort(allr(f));
  for(int i=0;i<k;i++){
    ans-=f[i];
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
        cout << nl;
    }
    return 0;
}