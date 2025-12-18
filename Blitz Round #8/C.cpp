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
int sum(int i){
    return i*(i+1)/2;
}
void solve() {
    int n; cin >> n;
 int l=1,r=1e10,ans=0;
//  cout<<sum(r)<<nl;
 while(l<=r){
     int mid=(l+r)/2;
     if(sum(mid)>=n)r=mid-1,ans=mid;
     else l=mid+1;
 }
 if(sum(ans)==n)rv(cout<<ans<<" "<<ans);
 int res=n-sum(ans-1);
 cout<<ans-1<<" "<<ans-1+res;
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