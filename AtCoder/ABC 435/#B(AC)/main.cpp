#include <bits/stdc++.h>

using namespace std;

int A[55], ans;

int main(void){
    int i, j, N; cin >> N;
    for(i = 1;i <= N;i++) cin >> A[i];

    for(i = 1;i <= N;i++){
        for(j = i;j <= N;j++){
            int sum = 0;
            for(int k = i;k <= j;k++) sum += A[k];

            int chk = 0;
            for(int k = i;k <= j;k++){
                if(sum % A[k] == 0) chk = 1;
            }
            if(chk == 0) ans++;
        }
    }
    cout << ans;
    return 0;
}