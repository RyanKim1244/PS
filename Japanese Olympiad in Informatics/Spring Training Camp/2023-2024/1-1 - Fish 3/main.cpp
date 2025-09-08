#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXN = 3e5 + 5;
ll N, D;
ll arr[MAXN], S[MAXN];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j;
    cin >> N >> D;
    for(i = 1;i <= N;i++) {
        cin >> arr[i];
        S[i] = S[i - 1] + arr[i];
    }

    for(i = 1;i <= N;i++){
        
    }

    ll Q;
    cin >> Q;
    while(Q--){
        int l, r; cin >> l >> r;
        
        
    }
    return 0;
}

// observation 1 : D 만큼 빼서 주어진 구간을 오름차순으로 만들어야 함.
// subtask 1 : greedy하게 구간 뒤에서부터 보면서 오름차순이 되도록 적절히 D를 빼면 됨.

// subtask 3 : D = 1, 어떤 지점의 물고기에서 왼쪽에 있는 물고기 중 자신보다 작은 것 중 가장 오른쪽으로 간선을 제작.
// subtask 3 : 각각의 쿼리에 대해 sparse table로 구할 수 있음.

// subtask 4 : 