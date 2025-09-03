#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;
int N;
int arr[MAXN], chk[MAXN];

vector<int> s, ans, ne[MAXN];
vector<pair<int, int>> v, V;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N;
    for (i = 1;i < N;i++) {
        cin >> arr[i];

        if (arr[i] > arr[i - 1]) {
            s.push_back(i);
        }else if (arr[i] < arr[i - 1]) {
            int t = s.back(); s.pop_back();
            v.push_back({t, i});
        }
    }

    v.push_back({s.back(), N});

    sort(v.begin(), v.end());

    int sz = v.size();
    for (i = 0;i < sz - 1;i++) {
        ans.push_back(v[i].first);
        ans.push_back(v[i + 1].second);
    }
    ans.push_back(v[sz - 1].first); ans.push_back(N);

    int ans_size = ans.size(); chk[N] = 1;
    for (i = 0;i < ans_size - 1;i++) {
        chk[ans[i]] = 1;
        if (ans[i] < ans[i + 1]) V.push_back({ans[i], ans[i + 1]});
    }
    sort(V.begin(), V.end());

    int now = 0;
    for (i = 1;i <= N;i++) {
        if (chk[i]) continue;

        while (V[now].second < i) now++;
        ne[V[now].first].push_back(i);
    }

    for (auto x : ans) {
        cout << x << " ";
        for (auto t : ne[x]) cout << t << " ";
    }
    return 0;
}