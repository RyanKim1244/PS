#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, s;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j, sum = 0;
    cin >> N >> s;
    for(i = 1;i <= N;i++){
        ll a; cin >> a;
        if(i >= (N + 2) / 2) sum += 2 * a;
        else sum -= 2 * a;
    }
    cout << sum + (N & 1 ? -s : s);
    return 0;
}