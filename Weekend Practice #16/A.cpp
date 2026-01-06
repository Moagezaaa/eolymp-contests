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
  int n,k;cin>>n>>k;
  vec<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
  int sum=0;
  vec<int>ans(k,a[0]);
    for(int i=1;i<n;i++){
        vec<int>temp;
        for(int j=0;j<k;j++){
            temp.push_back(a[i]);
            a[i]-=ans[j];
        }
        ans=temp;
  }
  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
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