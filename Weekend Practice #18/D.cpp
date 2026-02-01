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
const int N = 2e6 + 5;
int n, a[N];
int seg[2 * N];  
int k_value;

void build() {
    for (int i = 0; i < n; i++) {
        seg[n + i] = a[i + 1];
    }
    for (int i = n - 1; i > 0; i--) {
        seg[i] = lcm(seg[i << 1], seg[i << 1 | 1]);
    }
}

int query(int l, int r) {
    l--; r--; 
    l += n;
    r += n;
    int res = 1;
    
    while (l <= r) {
        if (l & 1) res = lcm(res, seg[l++]);
        if (!(r & 1)) res = lcm(res, seg[r--]);
        l >>= 1;
        r >>= 1;
    }
    
    return res;
}

void solve() {
    int k;
    cin >> n >> k;
    k_value = k;
    
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = gcd(x, k);
    }
    
    build();
    
    int ans = 0;
     int i=1,j=1;
    while(j<=n){
        int lcm = query(i, j);
        if (lcm == k) {
            ans += (n - j + 1);
            i++;
        } else {
            j++;
        }
        if(i>j) j=i;
    }
    cout << ans;
}
signed main()
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