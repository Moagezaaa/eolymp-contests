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
 int n,c=0;cin>>n;
 vec<int>x(n),y(n);
 vec<pair<int,int>>v;
 map<int,int>mp;
 for(int i=0;i<n;i++){
    cin>>x[i];
    mp[x[i]]++;
    if(mp[x[i]]>1)c=1;
 }
 mp.clear();
 for(int i=0;i<n;i++){
    cin>>y[i];
    mp[y[i]]++;
    if(mp[y[i]]>1)c=1;
    v.push_back({x[i],y[i]});
 }
 if(c)rv(cout<<"NO");
 sort(all(v));
 c=INT_MIN;
 for(int i=0;i<n;i++){
    if(c>v[i].second)rv(cout<<"NO");
    c=v[i].second;
 }
 cout<<"YES";
 
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