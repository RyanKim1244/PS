#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
int M, N, L;
int arr[MAXN];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j, ans = 0;
    cin >> M >> N >> L;
    for(i = 1;i <= M;i++) cin >> arr[i];

    sort(arr + 1, arr + M + 1);

    for(i = 1;i <= N;i++){
        int a, b; cin >> a >> b;

        int l = 1, r = M;
        while(l < r - 1){
            int mid = (l + r) >> 1;
            if(arr[mid] < a) l = mid;
            else r = mid;
        }
        if(l == M) {
            if(b + abs(a - arr[l]) <= L) ans++;
        }else{
            if(b + abs(a - arr[l]) <= L) ans++;
            else if(b + abs(a - arr[l + 1]) <= L) ans++;
        }
    }
    cout << ans;
    return 0;
} // 이분 탐색을 사용하지 않고도 풀 수 있을듯하다.