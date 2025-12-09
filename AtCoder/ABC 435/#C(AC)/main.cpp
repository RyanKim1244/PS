#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 5;
int arr[MAXN], N;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N;
    for(i = 1;i <= N;i++) cin >> arr[i];

    int M = 1;
    for(i = 1;i <= N;i++){
        if(i > M) break;
        M = max(M, i + arr[i] - 1);
    }
    cout << min(M, N);
    return 0;
}