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
int n;
vec<int>v;
vec<vec<int>>dp;
int rec(int i,int f){
    if(i==n)return 0;
    int&ret=dp[i][f];
    if(ret!=-1e18)return ret;
    if(f==0){
        ret=max({ret,rec(i+1,f)+v[i],rec(i+1,1)});
    }
    if(f==1){
        ret=max({ret,rec(i+1,f),rec(i+1,2)+v[i]});
    }
    if(f==2){
        ret=max({ret,rec(i+1,f)+v[i]});
    }
    return ret;
}
void solve(){
  cin>>n;
  v.assign(n,0),dp.assign(n+1,vec<int>(5,-1e18));
  for(int i=0;i<n;i++)cin>>v[i];
  cout<<rec(0,0)<<nl;
}
signed main()
{
   Moageza
    int t = 1;
     cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}