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
int sum(int i){
  return i*(i+1)/2;
}
void solve(){
  int n,k;cin>>n>>k;
  int idx=n/2;
  if(sum(n)-sum(n-idx)>=k&&sum(idx)<=k)cout<<"YES"<<nl;
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