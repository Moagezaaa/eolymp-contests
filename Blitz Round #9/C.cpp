#include <bits/stdc++.h>
// #define int long long
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
  vec<int>v,vv;
  for(int i=0;i<n;i++){
    int x;cin>>x;
   if(x>=0) v.push_back(x);
   else vv.push_back(x);
  }
  sort(allr(vv)),sort(allr(v));
  for(auto x:v) cout<<x<<" ";
  int i=0;
  while(i<vv.size()){
    cout<<vv[i]<<" ";
    i++;
    if(i<vv.size()){
      cout<<vv.back()<<" ";
      vv.pop_back();
    }
    if(i<vv.size()){
       cout<<vv.back()<<" ";
      vv.pop_back();
    }
  }
  
}

signed main()
{
    Moageza
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << nl;
    }
    return 0;
}