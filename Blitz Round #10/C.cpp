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
void solve() {
 int n;cin>>n;
 vec<int> a(n);
    int one=0,two=0,cnt=0,ans=0;
 for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]==1)one++;
    else if(a[i]==2)two++;
    else cnt++;
 }
 for(int i=0;i<n;i++){
   if(a[i]==1)one--;
   else if(a[i]==2)two--;
   else cnt--;
   if(a[i]==1)continue;
   else if(a[i]==2)ans+=cnt;
   else ans+=two+cnt;
 }
    cout<<ans;
}

signed main()
{
    Moageza
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << nl;
    }
    return 0;
}