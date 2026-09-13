#include <bits/stdc++.h>
#define int long long
#define ll long long
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
  int x;cin>>x;
  vec<vec<int>>v(2,vec<int>(2));
  for(int i=0;i<2;i++) for(int j=0;j<2;j++)cin>>v[i][j];
  if(abs((v[0][0]*v[1][1]-v[0][1]*v[1][0]))==x)cout<<"YES"<<nl;
  else cout<<"NO"<<nl;
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