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
  int l,r,x;cin>>l>>r>>x;
  int ans=0,val=1;
  for(int i=0;i<60;i++){
    int low=1,high=1e18/val;
    while(low<=high){
      int mid=(low+high)/2;
      if((mid*val)<l){
        low=mid+1;
      }
      else if((mid*val)>r){
        high=mid-1;
      }
      else{
        ans=mid*val;
        low=mid+1;
      }
    }
    if (val > r / x) break;
    val*=x;
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