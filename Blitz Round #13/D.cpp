//author : MOAGEZA
#include <bits/stdc++.h>
#define ll long long
#define Moageza ios::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

const int N=1e6+5,base1=127,base2=131;
const int mod1=1e9+7,mod2=2e9+11;

int n,pw1[N],pw2[N];
pair<int,int>pre[N],suf[N];

void init(){
    pw1[0]=pw2[0]=1;
    for(int i=1;i<N;i++){
        pw1[i]=(1LL*pw1[i-1]*base1)%mod1;
        pw2[i]=(1LL*pw2[i-1]*base2)%mod2;
    }
}

void Hash(string&s,pair<int,int>arr[]){
    int a=0,b=0;
    for(int i=0;i<s.size();i++){
        a=(1LL*a*base1+s[i])%mod1;
        b=(1LL*b*base2+s[i])%mod2;
        arr[i]={a,b};
    }
}

pair<int,int>get(int l,int r,pair<int,int>arr[]){
    auto ret=arr[r];
    int sz=r-l+1;
    if(l>0){
        ret.first=(ret.first-1LL*arr[l-1].first*pw1[sz]%mod1+mod1)%mod1;
        ret.second=(ret.second-1LL*arr[l-1].second*pw2[sz]%mod2+mod2)%mod2;
    }
    return ret;
}

bool pal(int l,int r){
    return get(l,r,pre)==get(n-r-1,n-l-1,suf);
}

void solve(){
    cin>>n;
    string s;cin>>s;

    Hash(s,pre);
    reverse(s.begin(),s.end());
    Hash(s,suf);
    reverse(s.begin(),s.end());

    if(pal(0,n-1)){
        cout<<0;
        return;
    }

    int ans=-1;

    // left shifts
    for(int i=1;i<(n+1)/2;i++){
        if(pal(2*i,n-1)&&get(n-i,n-1,suf)==get(i,2*i-1,pre)){
            ans=i;
            break;
        }
    }

    // right shifts
    reverse(s.begin(),s.end());
    Hash(s,pre);
    reverse(s.begin(),s.end());
    Hash(s,suf);

    for(int i=1;i<(n+1)/2;i++){
        if(pal(2*i,n-1)&&get(n-i,n-1,suf)==get(i,2*i-1,pre)){
            if(ans==-1||i<ans) ans=i;
            break;
        }
    }

    cout<<ans;
}

int main(){
    Moageza
    init();

    int t;cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
}