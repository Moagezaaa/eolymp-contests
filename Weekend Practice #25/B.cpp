#include <bits/stdc++.h>
#define ld long double
// #define int long long
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
const int N=2e5+5;
void solve(){
  int n,k;cin>>n>>k;
  vec<vec<int>>p(N);
  for(int i=1;i<N;i++){
    for(int j=i;j<N;j+=i)p[i].push_back(j);
  }
  int sum=0;
  vec<int>vis(N,0);
  for(int i=0;i<n;i++){
    int x;cin>>x;
    vis[x]++;
  }
  for(int i=1;i<N;i++){
        int cnt=0;
    if(vis[i]){
        for(int j:p[i])cnt+=vis[j];
    }
    if(cnt>=3)sum+=i;
  }
  if(sum>k)cout<<"YES";
  else cout<<"NO";

}
signed main()
{
   Moageza
    int t = 1;
    //  cin >> t;
    while (t--) {
        solve();
        // cout << nl;
    }
    return 0;
}