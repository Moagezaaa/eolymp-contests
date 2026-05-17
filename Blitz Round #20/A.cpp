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
  int n,m;cin>>n>>m;
  vec<int> a(n),b(m);
  for(int &i:a) cin>>i;
  for(int &i:b) cin>>i;
  sort(all(a)),sort(all(b));
  if(n>m) swap(a,b),swap(n,m);
  int i=0,j=0;
  while(i<n && j<m){
    if(a[i]==b[j])i++,j++;
    else j++;
  }
  if(i==n) cout<<"YES";
  else cout<<"NO";
}

signed main() {
    Moageza
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << nl;
    }
    return 0;
}