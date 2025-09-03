#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXN = 2005, INF = 1e18;
ll N, M, A, B;
ll dist[MAXN][MAXN], chk[MAXN], c[MAXN], ans_dist[MAXN];

vector<pair<ll, ll>> graph[MAXN], new_graph[MAXN];

struct Data {
    ll cost, now, turn;

    bool operator<(const Data&r)const {
        return cost > r.cost;
    }
};

void Dijkstra(ll source) {
    ll i, j;
    for (i = 1;i <= N;i++) dist[source][i] = INF, chk[i] = 0;
    dist[source][source] = 0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        auto x = pq.top(); pq.pop();
        ll now = x.second, cost = x.first;

        if (chk[now]) continue;
        chk[now] = 1;

        for (auto t : graph[now]) {
            if (chk[t.first] == 0 && cost + t.second < dist[source][t.first]) {
                dist[source][t.first] = cost + t.second;
                pq.push({dist[source][t.first], t.first});
            }
        }
    }
}

void solve(ll source) {
    ll i, j;
    for (i = 1;i <= N;i++) ans_dist[i] = INF, chk[i] = 0;
    ans_dist[source] = 0;

    priority_queue<Data> pq;
    pq.push({0, source, 0});

    while (!pq.empty()) {
        auto x = pq.top(); pq.pop();
        ll now = x.now, cost = x.cost, turn = x.turn;

        if (chk[now]) continue;
        chk[now] = 1;

        for (auto t : new_graph[now]) {
            if (t.second > A || chk[t.first]) continue;
            if (turn + t.second > A) {
                if ((cost + A + B - turn + t.second) < ans_dist[t.first]) {
                    ans_dist[t.first] = (cost + A + B - turn + t.second);
                    pq.push({ans_dist[t.first], t.first, t.second});
                }
            }else {
                if ((cost + t.second) < ans_dist[t.first]) {
                    ans_dist[t.first] = cost + t.second;
                    pq.push({ans_dist[t.first], t.first, t.second + turn});
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j;
    cin >> N >> M;
    for (i = 1;i <= M;i++) {
        ll a, b, c; cin >> a >> b >> c;

        graph[a].push_back({b, c});
    }
    for (i = 1;i <= N;i++) Dijkstra(i);
    for (i = 1;i <= N;i++) cin >> c[i];

    cin >> A >> B;

    for (i = 1;i <= N;i++) {
        for (j = i + 1;j <= N;j++) {
            if (c[i] == 0 && c[j] == 0) {
                if (dist[i][j] != INF) new_graph[i].push_back({j, dist[i][j]});
                if (dist[j][i] != INF) new_graph[j].push_back({i, dist[j][i]});
            }
        }
    }
    solve(1);

    if (ans_dist[N] == INF) cout << -1;
    else cout << ans_dist[N];
    return 0;
}