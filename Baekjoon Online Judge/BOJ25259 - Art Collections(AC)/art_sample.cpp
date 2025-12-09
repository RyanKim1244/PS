#include "art.h"
#include <algorithm>

using namespace std;

const int MAXN = 4005;
vector<int> v;
int S[MAXN];

struct Data{
    int val, i;

    bool operator<(const Data&r)const{
        return val < r.val;
    }
}arr[MAXN];

void solve(int N) {
    int i, j;
    for(i = 1;i <= N;i++) arr[i].i = i;
    for(i = 1;i <= N;i++){
        for(j = i;j <= N;j++) v.push_back(j);
        for(j = 1;j < i;j++) v.push_back(j);

        S[i] = publish(v);
        v.clear();
    }

    for(i = 1;i <= N;i++){
        if(i == N) arr[i].val = S[1] - S[N];
        else arr[i].val = S[i + 1] - S[i];
    }

    sort(arr + 1, arr + N + 1);
    reverse(arr + 1, arr + N + 1);
    vector<int> ans;

    for(i = 1;i <= N;i++) ans.push_back(arr[i].i);
    answer(ans);
}
