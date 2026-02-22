#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int mx = max({a,b,c,7-(a+b+c)});
    if(mx>=5) cout<<"YES";
    else cout<<"NO";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
}