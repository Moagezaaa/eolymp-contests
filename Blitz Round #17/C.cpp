#include <bits/stdc++.h>
#define ll  int
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
const ll mod = 1e9+7,n=105;
//////////////////////////////////////////////////////
template < typename T = ll, int Base = 0 > struct DSU {
    
    vector < T > parent, Gsize,cost;
    DSU(int MaxNodes){
       cost= parent = Gsize  = vector < T > (MaxNodes + Base);
        for(int i = Base; i < MaxNodes + Base; i++){
            parent[i] = i;
             Gsize[i] = 1;
        }
    }
    
    T find_leader(T i)
    {
        if(parent[i]==i)
        {
            return i;
        }
        return find_leader(parent[i]);
    }
    bool is_same_sets(int u, int v){
        return find_leader(u) == find_leader(v);
    }

    void union_sets(int u, int v){
        int leader_u = find_leader(u), leader_v = find_leader(v);
        if(Gsize[leader_u] < Gsize[leader_v]) 
            swap(leader_u, leader_v);
        if(leader_u == leader_v) return;
        Gsize[leader_u] += Gsize[leader_v];
        cost[leader_v] -= cost[leader_u];
        parent[leader_v] = leader_u;
    }
    int get_size(int u){
        return Gsize[find_leader(u)];
    }
};
// struct edge{
//     int u,v,w;
//     bool operator<(const edge&d)const{
//        return w<d.w;
//     }
//    };
int a,b;
vec<vec<int>>v,vis,ans;
void dfs(int i,int j,int c){
    // cout<<"DFS: "<<i<<" "<<j<<" "<<c<<nl;
   if(i+1<a&&v[i+1][j]!=1){
    if(v[i+1][j]==2){
        if(ans[i+1][j]==-1){
            ans[i+1][j]=0;
            dfs(i+1,j,0);
        }
    }
    else if(ans[i+1][j]==-1||ans[i+1][j]>c+1){
        ans[i+1][j]=c+1;
        dfs(i+1,j,c+1);
    }
   }
   if(j+1<b&&v[i][j+1]!=1){
    if(v[i][j+1]==2){
        if(ans[i][j+1]==-1){
            ans[i][j+1]=0;
            dfs(i,j+1,0);
        }
    }
    else if(ans[i][j+1]==-1||ans[i][j+1]>c+1){
        ans[i][j+1]=c+1;
        dfs(i,j+1,c+1);
    }
}
    if(i-1>=0&&v[i-1][j]!=1){
        // cout<<"DFS: "<<i-1<<" "<<j<<" "<<c+1<<nl;
    if(v[i-1][j]==2){
        if(ans[i-1][j]==-1){
            ans[i-1][j]=0;
            dfs(i-1,j,0);
        }
    }
    else if(ans[i-1][j]==-1||ans[i-1][j]>c+1){
        // cout<<"DFS: "<<i-1<<" "<<j<<" "<<c+1<<nl;
        ans[i-1][j]=c+1;
        dfs(i-1,j,c+1);
    }
   }
    if(j-1>=0&&v[i][j-1]!=1){
    if(v[i][j-1]==2){
        if(ans[i][j-1]==-1){
            ans[i][j-1]=0;
            dfs(i,j-1,0);
        }
    }
    else if(ans[i][j-1]==-1||ans[i][j-1]>c+1){
        ans[i][j-1]=c+1;
        dfs(i,j-1,c+1);
   }
}
}
void solve(){
    cin >> a>>b;
  DSU<ll>d(a*b+5);
 v.assign(a,vec<int>(b)),vis.assign(a,vec<int>(b,0)),ans.assign(a,vec<int>(b,-1));

  int cnt=0;
  for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
        cin>>v[i][j];
        vis[i][j]=++cnt;
    }
  }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(v[i][j]==2&&ans[i][j]==-1){
                ans[i][j]=0;
               dfs(i,j,0);
            }
            if(i+1<a&&v[i][j]!=1&&v[i+1][j]!=1){
                d.union_sets(vis[i][j],vis[i+1][j]);
            }
            if(j+1<b&&v[i][j]!=1&&v[i][j+1]!=1){
                d.union_sets(vis[i][j],vis[i][j+1]);
            }
        }
    }
    int q;cin>>q;
    while(q--){
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        x1--,y1--,x2--,y2--;
        // cout<<"Query: "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" ";
        if(d.is_same_sets(vis[x1][y1],vis[x2][y2])){
            cout<<0;
        }
        else {
            // cout<<ans[x1][y1]<<" "<<ans[x2][y2]<<" ";
            if(ans[x1][y1]==-1||ans[x2][y2]==-1){
                cout<<-1;
            }
            else{
                cout<<ans[x2][y2];
            }
        }
        cout<<nl;
    }
}
int main()
{
   Moageza
    int t = 1;
     cin >> t;
    while (t--) {
        solve();
        // cout << nl;
    }
    return 0;
}