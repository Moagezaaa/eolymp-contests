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
int C(int x) {
    return (x * (x - 1)) / 2;
}
void solve(){
 int x, y; cin >> x >> y;
     map<int, int> mp;
        for (int i = 1; i < 100000; i++) {
            mp[C(i)] = i;
    }
    
    if (y == 1) {
        for (int i = 1; i <= 2 * sqrt(x) + 2; i++) {
            if (C(i) == x) {
                cout << i << "\n";
                for (int j = 0; j < i; j++) {
                    cout << 1 << " ";
                }
                cout << "\n";
                return;
            }
        }
    }
    
    if (y == 2) {
        for (int c1 = 1; c1 < 100000; c1++) {
            int t = x - C(c1);
            if (t >= 0 && mp.find(t) != mp.end()) {
                int c2 = mp[t];
                cout << c1 + c2 << "\n";
                for (int j = 0; j < c1; j++) cout << 1 << " ";
                for (int j = 0; j < c2; j++) cout << 2 << " ";
                cout << "\n";
                return;
            }
        }
    }
        int l = 1, r = 2000000000;
        int s = r;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (C(m) >= x) {
                s = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        
        int rem = C(s) - x;
        int  c1 = 0, c2 = 0, c3 = 0;
        
        if (rem == 0) {
            c3 = s;
        } else {
            c1 = rem;
            c2 = 1;
            c3 = s - c1 - c2;
        }
        
        cout << c1 + c2 + c3 << "\n";
        for (int i = 0; i < c1; i++) cout << 1 << " ";
        for (int i = 0; i < c2; i++) cout << 2 << " ";
        for (int i = 0; i < c3; i++) cout << 3 << " ";
}
signed main()
{
   Moageza
    int t = 1;
     cin >> t;    
    while (t--) {
        solve();
        // cout << nl;
    }
    return 0;
}