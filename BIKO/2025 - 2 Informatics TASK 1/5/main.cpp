#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2005;
int arr[2 * MAXN], idx[MAXN];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j, ans = 0;
    int N; cin >> N;
    for(i = 1;i <= 2 * N;i++){
        int a; cin >> a;
        if(idx[a] == 0) idx[a] = i;
        else ans = max(ans, i - idx[a] - 1);
    }
    cout << ans;
}