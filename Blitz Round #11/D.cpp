#include <bits/stdc++.h>
// #define int long long
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
map<int, int> mp;
int len ;
int primefactor(int num){
  int ans = 0;
  while (num%2==0)
  {
    num/=2;
    ans++;
  }
  for (int i = 3; i <= sqrt(num); i+=2)
  {
    while (num%i==0)
    {
      num/=i;
      ans++;
    }
  }
  if(num>1)ans++;
  return ans;
  
}
int rec(int n,int cnt){
    len=max(len,cnt);
    // cout<<n<<" ";
    if(n==1){
        return 1;
    }
    if(mp.find(n)!=mp.end()){
        return mp[n];
    }
    int&ret=mp[n];
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
           if(primefactor(i)==1){
                ret += rec(n/i,cnt+1);
           }
            if(i!=n/i && primefactor(n/i)==1){
                ret += rec(i,cnt+1);
            }
        }
    }
    return ret;
}
void solve()
{
  int n;cin>>n;
  if(n==1)rv(cout<<1<<" "<<1);
  mp.clear();
  len=0;
  cout<<rec(n,1)<<" "<<len;
}
signed main()
{
    Moageza
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << nl;
    }
    return 0;
}