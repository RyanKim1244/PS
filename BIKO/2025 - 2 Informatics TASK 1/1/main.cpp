#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 5;
int N;
int arr[MAXN];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j, flag = 0;
    cin >> N;
    for(i = 1;i <= N;i++) {
        cin >> arr[i];
        if(i > 1 && arr[i] == arr[i - 1] + 1) flag = 1; 
    }
    if(flag) { cout << -1; return 0; }

    int now = 0, X = 1, ans = 0;
    while(1){
        if(now + 2 > arr[X]) ans++, now += 2, X++;
        else if(now + 2 < arr[X]) ans++, now += 2;
        else ans++, now++;
        if(X > N) break;
    }
    cout << ans;
    return 0;
}