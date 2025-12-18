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
  vec<int>v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  sort(all(v));
  int cnt=1,ans=1;
  for(int i=0;i<n-1;i++){
      if(abs(v[i]-v[i+1])<=1)cnt++;
      else cnt=1;
      ans=max(ans,cnt);
  }
  cout<<ans;
}
signed main()
{
   Moageza
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
     cin >> t;
    while (t--) {
        solve();
        cout << nl;
    }
    return 0;
}