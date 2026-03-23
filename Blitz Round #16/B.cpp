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
 int n;cin>>n;
 if(n%10)rv(cout<<n-1);
 str s=to_string(n);
 for(int i=s.size()-1;i>=0;i--){
    if(s[i]!='0'){
        s[i]--;
        break;
    }
 }
 int val=stoi(s);
 cout<<val;
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