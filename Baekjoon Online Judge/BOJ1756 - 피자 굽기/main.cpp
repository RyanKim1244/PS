#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 5;
int D, N;
int d[MAXN], n[MAXN];

deque<pair<int, int>> dq;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> D >> N;
    for(i = 1;i <= D;i++) cin >> d[i];
    for(i = 1;i <= N;i++) cin >> n[i];

    for(i = 1;i <= D;i++){
        if(dq.empty()) dq.push_back({d[i], i});
        else if(dq.back().first > d[i]) dq.push_back({d[i], i});
    }

    
    return 0;
}