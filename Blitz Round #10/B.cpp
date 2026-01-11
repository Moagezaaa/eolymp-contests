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
  int n,i;cin>>n>>i;
  if(i>2*n)rv(cout<<-1);
  if(n==1){
    if(i==1)cout<<8;
    else cout<<1;
    return;
  }
  if(i<=n-1)rv(cout<<9);
  if(i==n)rv(cout<<8);
  if(i==2*n)rv(cout<<1);
  rv(cout<<0);
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