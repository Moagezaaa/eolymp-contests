                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  #include <bits/stdc++.h>
#define ll long long 
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
// const ll mod = 1e9+7,n=105;
//////////////////////////////////////////////////////
const int MAX = 1e7 + 1,mod=1e9+7;
vector<bool> is_prime(MAX, true);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < MAX; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
void solve(){
  int n,k,cnt=0,check=1;cin>>n>>k;
  ll ans=1;
  for(int i=0;i<n;i++){
    int x;cin>>x;
    if(!is_prime[x]){
      if(cnt==k)check++;
    }
    else{
      if(cnt==k){
        ans=ans*check,check=1,cnt=0;
        ans%=mod;
      }
      cnt++;
    }
  }
  if(cnt!=k)rv(cout<<0);
        cout<<ans;
}
signed main()
{
   Moageza
  sieve();
    int t = 1;
     cin >> t;
    while (t--) {
        solve();
        cout << nl;
    }
    return 0;
}