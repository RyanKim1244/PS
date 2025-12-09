#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 5;
int N, M, chk[MAXN];
vector<int> graph[MAXN];

void DFS(int x, int before){
    if(chk[x]) return;
    chk[x] = 1;
    for(auto element : graph[x]){
        if(element == before) continue;
        DFS(element, x);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;
    cin >> N >> M;
    for(i = 1;i <= M;i++){
        int a, b; cin >> a >> b;
        graph[b].push_back(a);
    }

    int Q; cin >> Q;
    while(Q--){
        int c, a; cin >> c >> a;
        if(c == 1){
            DFS(a, 0);
        }else{
            if(chk[a]) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}