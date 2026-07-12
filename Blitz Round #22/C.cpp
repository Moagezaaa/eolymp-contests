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
  vec<int>v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  set<int>s(all(v));
  if(s.size()==1){
    cout<<0;
    return ;
  }
  int ans1=*s.rbegin(),ans2=0,mx=0;
  for(int i=0;i<n;i++){
    if(v[i]==ans1){
        ans2+=mx;
        mx=0;
    }
    else{
        mx=max(mx,v[i]);
    }
  }
  ans2+=mx;
  cout<<min(ans1,ans2);
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