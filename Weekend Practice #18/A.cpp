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
  int n,k;cin>>n>>k;
  vec<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int mx=0;
    for(int i=0;i<k-1;i++)mx=max(mx,v[i]);
    cout<<max(0LL,(mx+1)-v[k-1]);
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
        cout <<endl;
    }
    return 0;
}