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
  int n,m;cin>>n>>m;
  vec<int>v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  if(n==1)rv(cout<<v[0]);
  for(int i=0;i<n-1;i++){
    cout<<0<<" ";
  }
  int gd=m;
  for(int i=0;i<n;i++){
    gd=gcd(gd,v[i]);
  }
   cout<<gd;
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