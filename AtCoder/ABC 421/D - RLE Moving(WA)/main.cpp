#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1e18;
ll N, M, L;
ll rt, ct, ra, ca;
ll dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

vector<pair<ll, ll>> t, a;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j;
    cin >> rt >> ct >> ra >> ca;
    cin >> N >> M >> L;

    for(i = 1;i <= M;i++){
        char c; ll A; cin >> c >> A;

        ll type;
        if(c == 'U') type = 0;
        else if(c == 'R') type = 1;
        else if(c == 'D') type = 2;
        else type = 3;
        t.push_back({type, A});
    }

    for(i = 1;i <= L;i++){
        char c; ll A; cin >> c >> A;

        ll type;
        if(c == 'U') type = 0;
        else if(c == 'R') type = 1;
        else if(c == 'D') type = 2;
        else type = 3;
        a.push_back({type, A});
    }

    ll idx1 = 0, idx2 = 0, ans = 0;

    while(1){
        ll T;
        if(t[idx1].second < a[idx2].second) T = t[idx1].second;
        else T = a[idx2].second;

        t[idx1].second -= T;
        a[idx2].second -= T;

        ll type1 = t[idx1].first, type2 = a[idx2].first;

        if(t[idx1].first == a[idx2].first) {
            if(rt == ra && ct == ca) ans += T;
        }
        else if(abs(t[idx1].first - a[idx2].first) != 2){
            ll c1x = INF, c1y = INF, c2x = INF, c2y = INF;
            if(type1 == 0 || type1 == 2) c1y = ct;
            else c1x = rt;

            if(type2 == 0 || type2 == 2) c2y = ca;
            else c2x = ra;

            pair<ll, ll> cross;
            if(c1x == INF) cross.first = c2x;
            else cross.first = c1x;

            if(c1y == INF) cross.second = c2y;
            else cross.second = c1y;

            if((abs(cross.first - rt) + abs(cross.second - ct)) == abs(cross.first - ra) + abs(cross.second - ca)){
                ll dist = abs(cross.first - rt) + abs(cross.second - ct);

                if (dist <= T) {
                    pair<ll, ll> cross1, cross2;

                    cross1 = {rt + dx[type1] * dist, ct + dy[type1] * dist};
                    cross2 = {ra + dx[type2] * dist, ca + dy[type2] * dist};

                    if(cross1 == cross2 && cross2 == cross) ans++;
                }
            }
        }
        else {
            if (!(rt == ra && ct == ca)) {
                ll dist = abs(rt - ra) + abs(ct - ca);
                if (dist % 2 == 0) {
                    dist /= 2;

                    if (dist <= T) if (rt + dx[type1] * dist == ra + dx[type2] * dist && ct + dy[type1] * dist == ca + dy[type2] * dist) ans++;
                }
            }
        }
        rt = rt + dx[type1] * T; ct = ct + dy[type1] * T;
        ra = ra + dx[type2] * T; ca = ca + dy[type2] * T;

        if(t[idx1].second == 0) idx1++;
        if(a[idx2].second == 0) idx2++;

        if(idx1 == M && idx2 == L) break;
    }
    cout << ans;
    return 0;
}