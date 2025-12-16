#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5, INF = 21e8;
int N, Q;
pair<int, int> arr[MAXN];
vector<int> v;

int graph[MAXN][20];

struct segment{
    int tree[4 * MAXN], number[4 * MAXN];

    void update(int node, int s, int e, int k, int val, int num){
        int mid = (s + e) >> 1;

        if(s == e){
            if(tree[node] > val){
                tree[node] = val;
                number[node] = num;
            }   
            return;
        }

        if(k <= mid) update(node * 2, s, mid, k, val, num);
        else update(node * 2 + 1, mid + 1, e, k, val, num);

        if(tree[node * 2] <= tree[node * 2 + 1]) tree[node] = tree[node * 2], number[node] = number[node * 2];
        else tree[node] = tree[node * 2 + 1], number[node] = number[node * 2 + 1];
    }

    pair<int, int> query(int node, int s, int e, int l, int r){
        int mid = (s + e) >> 1;

        if(e < l || r < s) return {INF, 0};
        if(l <= s && e <= r) return {tree[node], number[node]};

        return min(query(node * 2, s, mid, l, r), query(node * 2 + 1, mid + 1, e, l, r));
    }
}seg;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N >> Q;

    for(i = 0;i < 4 * MAXN;i++) seg.tree[i] = INF;
    
    for(i = 1;i <= N;i++){
        int a, b; cin >> a >> b;

        arr[i] = {a, b};
        v.push_back(a); 
        v.push_back(b);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(i = 1;i <= N;i++){
        arr[i].first = (lower_bound(v.begin(), v.end(), arr[i].first) - v.begin()) + 1;
        arr[i].second = (lower_bound(v.begin(), v.end(), arr[i].second) - v.begin()) + 1;
    }

    for(i = 1;i <= N;i++) seg.update(1, 1, 2 * N, arr[i].second, arr[i].first, i);

    for(i = 1;i <= N;i++){
        auto A = seg.query(1, 1, 2 * N, arr[i].first, arr[i].second);

        graph[i][0] = A.second;
        //cout << i << " : " << A.second << "\n";
    }

    for(i = 1;i < 20;i++){
        for(j = 1;j <= N;j++) graph[j][i] = graph[graph[j][i - 1]][i - 1];
    }

    while(Q--){
        int a, b; cin >> a >> b;
        int ans = 0;

        if(a == b){
            cout << 0 << "\n";
            continue;
        }
        if(arr[b].second < arr[a].second) {
            cout << "impossible\n";
            continue;
        }

        for(i = 19;i >= 0;i--){
            if(arr[a].second < arr[graph[b][i]].first) {
                b = graph[b][i], ans += (1 << i);
            }
        }
        if(arr[b].first > arr[a].second) ans++, b = graph[b][0];
        if(arr[b].first > arr[a].second) cout << "impossible\n";
        else cout << ans + 1 << "\n";
    }
    return 0;
}