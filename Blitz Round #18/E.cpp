#include <bits/stdc++.h>
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
const int N = 2e5 + 5;
int n, k, a[N], T[N][22], Log[N];
int merge(int a, int b)
{
    return (a | b);
}

void build()
{
    for (int i = 1; i <= n; i++)
        T[i][0] = a[i];

    for (int pw = 1; (1 << pw) <= n; pw++)
    {
        for (int i = 1; i + (1 << pw) - 1 <= n; i++)
            T[i][pw] = merge(T[i][pw - 1], T[i + (1 << (pw - 1))][pw - 1]);
    }
}

int query(int l, int r)
{
    int sz = r - l + 1;
    int pw = Log[sz];
    return merge(T[l][pw], T[r - (1 << pw) + 1][pw]);
}

void preCount()
{
    Log[1] = 0;
    for (int i = 2; i < N; i++)
        Log[i] = Log[i >> 1] + 1;
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vec<int>sum(n+1,0);
    for(int i=1;i<=n;i++){
        bitset<30>f=a[i],s=k;
        bool check=false;
        for(int j=0;j<30;j++){
            if(f[j]&&!s[j])check=true;
        }
        if(check){
            a[i]=0;
            sum[i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        sum[i]+=sum[i-1];
    }
    build();
    int ans=1e9,len=0;
    for(int i=1;i<=n;i++){
        int l=i,r=n;
        while(l<=r){
           int mid=(l+r)/2;
           if(query(i,mid)==k){
           r=mid-1;
           ans=min(ans,sum[mid]-sum[i-1]);
           }
           else l=mid+1;
        }
    }
    if(ans==1e9)rv(cout<<"-1 -1");
    for(int i=1;i<=n;i++){
        int l=i,r=n;
        while(l<=r){
           int mid=(l+r)/2;
           if(sum[mid]-sum[i-1]<=ans){
            l=mid+1;
           if(query(i,mid)==k) len=max(len,(mid-i+1)-(ans));
           }
              else r=mid-1;
        }
    }
    cout<<ans<<" "<<len;
}

signed main()
{
    Moageza
    preCount();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << nl;
    }
    return 0;
}