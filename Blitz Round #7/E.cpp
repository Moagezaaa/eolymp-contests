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
vec<int>sum,v,vis;
vec<vec<int>>adj;
void dfs(int node,int par,int val){
    for(auto it:adj[node]){
        if(it==par)continue;
        dfs(it,node,val);
        if(vis[it]==1){
            sum[it]-=val;
        }
        sum[node]+=min(0LL,sum[it]);
    }
}
void solve()
{
   int n;cin>>n;
  v.assign(n+1,0),vis.assign(n+1,0),adj.assign(n+1,{});;
   for(int i=1;i<=n;i++)cin>>v[i];
   for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    vis[a]++,vis[b]++;
   }
   int mx=0;
   vec<int>ans;
   for(int i=1;i<=n;i++){
    if(vis[i]==1){
        mx=max(mx,v[i]);
        ans.push_back(i);
    }
    else v[i]--;
   }
   int l=0,r=mx,res=0;
   while(l<=r){
    int mid=(l+r)/2;
   sum.assign(n+1,0);
   for(int i=1;i<=n;i++)sum[i]=v[i];
   dfs(1,0,mx-mid);
    // cout<<sum[1]<<" ";
    if(sum[1]<0)l=mid+1;
    else {
        res=mid;
        r=mid-1;
        // cout<<mid<<" ";
    }
   }
   cout<<res;
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