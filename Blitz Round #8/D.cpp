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
   int n,k,ans=0;cin>>n>>k;
   vec<int>v(n);
   for(int i=0;i<n;i++)cin>>v[i];
   for(int i=31;i>=0;i--){
        int cnt=0;
    for(int j=0;j<n;j++){
        if((v[j]&(1LL<<i))==0)cnt++;
    }
   if(cnt==k){
    ans|=(1LL<<i);
    if(k){
    for(int j=0;j<n;j++){
       if((v[j]&(1LL<<i))==0)v[j]=~v[j];
    }
    k=0;
   }
   }
}
   cout<<ans;
}
signed main()
{
   Moageza
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    //  cin >> t;
    while (t--) {
        solve();
        // cout << nl;
    }
    return 0;
}