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
 int n,k;cin>>n>>k;
 vec<int> a(n),b(n);
 for(int i=0;i<n;i++) cin>>a[i];
 for(int i=0;i<n;i++) cin>>b[i];
 vec<pair<int,int>> v;
 for(int i=0;i<n;i++){
     v.push_back({a[i],b[i]});
 }
 multiset<int> s;
 int sum=0,ans=0;
 sort(allr(a));
 for(int i=0;i<k;i++)sum+=a[i];
 for(int i=k;i<n;i++)s.insert(a[i]);
 for(int i=0;i<n;i++){
  if(s.count(v[i].first))ans=max(ans,sum*v[i].second);
  else {
    int temp=sum;
    temp-=v[i].first;
    temp+=*s.rbegin();
    ans=max(ans,temp*v[i].second);
  }
 }
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