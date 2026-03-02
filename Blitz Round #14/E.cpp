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
int n,c;
vec<int>l,r;
vec<vec<int>>dp;
vec<int>ans;
int rec(int i,int rem){
  if(i==n)return rem;
  int&ret=dp[i][rem];
  if(~ret)return ret;
  ret=c+1;
  for(int j=l[i];j<=min(r[i],l[i]+c);j++){
    ret=min(ret,rec(i+1,(j*rem)%c));
  }
  return ret;
}
void bulid(int i,int rem){
  if(i==n)return;
  int&ret=dp[i][rem];
  for(int j=l[i];j<=min(r[i],l[i]+c);j++){
    if(ret==rec(i+1,(j*rem)%c)){
      ans.push_back(j);
      bulid(i+1,(j*rem)%c);
      break;
    }
  }
}

void solve(){
  cin>>n>>c;
  ans.clear();
  l.assign(n,0),r.assign(n,0),dp.assign(n,vec<int>(c+1,-1));
  for(int i=0;i<n;i++)cin>>l[i];
  for(int i=0;i<n;i++)cin>>r[i];
  rec(0,1);
  bulid(0,1);
  for(auto i:ans)cout<<i<<" ";
}
signed main()
{
   Moageza
    int t = 1;
     cin >> t;
    while (t--) {
        solve();
        cout <<endl;
    }
    return 0;
}