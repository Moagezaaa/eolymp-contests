#include <bits/stdc++.h>
// #define int long long
#define ll long long
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
 int n,m;cin>>n>>m;
 vec<vec<int>>v(n+1,vec<int>(m+1));
 int ans=0;
 for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>v[i][j];
 for(int i=1;i<=m;i++){
    int f=i;
    set<int>st;
    vec<int>val;
    for(int j=1;j<=n;j++){
        val.push_back(v[j][i]),st.insert(f),f+=m;
    }
    bool ok=true;
    for(int j=0;j<val.size();j++){
        if(st.find(val[j])==st.end()){
            ok=false;
            break;
        }
    }
    if(!ok)continue;
    
    for(int j=1;j<val.size();j++){
        if(val[j]<val[j-1]){
            if(val[j]==*st.begin()&&val[j-1]==*st.rbegin()){}
            else {
                ok=false;
                break;
            }
        }
        else {
            if(val[j]-val[j-1]!=m){
                ok=false;
                break;
            }
        }
    }
    if(ok)ans++;
 }
 cout<<ans<<nl;
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