#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXN = 2e5 + 5;
ll N, M, Q;
ll sum_ans;
pair<ll, ll> arr[MAXN];

multiset<ll> s[MAXN], ans, non_ans;

void ANSWER(){
    if(non_ans.empty()) {
        cout << sum_ans << "\n";
        return;
    }

    if(*ans.begin() >= *prev(non_ans.end())) cout << sum_ans << "\n";
    else cout << sum_ans - *ans.begin() + *prev(non_ans.end()) << "\n";
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j;
    cin >> N >> M >> Q;

    for(i = 1;i <= N;i++){
        ll a, b; cin >> a >> b;

        s[a].insert(b);
        arr[i] = {a, b};
    }
    for(i = 1;i <= M;i++){
        ll cnt = 0;
        for(auto x : s[i]){
            cnt++;
            if(cnt == s[i].size()) break;

            non_ans.insert(x);
        }
        ans.insert(*prev(s[i].end()));
        sum_ans += *prev(s[i].end());
    }

    ANSWER();
    while(Q--){
        ll c; cin >> c;
        ll a, b; cin >> a >> b;

        ll pr, pr_val, ne, ne_val;

        if(c == 1){
            pr = arr[a].first, pr_val = arr[a].second;
            ne = b, ne_val = arr[a].second;

            arr[a].first = b;
        }
        else {
            pr = arr[a].first, pr_val = arr[a].second;
            ne = arr[a].first, ne_val = b;

            arr[a].second = b;
        }

        // 원래 있던거 없애는 과정
        if(*prev(s[pr].end()) == pr_val) {
            auto iter = ans.lower_bound(pr_val);
            ans.erase(iter); sum_ans -= pr_val;

            if(s[pr].size() > 1) {
                ll A = *prev(prev(s[pr].end()));
                iter = non_ans.lower_bound(A); non_ans.erase(iter);
                ans.insert(A); sum_ans += A;
            }
        }else{
            auto iter = non_ans.lower_bound(pr_val);
            non_ans.erase(iter);
        }
        auto iter = s[pr].lower_bound(pr_val); s[pr].erase(iter);

        // 새로 추가하는 과정

        if(s[ne].empty()) {
            ans.insert(ne_val); sum_ans += ne_val;
            s[ne].insert(ne_val);
            ANSWER();
            continue;
        }

        if(*prev(s[ne].end()) < ne_val){
            ll A = *prev(s[ne].end()); sum_ans -= A;
            iter = ans.lower_bound(A); ans.erase(iter);
            non_ans.insert(A); 

            ans.insert(ne_val); sum_ans += ne_val;
        }else{
            non_ans.insert(ne_val);
        }
        s[ne].insert(ne_val);

        ANSWER();
    }
    return 0;
}