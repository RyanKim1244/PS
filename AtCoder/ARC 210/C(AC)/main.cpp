#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;
int N, M;
vector<int> v, ans;

int f(int i, int k){
    int x = (i < N ? v[i] : 0) + k;
    if(N <= i && x < M) return k;

    int Q = x / 10, R = f(i + 1, Q);
    x -= 10 * (Q - R);

    int A = x / M;
    if(A > 0) {
        while(ans.size() <= i) ans.push_back(0);
        ans[i] += A;
    }
    return min(x - M * A, k);
}

void solve(){
    int i, j;
    cin >> N >> M;
    
    v.resize(N);
    for(i = 0;i < N;i++) cin >> v[i];
    ans.push_back(0);

    f(0, 0);

    string str;
    reverse(ans.begin(), ans.end());
    for(auto element : ans) {
        str.push_back('0' + element);
    }
    cout << str << "\n";
    ans.clear();
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    int T; cin >> T;
    for(i = 1;i <= T;i++) solve();
    return 0;
}