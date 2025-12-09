#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 3e6 + 5;
int N, T;
int arr[MAXN];

deque<pair<int, int>> dq1, dq2;

int chk(int mid){
    int i, j;
    for(i = 1;i <= mid;i++){
        if(dq1.empty()) dq1.push_back({arr[i], i});
        else{
            while(!dq1.empty() && dq1.back().first <= arr[i]) dq1.pop_back();
            dq1.push_back({arr[i], i});
        }

        if(dq2.empty()) dq2.push_back({arr[i], i});
        else{
            while(!dq2.empty() && dq2.back().first >= arr[i]) dq2.pop_back();
            dq2.push_back({arr[i], i});
        }
    }
    for(i = 1;i <= N - mid + 1;i++){
        if(dq1.front().second == i - 1) dq1.pop_front();
        if(dq2.front().second == i - 1) dq2.pop_front();

        if(dq1.front().first - dq2.front().first <= T) return 1;

        while(!dq1.empty() && dq1.back().first <= arr[i + mid]) dq1.pop_back();
        while(!dq2.empty() && dq2.back().first >= arr[i + mid]) dq2.pop_back();

        dq1.push_back({arr[i + mid], i + mid});
        dq2.push_back({arr[i + mid], i + mid});
    }
    return 0;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> T >> N;

    for(i = 1;i <= N;i++) cin >> arr[i];

    int low = 1, high = N;
    while(low < high - 1){
        int mid = (low + high) >> 1;

        if(chk(mid)) low = mid;
        else high = mid - 1;

        dq1.clear(); dq2.clear();
    }
    if(chk(high)) cout << high;
    else cout << low;
    return 0;
}