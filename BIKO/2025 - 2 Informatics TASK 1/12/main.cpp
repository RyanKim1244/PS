#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXN = 1e5 + 5;
ll N;
pair<ll, ll> arr[MAXN];

vector<ll> pos[MAXN];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j;
    cin >> N;
    for(i = 1;i <= N;i++) cin >> arr[i].first >> arr[i].second;

    sort(arr + 1, arr + N + 1);

    for(i = 1;i <= N;i++) pos[arr[i].second].push_back(arr[i].first);

    ll ans = 0;
    for(i = 1;i <= N;i++){
        if(pos[i].size() <= 1) continue;

        ll sz = pos[i].size(), mn = 1e18;
        for(j = 0;j < sz;j++){
            if(j == 0) ans += (pos[i][j + 1] - pos[i][j]);
            else if(j == sz - 1) ans += (pos[i][j] - pos[i][j - 1]);
            else ans += min(pos[i][j + 1] - pos[i][j], pos[i][j] - pos[i][j - 1]);
        }
    }
    cout << ans;
    return 0;
}