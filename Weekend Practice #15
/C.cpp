#include <bits/stdc++.h>
#define ll long long
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
struct SegmentTree{
private:
#define L 2*node+1
#define R 2*node+2
#define mid (l+r>>1)
// struct Node{
//         ll pre,suf,mx,sum;
//         Node():pre(0),suf(0),sum(0),mx(0){}
//         Node(ll val):pre(max(0LL,val)),suf(max(0LL,val)),sum(val),mx(max(0LL,val)){}
//     };
//     vector<Node>seg;ll sz;
//     Node merge(Node &a,Node b)
//     {
//         Node ret;
//         ret.sum=a.sum+b.sum;
//         ret.pre=max(a.pre,a.sum+b.pre);
//         ret.suf=max(b.suf,b.sum+a.suf);
//         ret.mx=max({ret.sum,a.mx,b.mx,a.suf+b.pre});
//         return ret;
//     }
  ll merge(ll x,ll y){
    return x+y;
  }
    int sz;vector<ll>seg;
    void update(int l,int r,int node,int idx,ll val)
    {
        if(l==r)
        {
            seg[node]=val;
            return;
        }
        if(idx<=mid)
        {
            update(l,mid,L,idx,val);
        }
        else
        {
            update(mid+1,r,R,idx,val);
        }
        seg[node]=merge(seg[L],seg[R]);
    }
    ll query(int l,int r,int node,int lq,int rq)
    {
        if(r<lq||l>rq)
        {
            return 0;
        }
        if(l>=lq&&r<=rq)
        {
            return seg[node];
        }
        ll lft=query(l,mid,L,lq,rq);
        ll rgt=query(mid+1,r,R,lq,rq);
        return merge(lft,rgt);
    }
public:
    SegmentTree(int n)
    {
        sz=1;
        while(sz<n) sz*=2;
        seg=vector<ll>(sz*2);
    }
    void update(int idx,ll val)
    {
        update(0,sz-1,0,idx,val);
    }
    ll query(int l,int r)
    {
        return query(0,sz-1,0,l,r);
    }
};
void solve() {
 int n,z=0,res=0,f=0;cin>>n;
 SegmentTree seg(n+1);
 vec<int>a(n),b(n),ans(n);
 map<int,vec<int>>k;
 for(int i=0;i<n;i++)cin>>a[i];
 for(int i=0;i<n;i++){
     cin>>b[i];
     if(a[i]==b[i])z++,seg.update(i,1);
     ans[i]=b[i]-a[i];
    if(ans[i]) k[ans[i]].push_back(i);
 }
 int h=z;
 res=z;
 map<int,int>mp;
 for(int i=0;i<n;i++){
    if(ans[i]){
        mp[ans[i]]++;
        f=max(f,mp[ans[i]]);
    }
    else h--;
    res=max(res,h+f);
 }
 mp.clear(),h=z,f=0;
 for(int i=n-1;i>=0;i--){
     if(ans[i]){
         mp[ans[i]]++;
         f=max(f,mp[ans[i]]);
     }
     else h--;
     res=max(res,h+f);
 }
 
 for(auto it:k){
     vec<int>t=it.second;
     int w=1;
     res=max(res,z+1);
   for(int i=0;i<t.size()-1;i++){
       if(seg.query(t[0],t[i+1])>w){
        w=1;
        t[0]=t[i+1];
       }
       else w++;
       res=max(res,seg.query(0,t[0])+w+seg.query(t[i+1],n));
    //    w=max(w,1LL);
   }
 }
 cout<<res;
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