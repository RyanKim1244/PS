#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;
int N;
int arr[MAXN], X[MAXN];
pair<int, int> range[MAXN];

vector<int> v, pos[MAXN];

int DNC(int l, int r){
    int L = l, R = r, cnt = 0;
    if(l >= r) return 1;

    while(L <= R){
        int now;
        if(cnt & 1) now = R--;
        else now = L++;

        if(range[now].first <= l && range[now].second >= r){
            return DNC(l, now - 1) & DNC(now + 1, r);
        }
        cnt++;
    }
    return 0;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j, T;
    cin >> T;
    while(T--){
        cin >> N;
        for(i = 1;i <= N;i++) {
            cin >> arr[i];
            v.push_back(arr[i]);

            pos[i].push_back(0); X[i] = 0;
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        for(i = 1;i <= N;i++){
            arr[i] = (lower_bound(v.begin(), v.end(), arr[i]) - v.begin()) + 1;
            pos[arr[i]].push_back(i);
        }

        for(i = 1;i <= N;i++) pos[i].push_back(N + 1);

        for(i = 1;i <= N;i++){
            ++X[arr[i]];

            range[i].first = pos[arr[i]][X[arr[i]] - 1] + 1;
            range[i].second = pos[arr[i]][X[arr[i]] + 1] - 1;
        }

        if(DNC(1, N)) cout << "non-boring\n";
        else cout << "boring" << "\n";

        for(i = 1;i <= N;i++) pos[i].clear();
        v.clear();
    }
    return 0;
}