#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N;
string s;

vector<ll> pos;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j;
    cin >> N >> s;
    for(i = 0;i < 2 * N;i++){
        if(s[i] == 'A') pos.push_back(i);
    }

    ll ans = 0;
    ll idx = 0;
    for(i = 0;i < 2 * N;i += 2){
        ans += abs(pos[idx++] - i);
    }

    ll sum = 0; idx = 0;
    for(i = 1;i < 2 * N;i += 2){
        sum += abs(pos[idx++] - i);
    }

    cout << min(sum, ans);
    return 0;
}