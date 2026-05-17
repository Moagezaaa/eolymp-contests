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
int sum(int n){
    return n*(n+1)/2;
}
void solve(){
  int n;cin>>n;
  vec<int>v(n),f={0,1,1,2,3};
  map<int,int>mp;
  for(int i=0;i<n;i++)cin>>v[i],mp[v[i]]++;
  int ans=0;
  if(mp.count(0)){
    ans+=sum(mp[0]-1)+(mp[0]*(n-mp[0]));
  }
  for(int i=1;i<=4;i++){
    if(mp.count(i)){
       for(int j=i+1;j<=4;j++){
         if(mp.count(j)){
            if(f[i]+f[j]&&i+j<=4&&f[i]+f[j]==f[i+j]){
                ans+=(mp[i]*mp[j]);
            }
         }
       }
    }
  }
    cout<<ans;
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