#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXN = 4e5 + 5;
ll N, Q, found, numbering;
ll S[MAXN], num[MAXN], rev_num[MAXN], chk[MAXN], depth[MAXN], top[MAXN], Q_type[MAXN];
pair<ll, ll> scenario[MAXN];

vector<ll> LIST, pos;
vector<pair<ll, ll>> graph[MAXN], path, Query;

void DFS(ll node, ll before) {
    if (node == N) {
        found = 1;
        return;
    }
    for (auto x : graph[node]) {
        if (x.first == before) continue;

        path.push_back(x);
        DFS(x.first, node);
        if (found) return;

        path.pop_back();
    }
}

void DFS2(ll node, ll T, ll cost) {
    depth[node] = cost; top[node] = T;
    chk[node] = 1;

    for (auto x : graph[node]) {
        if (chk[x.first]) continue;
        DFS2(x.first, T, cost + x.second);
    }
}

struct segment {
    ll tree[8 * MAXN], lazy[8 * MAXN];

    void Lazy(ll node, ll s, ll e) {
        if (lazy[node] == 0) return;

        tree[node] += lazy[node];
        if (s != e) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    void update(ll node, ll s, ll e, ll l, ll r, ll v) {
        ll mid = (s + e) >> 1;
        Lazy(node, s, e);
        if (e < l || r < s || l > r) return;

        if (l <= s && e <= r) {
            lazy[node] += v;
            Lazy(node, s, e);
            return;
        }

        update(node * 2, s, mid, l, r, v);
        update(node * 2 + 1, mid + 1, e, l, r, v);

        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
}seg;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j;
    cin >> N >> Q;
    for (i = 1;i < N;i++) {
        ll a, b, c; cin >> a >> b >> c;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    DFS(1, 0);

    numbering = 1; chk[1] = 1; num[1] = 1;

    LIST.push_back(1);
    for (auto x : path) {
        num[x.first] = ++numbering; rev_num[numbering] = x.first;
        S[numbering] = S[numbering - 1] + x.second;

        chk[x.first] = 1;
        LIST.push_back(x.first);
    }

    for (auto x : LIST) DFS2(x, x, 0);

    ll turn = 0;
    while (Q--) {
        ++turn;

        ll a; cin >> a;
        if (a == 1) {
            ll A, B; cin >> A >> B;

            scenario[turn] = {A, B};

            ll D = max(0LL, B - depth[A]);
            ll now = num[top[A]];

            pair<ll, ll> range = {max(0LL, S[now] - D) + 1, min(S[numbering], S[now] + D)};

            if (range.second == 0) pos.push_back(range.first);
            else { pos.push_back(range.first); pos.push_back(range.second); }
            Query.push_back(range);

            Q_type[turn] = 1;
        }else {
            ll c; cin >> c;
            ll A = scenario[c].first, B = scenario[c].second;

            ll D = max(0LL, B - depth[A]);
            ll now = num[top[A]];

            pair<ll, ll> range = {max(0LL, S[now] - D) + 1, min(S[numbering], S[now] + D)};

            if (range.second == 0) pos.push_back(range.first);
            else { pos.push_back(range.first); pos.push_back(range.second); }
            Query.push_back(range);

            Q_type[turn] = 2;
        }
    }
    pos.push_back(1); pos.push_back(S[numbering]);

    sort(pos.begin(), pos.end());

    ll sz = pos.size();

    vector<ll> v;
    for (i = 0;i < sz - 1;i++) {
        if (pos[i] + 1 < pos[i + 1]) v.push_back(pos[i] + 1);
    }

    for (auto x : v) pos.push_back(x);

    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());

    for (i = 0;i < turn;i++) {
        if (Query[i].first <= Query[i].second) {
            ll l = (lower_bound(pos.begin(), pos.end(), Query[i].first) - pos.begin()) + 1;
            ll r = (lower_bound(pos.begin(), pos.end(), Query[i].second) - pos.begin()) + 1;

            if (Q_type[i + 1] == 1) seg.update(1, 1, pos.size(), l, r, 1);
            else seg.update(1, 1, pos.size(), l, r, -1);
        }

        seg.Lazy(1, 1, pos.size());
        if (seg.tree[1] > 0) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}