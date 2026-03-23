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
  vec<int> a(n);
  int sum=0;
  for(int i=0;i<n;i++)cin>>a[i],sum+=a[i];
  if(sum%2==0)rv(cout<<"YES");
   for(int i=0;i<n;i++){
    str s=to_string(a[i]);
    int val=a[i];
    for(int j=0;j<s.size();j++){
        if((sum-val+(s[j]-'0'))%2==0)rv(cout<<"YES");
   }
  }
  cout<<"NO";
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