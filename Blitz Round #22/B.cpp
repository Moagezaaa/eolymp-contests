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
  vec<str>v(4);
  for(int i=0;i<4;i++)cin>>v[i];
  int ans=0;
  sort(all(v));
  do{
    str temp="";
    for(int i=0;i<4;i++)temp+=v[i];
    int cnt=1;
    for(int i=1;i<temp.size();i++){
        if(temp[i]==temp[i-1])cnt++;
        else{
            ans=max(ans,cnt);
            cnt=1;
        }
    }
    ans=max(ans,cnt);
  }while(next_permutation(all(v)));
    cout<<ans;
}
signed main()
{
   Moageza
    int t = 1;
     cin >> t;    
    while (t--) {
        solve();
        cout << nl;
    }
    return 0;
}