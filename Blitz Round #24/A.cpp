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
void solve(){
 int n;cin>>n;
 vec<int>a(n),b(n);
 int f=0;
 for(int i=0;i<n;i++)cin>>a[i];
 for(int i=0;i<n;i++)cin>>b[i];
 for(int i=0;i<n;i++){
  if(f==a[i])rv(cout<<"Nasser");
  f=a[i];
  if(f==b[i])rv(cout<<"Fady");
  f=b[i];
 }
 cout<<"Tie";
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