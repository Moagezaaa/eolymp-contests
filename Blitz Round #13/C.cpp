#include <bits/stdc++.h>
using namespace std;

#define vec vector
#define all(x) x.begin(), x.end()
#define Moageza ios::sync_with_stdio(false);cin.tie(nullptr);

void solve(){
    int n;
    cin>>n;

    vec<pair<int,int>> v;
    pair<int,int> cur={0,0};

    for(int i=0;i<n;i++){
        int x;
        cin>>x;

        if(cur.first==0) cur={1,x};
        else if(cur.second==x) cur.first++;
        else{
            v.push_back(cur);
            cur={1,x};
        }
    }
    v.push_back(cur);

    int cnt=0;

    for(int i=1;i+1<v.size();i++){
        if(v[i-1].second==v[i+1].second){
            cnt=max(cnt,
                v[i-1].first+v[i].first+v[i+1].first);
        }
    }

    sort(all(v));

    if(v.size()>=2)
        cnt=max(cnt,
            v.back().first+v[v.size()-2].first);
    else
        cnt=v.back().first;

    cout<<n-cnt;
}

int main(){
    Moageza

    int t;
    cin>>t;

    while(t--){
        solve();
        cout<<'\n';
    }
}