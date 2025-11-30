#include <bits/stdc++.h>
// #define int long long
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
   int n,k,res=0;cin>>n>>k;
   vec<int>v(n);
   for(int i=0;i<n;i++)cin>>v[i],res=gcd(res,v[i]);
   sort(all(v));
   if(k==0)rv(cout<<v.back());
   if(k==1)rv(cout<<v.back()+res);
   if(k==2){
   int c=0;
   for(int i=0;i<n;i++){
    vec<int>f=v;
    f[i]+=res;
    int ans=0;
    for(auto it:f)ans=gcd(ans,it);
    vec<int>g=f;
    for(int j=0;j<n;j++){
        g[j]+=ans;
        c=max(c,g[j]);
    }
   }
   cout<<c;
}
else{
int c=0;
   for(int i=0;i<n;i++){
    vec<int>f=v;
    f[i]+=res;
    int ans=0;
    for(auto it:f)ans=gcd(ans,it);
    vec<int>g=f;
    for(int j=0;j<n;j++){
        g[j]+=ans;
        int b=0;
        if(j)g[j-1]-=ans;
        for(auto it:g)b=gcd(b,it);
        for(auto it:g)c=max(c,it+b);
    }
   }
   cout<<c;
}
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