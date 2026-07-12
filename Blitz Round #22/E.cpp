#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_V = 102;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int>> L(n, vector<int>(MAX_V, -1));
    vector<vector<long long>> dp(n, vector<long long>(MAX_V, 0));
    vector<long long> ans(n, 0);

    for (int i = 0; i < n; i++) {
        L[i][a[i]] = i;

        for (int v = a[i] + 1; v < MAX_V; v++) {
            int right_start = L[i][v - 1];
            if (right_start > 0) {
                int left_start = L[right_start - 1][v - 1];
                if (left_start != -1)
                    L[i][v] = left_start;
            }
        }

        for (int v = 0; v < MAX_V; v++) {
            int start = L[i][v];
            if (start == -1)
                continue;

            if (start == 0) {
                dp[i][v] = (dp[i][v] + 1) % MOD;
            } else {
                // We subtract dp[start-1][v] to ensure no two adjacent blocks are equal.
                long long ways = (ans[start - 1] - dp[start - 1][v] + MOD) % MOD;
                dp[i][v] = (dp[i][v] + ways) % MOD;
            }

            ans[i] = (ans[i] + dp[i][v]) % MOD;
        }
    }

    cout << ans[n - 1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}