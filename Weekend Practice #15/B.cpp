#include <bits/stdc++.h>
#define ll long long int
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
const ll mod = 1e9+7;
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
    return (x&y);
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
            return -1;
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
void solve(){
    int n;cin>>n;
    SegmentTree seg(n);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        seg.update(i,x);
    }
   int sum=0;
    for(int i=0;i<n;i++){
        int l=i,r=n-1;
        while(l<=r){
            int m=(l+r)/2;
            if(seg.query(i,m)>=m-i+1){
               if(seg.query(i,m)==m-i+1) sum++;
                l=m+1;
            }
            else{
                r=m-1;
            }
        }

    }
    cout<<sum;
}
int main()
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