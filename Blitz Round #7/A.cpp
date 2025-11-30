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
void solve()
{
   int n;cin>>n;
   vec<vec<int>>v(n,vec<int>(n));
   for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>v[i][j];
   if(n==2){
    cout<<max(v[0][0]+v[1][1],v[0][1]+v[1][0]);
    return;
   }
   multiset<int>s;
   int ans1=0,ans2=0;
   for(int i=0;i<n;i++){
    int c=0;
    for(int j=0;j<n;j++)s.insert(v[i][j]);
   }
   while(n--){
       ans1+=*s.rbegin();
       s.erase(s.find(*s.rbegin()));
   }
   cout<<ans1;
}
signed main()
{
    Moageza
     #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << nl;
    }
    return 0;
}