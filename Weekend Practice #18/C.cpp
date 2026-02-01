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
void solve() {
 int n,k;cin>>n>>k;
 map<int,int>mp;
 vec<vec<int>>v(n);
 for(int j=0;j<n;j++){
    int x;cin>>x;
    bool flag=false;
    for(int i=0;i<x;i++){
        int y;cin>>y;
        v[j].push_back(y);
         if(y==k)flag=true;
       if(!flag) mp[y]++;
    }
 }
 int cnt=0;
 while(mp[cnt]) cnt++;
 if(cnt!=k)rv(cout<<"NO");
 else {
    for(int i=0;i<n;i++){
        bool flag=false;
        for(int j=0;j<v[i].size();j++){
              if(v[i][j]==k){
                break;
              }
              mp[v[i][j]]--;
        }
        for(int j=0;j<v[i].size();j++){
           if(v[i][j]<k && !mp[v[i][j]]){
                  flag=true;
           }
          if(v[i][j]==k)break;
        }
         for(int j=0;j<v[i].size();j++){
              if(v[i][j]==k){
                break;
              }
              mp[v[i][j]]++;
        }
        if(!flag)rv(cout<<"YES");
    }
    }
    cout<<"NO";
 }
signed main()
{
   Moageza
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
     cin >> t;
    while (t--) {
        solve();
        cout <<endl;
    }
    return 0;
}