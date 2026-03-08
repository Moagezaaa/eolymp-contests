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
//////////////////////////////////////////////////////
void solve(){
    int n,k;cin>>n>>k;
    if(k>=n)rv(cout<<-1);
    if(k==0){
        for(int i=1;i<=n;i++)cout<<i<<" ";
        return ;
    }
    if(k==1){
        for(int i=2;i<=n;i++)cout<<i<<" ";
        cout<<1<<" ";
        return ;
    }
    vec<int>ans;
    for(int i=2;i<=n-2;i++)ans.push_back(i);
    reverse(all(ans));
    deque<int>temp;
    temp.push_back(n),temp.push_back(n-1),temp.push_back(1);
    k-=2;
    vec<int>f;
    while(k--){
    f.push_back(ans.back());
    ans.pop_back();
    }
    // reverse(all(ans));
    for(auto i:f)cout<<i<<" ";
    for(auto i:temp)cout<<i<<" ";
    for(auto i:ans)cout<<i<<" ";
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