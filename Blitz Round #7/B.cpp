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
   int n,ans=0;cin>>n;
   vec<int>v(n),x,vis(n+1,0);
   for(int i=0;i<n;i++)cin>>v[i];
   sort(all(v));
   for(int i=0;i<3;i++)x.push_back(v[i]),vis[i]=1;
   for(int i=n-1;i>=n-3;i--){
    if(!vis[i])x.push_back(v[i]);
   }
   sort(all(x));
   do{
    ans=max(ans,x[0]*x[1]+x[2]*x[2]);
   }while(next_permutation(all(x)));
   cout<<ans;
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