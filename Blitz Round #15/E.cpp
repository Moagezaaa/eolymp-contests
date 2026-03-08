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
const int MAXA=100005;
vector<int> divs[MAXA];
int cnt[MAXA],f[MAXA];

void pre(){
    for(int i=1;i<MAXA;i++){
        for(int j=i;j<MAXA;j+=i){
            divs[j].push_back(i);
        }
    }
}

void solve(){
    int n;cin>>n;
    vector<int>used;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        for(int d:divs[x]){
            if(!cnt[d])used.push_back(d);
            cnt[d]++;
        }
    }
    vector<int>cand;
    for(int d:used){
        if(cnt[d]>=2)cand.push_back(d);
    }
    sort(cand.rbegin(),cand.rend());
    int ans=0;
    for(int d:cand)f[d]=(cnt[d]*(cnt[d]-1))/2;
    for(int m:cand){
        if(f[m]>0){
            ans++;
            for(int d:divs[m]){
                if(d!=m&&cnt[d]>=2)f[d]-=f[m];
            }
        }
    }
    cout<<ans;
    for(int d:used){
        cnt[d]=0;
        f[d]=0;
    }
}

signed main()
{
   Moageza
        pre();
    int t = 1;
     cin >> t;
    while (t--) {
        solve();
        cout << nl;
    }
    return 0;
}