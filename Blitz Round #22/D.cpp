#include <bits/stdc++.h>
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
const int MAXA = 1e6 + 5;
int spf[MAXA];

void precompute() {
    for (int i = 1; i < MAXA; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i < MAXA; i++) {
        if (spf[i] == i) { 
            for (int j = i * i; j < MAXA; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    vector<int> freq(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int temp = a[i];
        
        while (temp > 1) {
            int p = spf[temp];
            freq[p]++;
        
            while (temp % p == 0) {
                temp /= p;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) continue; 
        
        int temp = a[i];
        bool can_include = false;
        
        
        while (temp > 1) {
            int p = spf[temp];
            if (freq[p] >= 2) {
                can_include = true;
                break; 
            }
            while (temp % p == 0) {
                temp /= p;
            }
        }
        
        if (can_include) {
            ans++;
        }
    }
    
    cout << ans;
}

signed main()
{
   Moageza
    precompute();
    int t = 1;
    cin >> t;    
    while (t--) {
        solve();
        cout << nl;
    }
    return 0;
}