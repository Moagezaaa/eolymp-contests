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
  vec<int>v;
  int l=1,r=n,f=0;
  while(l<=r){
    if(f==0){
        v.push_back(r);
        r--;
    }
    else{
        v.push_back(l);
        l++;
    }
    f^=1;
  }
    for(auto i:v)cout<<i<<" ";
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