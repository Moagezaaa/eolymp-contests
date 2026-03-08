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
       int l, r,p;cin>>l>>r>>p;
    int ans = 0;
    for (int k =0; k*k<=r;++k) {
        int lo =max(l, k * k), hi =min(r, k * k + 2 * k);
        if (lo> hi) continue;
        int del=((k - lo) % p + p) % p, x=lo + del;
        if (x>hi) continue;
        ans += (hi-x)/p+1;
    }
    cout << ans;
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