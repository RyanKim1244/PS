#include <bits/stdc++.h>

using namespace std;

int N;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N;

    int ans = 0;
    for(i = 1;i <= N;i++){
        int now = i, sum = 0;

        while(now){
            sum += now % 10;
            now /= 10;
        }
        if(i % sum == 0) ans++;
    }
    cout << ans;
    return 0;
}