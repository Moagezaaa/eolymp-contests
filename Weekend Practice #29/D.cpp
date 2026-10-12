#include <bits/stdc++.h>
using namespace std;

const int MAXA = 10000005;
int min_prime[MAXA], omega[MAXA];
vector<int> primes;

void precompute() {
    omega[1] = 0;
    for (int i = 2; i < MAXA; ++i) {
        if (min_prime[i] == 0) {
            min_prime[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > min_prime[i] || i * p >= MAXA)
                break;
            min_prime[i * p] = p;
        }
        omega[i] = omega[i / min_prime[i]] + 1;
    }
}

inline long long cost(int x, int y) {
    if (y == 1) return 0;
    return omega[y] - omega[gcd(x, y)];
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n + 2, 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += cost(a[i - 1], a[i]);

    while (q--) {
        int idx, x;
        cin >> idx >> x;

        ans -= cost(a[idx - 1], a[idx]);
        if (idx < n)
            ans -= cost(a[idx], a[idx + 1]);

        a[idx] = x;

        ans += cost(a[idx - 1], a[idx]);
        if (idx < n)
            ans += cost(a[idx], a[idx + 1]);

        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    precompute();
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}