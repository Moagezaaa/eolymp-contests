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
int sum(int i){
    return i*(i+1)/2;
}
void solve(){
  int n;cin>>n;
  if(sum(n)%(n+1))rv(cout<<"NO"<<nl);
  cout<<"YES"<<nl;
  for(int i=n;i>=1;i--)cout<<i<<" ";
  cout<<nl;
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