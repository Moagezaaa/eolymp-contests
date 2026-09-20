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
bool com(str&x,str&y){
    return x+y>y+x;
}
//////////////////////////////////////////////////////
void solve(){
    while(1){

  int n;cin>>n;
  if(n==0)break;
  vec<str>ans;
  for(int i=0;i<n;i++){
    int x;cin>>x;
    str s=to_string(x);
    ans.push_back(s);
  }
  sort(all(ans),com);
  for(auto it:ans)cout<<it;
  cout<<nl;
    }
}
signed main()
{
   Moageza
    int t = 1;
    //  cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}