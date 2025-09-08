#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 5;
int N, K;
int T[MAXN], S[MAXN];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N >> K;
    for(i = 1;i <= N;i++) cin >> T[i];
    for(i = 1;i < N;i++) S[i] = T[i + 1] - T[i] - 1;
    sort(S + 1, S + N);

    int ans = T[N] - T[1] + 1;
    for(i = 1;i < K;i++){
        ans -= S[N - i];
    }
    cout << ans;
    return 0;
}