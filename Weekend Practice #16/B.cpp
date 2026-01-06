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
//  if(n%2==0)rv(cout<<-1);
 vec<int>ans,res(n);
 for(int i=1;i<=n;i++)ans.push_back(i);
 for(int i=2;i<=n;i+=2){
    res[i-1]=ans.back();
    ans.pop_back();
 }
    for(int i=1;i<=n;i+=2){
        res[i-1]=ans[0];
        ans.erase(ans.begin());
    }
    for(auto x:res)cout<<x<<" ";
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