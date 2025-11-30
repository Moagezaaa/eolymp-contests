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
const int N = 2e5 + 5;
int n, x, a[N], T[N][22], Log[N];
int merge(int a, int b)
{
    return (a | b);
}

void build()
{
    for (int i = 1; i <= n; i++)
        T[i][0] = a[i];

    for (int pw = 1; (1 << pw) <= n; pw++)
    {
        for (int i = 1; i + (1 << pw) - 1 <= n; i++)
            T[i][pw] = merge(T[i][pw - 1], T[i + (1 << (pw - 1))][pw - 1]);
    }
}

int query(int l, int r)
{
    int sz = r - l + 1;
    int pw = Log[sz];
    return merge(T[l][pw], T[r - (1 << pw) + 1][pw]);
}

void preCount()
{
    Log[1] = 0;
    for (int i = 2; i < N; i++)
        Log[i] = Log[i >> 1] + 1;
}

void solve()
{
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build();
    vec<int> ans(n + 5, 0);
    for (int i = 1; i <= n; i++)
    {
        int l = i, r = n, res1 = 0, res2 = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (query(i, mid) < x)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
                if (query(i, mid) == x){
                    res1 = mid;
                }
            }
        }
         l = i, r = n;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (query(i, mid) <=x)
            {
                l = mid + 1;
                if (query(i, mid) == x){
                    res2 = mid;
                }
            }
            else
            {
                r = mid - 1;
            }
        }
      if(res1){
        ans[res1 - i + 1]++;
        ans[res2 - i + 2]--;
      }
    }
    for (int i = 1; i <= n; i++)
    {
        ans[i] += ans[i - 1];
        cout << ans[i] << " ";
    }
}

signed main()
{
    Moageza
    preCount();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << nl;
    }
    return 0;
}