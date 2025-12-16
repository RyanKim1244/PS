#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXN = 3e5 + 5;
ll N, Q;
ll D[MAXN], S[MAXN], idx[MAXN], ans[MAXN];
pair<ll, ll> A[MAXN];

struct Data {
    ll x, p, num;

    bool operator<(const Data&r)const {
        return x < r.x;
    }
}query[MAXN];

struct segment {
    pair<ll, ll> tree[4 * MAXN];

    void update(ll node, ll s, ll e, ll k, ll val) {
        ll mid = (s + e) >> 1;
        if (s == e) {
            tree[node] = {val, 1};
            return;
        }
        if (k <= mid) update(node * 2, s, mid, k, val);
        else update(node * 2 + 1, mid + 1, e, k, val);

        tree[node].first = tree[node * 2].first + tree[node * 2 + 1].first;
        tree[node].second = tree[node * 2].second + tree[node * 2 + 1].second;
    }

    pair<ll, ll> query(ll node, ll s, ll e, ll l, ll r) {
        ll mid = (s + e) >> 1;
        if (e < l || r < s) return {0, 0};
        if (l <= s && e <= r) return tree[node];

        auto A = query(node * 2, s, mid, l, r), B = query(node * 2 + 1, mid + 1, e, l, r);

        return {A.first + B.first, A.second + B.second};
    }
}seg;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j;
    cin >> N >> Q;
    for (i = 1;i <= N;i++) {
        cin >> D[i];
        S[i] = S[i - 1] + D[i];

        A[i] = {D[i], i};
    }

    sort(A + 1, A + N + 1);
    for (i = 1;i <= N;i++) idx[A[i].second] = i;

    for (i = 1;i <= Q;i++) cin >> query[i].x >> query[i].p, query[i].num = i;

    sort(query + 1, query + Q + 1);

    ll last = 0;
    for (i = 1;i <= Q;i++) {
        ll X = query[i].x, P = query[i].p, flag = 0;

        for (j = last + 1;j <= X;j++) seg.update(1, 1, N, idx[j], D[j]);
        last = X;

        ll s = 1, e = N;
        while (s < e - 1) {
            ll mid = (s + e) >> 1;
            if (seg.query(1, 1, N, mid, N).first >= P) s = mid;
            else e = mid - 1;
        }

        if (seg.query(1, 1, N, e, N).first >= P) s = e;
        else if (seg.query(1, 1, N, s, N).first < P) flag = 1;

        if (flag) ans[query[i].num] = -1;
        else ans[query[i].num] = seg.query(1, 1, N, s, N).second;
    }
    for (i = 1;i <= Q;i++) cout << ans[i] << "\n";
    return 0;
}