#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
int N, M, Q;

vector<pair<int, int>> edge;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N >> M >> Q;

    for(i = 1;i < N;i++){
        int a, b; cin >> a >> b;

        edge.push_back({a, b});
    }


    return 0;
}