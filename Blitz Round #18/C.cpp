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
int smallest_prime_factor(int x) {
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) return i;
    }
    return x; // x is prime
}

void solve(){
  int a, g, m; cin >> a >> g >> m;
  if(m==1){
      cout<<"YES";
      return;
  }
        if (a % g != 0) {
            cout << "NO";
            return;
        }
        int x = a / g;
        if (x == 1) {
            cout << "YES";
            return;
        }
        int p = smallest_prime_factor(x);
        if (m <= p) cout << "YES";
        else cout << "NO";
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