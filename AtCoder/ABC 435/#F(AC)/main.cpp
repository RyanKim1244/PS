#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXN = 2e5 + 5;
ll N;
ll arr[MAXN], idx[MAXN], cost[MAXN];

vector<pair<ll, ll>> graph[MAXN];

struct segment{
    ll tree[4 * MAXN], index[4 * MAXN];

    void update(ll node, ll s, ll e, ll k, ll val){
        ll mid = (s + e) >> 1;
        if(s == e){
            tree[node] = val;
            index[node] = k;
            return;
        }
        if(k <= mid) update(node * 2, s, mid, k, val);
        else update(node * 2 + 1, mid + 1, e, k, val);

        if(tree[node * 2] < tree[node * 2 + 1]) tree[node] = tree[node * 2 + 1], index[node] = index[node * 2 + 1];
        else tree[node] = tree[node * 2], index[node] = index[node * 2];
    }

    pair<ll, ll> query(ll node, ll s, ll e, ll l, ll r){
        ll mid = (s + e) >> 1;
        if(e < l || r < s || l > r) return {0, 0};
        if(l <= s && e <= r) return {tree[node], index[node]};
        return max(query(node * 2, s, mid, l, r), query(node * 2 + 1, mid + 1, e, l, r));
    }
}seg;

void solve(ll l, ll r){
    if(l > r) return;
    auto X = seg.query(1, 1, N, l, r);

    auto X1 = seg.query(1, 1, N, l, X.second - 1);
    auto X2 = seg.query(1, 1, N, X.second + 1, r);

    if(X1.second != 0) graph[X.first].push_back({X1.first, abs(X.second - X1.second)});
    if(X2.second != 0) graph[X.first].push_back({X2.first, abs(X.second - X2.second)});

    if(l == r) return;

    solve(l, X.second - 1);
    solve(X.second + 1, r);
}

void DFS(ll x){
    for(auto element : graph[x]){
        cost[element.first] = cost[x] + element.second;
        DFS(element.first);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j;
    cin >> N;
    for(i = 1;i <= N;i++) {
        cin >> arr[i], idx[arr[i]] = i;
        
        seg.update(1, 1, N, i, arr[i]);
    }

    solve(1, N);
    DFS(N);

    ll ans = 0;
    for(i = 1;i <= N;i++) ans = max(ans, cost[i]);
    cout << ans;
    return 0;
}
