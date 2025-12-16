#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
int N;
int arr[MAXN];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N;
    for(i = 1;i <= N;i++) cin >> arr[i];

    sort(arr + 1, arr + N + 1);

    vector<int> ans;
    int idx1 = 1, idx2 = N;
    for(i = 1;i <= N;i++){
        if(i & 1) ans.push_back(arr[idx1++]);
        else ans.push_back(arr[idx2--]);
    }
    reverse(ans.begin(), ans.end());

    for(auto x : ans) cout << x << " ";
    return 0;
}