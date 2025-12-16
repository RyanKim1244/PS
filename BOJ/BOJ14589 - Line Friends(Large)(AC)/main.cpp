#include <bits/stdc++.h>

using namespace std;

const int MAXN = 150005;
int N;
int to[MAXN], sparse[MAXN][20];
pair<int, int> arr[MAXN];

vector<int> v;

struct segment{
    pair<int, int> tree[8 * MAXN];

    void update(int node, int s, int e, int k, int val, int idx){
        int mid = (s + e) >> 1;
        if(s == e){
            if(tree[node].first <= val) tree[node] = {val, idx};
            return;
        }

        if(k <= mid) update(node * 2, s, mid, k, val, idx);
        else update(node * 2 + 1, mid + 1, e, k, val, idx);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    pair<int, int> query(int node, int s, int e, int l, int r){
        int mid = (s + e) >> 1;
        if(e < l || r < s) return {0, 0};
        if(l <= s && e <= r) return tree[node];

        return max(query(node * 2, s, mid, l, r), query(node * 2 + 1, mid + 1, e, l, r));
    }
}seg;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N;
    for(i = 1;i <= N;i++){
        cin >> arr[i].first >> arr[i].second;

        v.push_back(arr[i].first);
        v.push_back(arr[i].second);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int idx = v.size();
    for(i = 1;i <= N;i++) {
        arr[i].first = (lower_bound(v.begin(), v.end(), arr[i].first) - v.begin()) + 1;
        arr[i].second = (lower_bound(v.begin(), v.end(), arr[i].second) - v.begin()) + 1;

        seg.update(1, 1, idx, arr[i].first, arr[i].second, i);
    }

    for(i = 1;i <= N;i++){
        auto X = seg.query(1, 1, idx, 1, arr[i].second);
        to[i] = X.second; sparse[i][0] = X.second;
    }

    for(i = 1;i < 20;i++){
        for(j = 1;j <= N;j++){
            sparse[j][i] = sparse[sparse[j][i - 1]][i - 1];
        }
    }

    int Q; cin >> Q;
    while(Q--){
        int a, b; cin >> a >> b;

        if(arr[a].first > arr[b].first) swap(a, b);

        if(arr[sparse[a][19]].second < arr[b].first){
            cout << -1 << "\n";
            continue;
        }

        if(arr[a].second >= arr[b].first) {
            cout << 1 << "\n";
            continue;
        }

        int ans = 0;
        for(i = 19;i >= 0;i--){
            if(arr[sparse[a][i]].second < arr[b].first){
                ans += (1 << i);
                a = sparse[a][i];
            }
        }
        cout << ans + 2 << "\n";
    }
    return 0;
}