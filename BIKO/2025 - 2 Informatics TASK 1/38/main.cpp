#include <bits/stdc++.h>

using namespace std;

const int MAXN = 250005;
int N;
int arr[MAXN];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N;
    for(i = 1;i <= N;i++) cin >> arr[i];

    int ans = 0, idx = 1;
    for(i = 1;i <= N;i++){
        if(arr[i] == idx) ans++, idx++;
    }
    cout << N - ans;
    return 0;
}