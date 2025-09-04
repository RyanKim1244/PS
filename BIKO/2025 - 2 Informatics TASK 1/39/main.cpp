#include <bits/stdc++.h>

using namespace std;

int N, ans = 21e8;
int arr[505];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N;
    for(i = 1;i <= N;i++) cin >> arr[i];

    for(i = 1;i <= N;i++){
        for(j = i + 1;j <= N;j++){
            int len = j - i;
            if((arr[j] - arr[i]) % len != 0) continue;

            int d = (arr[j] - arr[i]) / len;

            int cnt = 0;
            for(int k = 1;k <= N;k++){
                if(arr[j] + (k - j) * d != arr[k]) cnt++;
            }
            ans = min(ans, cnt);
        }
    }
    cout << ans;
    return 0;
}