#include <bits/stdc++.h>

using namespace std;

int N;

vector<int> v1, v2;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j, mx = -21e8, mn = 21e8;
    cin >> N;
    for(i = 1;i <= N;i++){
        int a, b; cin >> a >> b;
        
        v1.push_back(a + b);
        v2.push_back(a - b);    

        mx = max(mx, b);
        mn = min(mn, b);
    }
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int T = v1[N - 1] - v2[0] + 2 * (-mn);

    cout << min(T, (v2[N - 1] - v1[0]) + 2 * mx);
    return 0;
}