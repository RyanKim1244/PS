#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

const ll MAXN = 5e5 + 5;
ll N;
ll S[MAXN], X[MAXN], Y[MAXN];

struct Data{
    ll a, b;

    bool operator<(const Data&r)const{
        return a < r.a;
    }
}arr[MAXN];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j;
    cin >> N;
    for(i = 1;i <= N;i++) cin >> arr[i].a >> arr[i].b;
    sort(arr + 1, arr + N + 1);
    for(i = 1;i <= N;i++) S[i] = S[i - 1] + arr[i].b;

    for(i = 1;i <= N;i++){
        X[i] = S[i] - arr[i].a;
        Y[i] = S[i - 1] - arr[i].a;
    }
    ll Min = Y[1], ans = 0;
    for(i = 1;i <= N;i++){
        Min = min(Min, Y[i]);
        ans = max(ans, X[i] - Min);
    }
    cout << ans;
    return 0;
}