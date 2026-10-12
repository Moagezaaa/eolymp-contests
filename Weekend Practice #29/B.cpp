#include <bits/stdc++.h>
#define ll long long 
// #define int long long
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
void solve() {
 int n;cin>>n;
 str s;cin>>s;
 vec<int>pre(n),suff(n);
 int cnt=1,ans=1;
 for(int i=0;i<n;i++){
    if(i){
        if(s[i]>=s[i-1])cnt++;
        else cnt=1;
    }
    pre[i]=cnt;
    ans=max(ans,cnt);
 }
 cnt=1;
 for(int i=n-1;i>=0;i--){
    if(i!=n-1){
        if(s[i]<=s[i+1])cnt++;
        else cnt=1;
    }
    suff[i]=cnt;
    ans=max(ans,cnt);
 }
 for(int i=0;i<n;i++){
  ans=max(ans,pre[i]);
  if(i<n-1)ans=max(ans,suff[i+1]+1);
  if(i)ans=max(ans,pre[i-1]+1);
  if(i>0&&i<n-1){
    if(s[i+1]>=s[i-1])ans=max(ans,pre[i-1]+suff[i+1]+1);
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