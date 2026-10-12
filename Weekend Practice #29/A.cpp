#include <bits/stdc++.h>
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
void solve(){
    int n; cin >> n;
    vec<int>a(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if(n==1){
    cout<<"YES";
    return;
  }
  bool check = false;
  for(int i=1;i<n;i++){
    if(abs(a[i]-a[i+1])%2==0){
        check=true;
        break;
    }
  }
    if(check)cout<<"YES";
    else cout<<"NO";
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