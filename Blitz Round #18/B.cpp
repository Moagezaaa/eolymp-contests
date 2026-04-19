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
  vec<int>a(n),b(n);
  int ans=0,mx=0,res=0;
  set<int>s;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
    for(int i=0;i<n;i++){
        cin>>b[i];
      if(b[i]%a[i]==0) s.insert(b[i]/a[i]+1);
       s.insert(b[i]);
    }
    // cout<<res<<" ";
    for(auto it:s){
     bool ok=true;
     res=it;
    for(int i=0;i<n;i++){
        if(a[i]>res&&a[i]*(res-1)>res){
            if(a[i]*(res-1)==b[i])continue;
            ok=false;
            break;
        }
        else{
            if(b[i]==res)continue;
            ok=false;
            break;
        }
    }
    if(ok)rv(cout<<res);
}
cout<<-1;
    
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