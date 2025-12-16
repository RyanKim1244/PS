#include <bits/stdc++.h>

using namespace std;

int n;
int arr[105], chk[105];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j, T;
    cin >> T;
    while(T--){
        cin >> n;
        for(i = 1;i <= n;i++) cin >> arr[i], chk[i] = 0;

        for(i = 1;i <= n;i++){
            for(j = i + 1;j <= n;j++){
                if(arr[i] > arr[j]) chk[j] = 1;
            }
        }

        int cnt = 0;
        for(i = 1;i <= n;i++) cnt += chk[i];
        cout << cnt << "\n";
    }
    return 0;
}