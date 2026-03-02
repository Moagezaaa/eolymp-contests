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
   int n,x,mx=0,ans=0;cin>>n>>x;
   vec<int>a(n);
   set<int>s;
   vec<pair<int,int>>v;
   for(int i=0;i<n;i++){
     cin>>a[i];
     mx=max(mx,a[i]);
     s.insert(i);
     v.push_back({a[i],i});
   }
   if(mx>x)rv(cout<<-1);
   sort(all(v));    
    for(int i=0;i<n-1;i++){
    int val=v[i].first,idx=v[i].second,res1=2e9,res2=2e9;
     s.erase(idx);
    auto it=s.upper_bound(idx);
    if(it!=s.end()){
        res1=a[*it];
    }
    if(it!=s.begin()){
        it--;
        res2=a[*it];
    }
    ans+=min(res1,res2)-val;
   }
   ans+=x-mx;
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