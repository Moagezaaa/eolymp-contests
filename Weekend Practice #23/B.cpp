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
const int mod=1e9+7;
int res(int n){
    return (1<<n)-1;
}
void solve(){
  int n;cin>>n;
  int cnt=0,ans=1;
  bitset<33> b(n);
  for(int i=0;i<33;i++){
    if(b[i]){
        ans*=3;
        ans%=mod;
        cnt++;
    }
  }
   ans-=2;
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