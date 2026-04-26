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
  int x,y,k;cin>>x>>y>>k;
  if(k==0){
    if(x==y)rv(cout<<"YES");
    else rv(cout<<"NO");
  }
  if(y%x)rv(cout<<"NO");
  if(x==y){
    if(k==0)rv(cout<<"YES");
    else rv(cout<<"NO");
  }
  int f=y/x;
  for(int i=2;i*i<=f;i++){
    while(f%i==0){
      f/=i;
      k--;
    }
  }
  if(f>1)k--;
    if(k<=0)cout<<"YES";
    else cout<<"NO";
  
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