#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[5005];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N >> K;
    for(i = 1;i <= N;i++) cin >> arr[i];

    sort(arr + 1, arr + N + 1);
    reverse(arr + 1, arr + N + 1);

    int sum = 0;
    for(i = 1;i <= K;i++) sum += arr[i];

    cout << sum - K * (K - 1) / 2;
    return 0;
}