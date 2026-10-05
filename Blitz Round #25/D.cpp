#include <bits/stdc++.h>
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
//////////////////////////////////////////////////////
int n;
vec<deque<int>>ans;
vec<vec<int>>dp;
int rec(int i,int j){
    if(i==n)return 0;
    int&ret=dp[i][j];
    if(~ret)return ret;
    ret=1e9;
    if(i){
        for(int k=0;k<ans[i].size();k++){
            if(ans[i][k]>=ans[i-1][j])ret=min(ret,rec(i+1,k)+k);
        }
    }
    else{
        for(int k=0;k<ans[i].size();k++){
            ret=min(ret,rec(i+1,k)+k);
        }
    }
    return ret;
}
void solve(){
  cin>>n;
  ans.assign(n,deque<int>());
  dp.assign(n,vec<int>(20,-1));
  for(int i=0;i<n;i++){
    int x;cin>>x;
    bitset<20>b=x;
    deque<int>d;
    for(int j=0;j<20;j++){
        d.push_back(b[j]);
    }
    while(d.back()==0)d.pop_back();
    // for(int j=0;j<d.size();j++)cout<<d[j]<<" ";
    // cout<<nl;
    for(int j=0;j<d.size();j++){
        if(j)d.push_front(d.back()),d.pop_back();
        int res=0;
        for(int k=0;k<d.size();k++){
            if(d[k])res|=(1<<k);
        }
        ans[i].push_back(res);
    }
  }
//   for(int i=0;i<n;i++){
//     for(auto it:ans[i])cout<<it<<" ";
//     cout<<nl;
//   }
  int res=rec(0,0);
  if(res==1e9)res=-1;
  cout<<res<<nl;
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