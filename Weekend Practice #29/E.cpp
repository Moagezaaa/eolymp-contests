#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 998244353;
const int INF = 1e9;
 
struct SegmentTree {
    vector<int> tree;
 
    SegmentTree(int n) {
        tree.assign(4 * n, INF);
    }
 
    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = min(tree[node], val);
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2 * node, l, mid, idx, val);
        else update(2 * node + 1, mid + 1, r, idx, val);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
 
    int query_mex(int node, int l, int r, int R) {
        if (tree[node] <= R) return -1;
        if (l == r) return l;
        int mid = (l + r) / 2;
        if (tree[2 * node] > R) return query_mex(2 * node, l, mid, R);
        return query_mex(2 * node + 1, mid + 1, r, R);
    }
};
 
struct Query {
    int l, r, id;
    bool operator<(const Query& other) const {
        return l > other.l;
    }
};
 
void solve() {
    int n, q;
    cin >> n >> q;
 
    int MAX_VAL = min(1 << 19, 4 * n + 20);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
 
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].id = i;
    }
    sort(queries.begin(), queries.end());
 
    SegmentTree st(MAX_VAL);
    vector<int> ans(q);
    int cur_l = n + 1;
 
    for (const auto& qry : queries) {
        while (cur_l > qry.l) {
            cur_l--;
            int val = 0;
            for (int len = 1; len <= 18 && cur_l + len - 1 <= n; len++) {
                val = (val << 1) + a[cur_l + len - 1];
                int v = (1 << len) + val;
                if (v < MAX_VAL) {
                    st.update(1, 2, MAX_VAL - 1, v, cur_l + len - 1);
                }
            }
        }
        ans[qry.id] = st.query_mex(1, 2, MAX_VAL - 1, qry.r) % MOD;
    }
 
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
        
    return 0;
}