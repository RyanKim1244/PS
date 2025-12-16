#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXN = 2005;
ll N, x, y;

struct Data{
    ll x1, x2, y;
}arr[MAXN];

vector<pair<Data, ll>> P;
vector<array<ll, 3>> point;

bool compare(pair<Data, ll> &a, pair<Data, ll> &b){
    ll A = (y - a.first.y) * (x - b.first.x1);
    ll B = (y - b.first.y) * (x - a.first.x1);

    if(A == B) return a.second < b.second;
    return A < B;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j;
    cin >> N;
    for(i = 1;i <= N;i++){
        cin >> arr[i].x1 >> arr[i].x2 >> arr[i].y;

        if(arr[i].x1 > arr[i].x2) swap(arr[i].x1, arr[i].x2);

        point.push_back({arr[i].x1, arr[i].y, arr[i].x2 - arr[i].x1});
        point.push_back({arr[i].x2, arr[i].y, arr[i].x2 - arr[i].x1});
    }

    ll ANS = 0;
    for(i = 0;i < 2 * N;i++){
        x = point[i][0], y = point[i][1];

        for(j = 1;j <= N;j++){
            if(y == arr[j].y) continue;

            if(arr[j].y < y){
                P.push_back({{2 * x - arr[j].x1, 2 * x - arr[j].x2, 2 * y - arr[j].y}, 0});
                P.push_back({{2 * x - arr[j].x2, 2 * x - arr[j].x1, 2 * y - arr[j].y}, 1});
            }else{
                P.push_back({{arr[j].x1, arr[j].x2, arr[j].y}, 1});
                P.push_back({{arr[j].x2, arr[j].x1, arr[j].y}, 0});
            }
        }
        sort(P.begin(), P.end(), compare);

        ll ans = 0, MAX = 0;
        for(auto x : P){
            if(x.second == 0) ans += abs(x.first.x1 - x.first.x2);
            else ans -= abs(x.first.x1 - x.first.x2);

            MAX = max(MAX, ans);
        }
        ANS = max(ANS, MAX + point[i][2]);

        P.clear();
    }
    cout << ANS;
    return 0;
}