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
const int MOD = 998244353;
vec<int> primes;

void sieve(int n) {
    vec<bool> is_prime(n+1, true);
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i*i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

vec<pair<int,int>> factorize(int x) {
    vec<pair<int,int>> res;
    for (int p : primes) {
        if (p * p > x) break;
        if (x % p == 0) {
            int e = 0;
            while (x % p == 0) {
                x /= p;
                e++;
            }
            res.push_back({p, e});
        }
    }
    if (x > 1) {
        res.push_back({x, 1});
    }
    return res;
}

void solve() {
    int n, k;  cin >> n >> k;
    vec<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vec<vec<int>> ways(n, vec<int>(k+1, 0));
    
    for (int i = 0; i < n; i++) {
        auto factors = factorize(a[i]);
        vec<int> exps;
        for (auto& [p, e] : factors) exps.push_back(e);
        
        vec<int> dp_cur(k+1, 0);
        dp_cur[0] = 1;
        for (int e : exps) {
            vec<int> dp_next(k+1, 0);
            for (int ops = 0; ops <= k; ops++) {
                if (dp_cur[ops] == 0) continue;
                for (int f = 0; f <= e; f++) {
                    int new_ops = ops + (e - f);
                    if (new_ops <= k) {
                        dp_next[new_ops] = (dp_next[new_ops] + dp_cur[ops]) % MOD;
                    }
                }
            }
            dp_cur = move(dp_next);
        }
        ways[i] = dp_cur;
    }
    
    vec<vec<int>> dp(n+1, vec<int>(k+1, 0));
    dp[0][0] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int op = 0; op <= k; op++) {
            if (dp[i][op] == 0) continue;
            for (int t = 0; t <= k - op; t++) {
                if (ways[i][t] == 0) continue;
                dp[i+1][op + t] = (dp[i+1][op + t] +  dp[i][op] * ways[i][t]) % MOD;
            }
        }
    }
    
    int ans = 0;
    for (int op = 0; op <= k; op++) {
        ans += dp[n][op];
        if(ans>=MOD)ans-=MOD;
    }
    cout << ans ;
}
signed main()
{
   Moageza
   sieve(1000);
    int t = 1;
     cin >> t;
    while (t--) {
        solve();
        cout << nl;
    }
    return 0;
}