#include <bits/stdc++.h>
#define int long long
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
 int n,q;cin>>n>>q;
 vec<int>v(n+1,0);
 int sum=0;
 for(int i=1;i<=n;i++){
    cin>>v[i];
    v[i]+=v[i-1];
 }
 while(q--){
    int x;cin>>x;
    sum=v.back();
    int rem =x-((x/sum)*sum);
    int ans=x/sum*n;
    int l=0,r=n,idx=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(v[mid]>=rem)r=mid-1,idx=mid;
        else l=mid+1;
    }
    ans+=idx;
    cout<<ans<<" ";
 }
 cout<<nl;
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