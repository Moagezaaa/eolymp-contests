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

int power(int base, int exp) {
    int res = 1;
    for (int i = 0; i < exp; i++) {
        if (res > 2e18 / base) return 2e18 + 1;
        res *= base;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    int ans = n - 1; 
    
    for (int y = 2; y <= 62; y++) {
        int l = 1, r = 1e10;
        while (l <= r) {
            int mid = (l + r) / 2;
            int p = power(mid, y);
            if (p > n) {
                r = mid - 1;
            } else {
                ans = min(ans, abs(n - p) + abs(mid - y));
                l = mid + 1;

                for (int dx = -10; dx <= 10; dx++) {
            int x = mid + dx;
            if (x < 1) continue;
            int p = power(x, y);
            if (p <1e18 +1) {
                ans = min(ans, abs(n - p) + abs(x - y));
            }
        }
        for (int dx = -10; dx <= 10; dx++) {
            int x = y + dx;
            if (x < 1) continue;
            int p = power(x, y);
            if (p < 1e18 +1) {
                ans = min(ans, abs(n - p) + abs(x - y));
            }
        }
            }
        }

        for (int dx = -10; dx <= 10; dx++) {
            int x = r + dx;
            if (x < 1) continue;
            int p = power(x, y);
            if (p <2e18 +1) {
                ans = min(ans, abs(n - p) + abs(x - y));
            }
        }
        for (int dx = -10; dx <= 10; dx++) {
            int x = y + dx;
            if (x < 1) continue;
            int p = power(x, y);
            if (p < 2e18 +1) {
                ans = min(ans, abs(n - p) + abs(x - y));
            }
        }
    }
    
    cout << ans << nl;
}

signed main() {
    Moageza
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}