#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5, MAX = 1e9;
int N;
int S[MAXN];
struct Data{
    int height, locate;

    bool operator<(const Data&r)const{
        return height > r.height;
    }
}arr[MAXN];

bool compare(Data&a, Data&b){
    return a.locate < b.locate;
}

set<pair<int, int>> s;
unordered_map<int, int> m;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    int i, j;
    cin >> N;

    for(i = 1;i <= N;i++){
        int a, b; cin >> a >> b;

        arr[i].height = a, arr[i].locate = b;
    }

    sort(arr + 1, arr + N + 1, compare);
    for(i = 1;i <= N;i++) m[arr[i].locate] = i;
 
    sort(arr + 1, arr + N + 1);

    s.insert({-MAX, 0}); m[-MAX] = 0;
    s.insert({2 * MAX, 0}); m[2 * MAX] = N + 1;

    for(i = 1;i <= N;i++){
        int h = arr[i].height, pos = arr[i].locate;

        auto right = s.lower_bound({pos, 0});
        auto left = prev(right);

        if((pos - left->first) <= min(h, left->second)) {
            S[m[left->first]]++;
            S[m[pos]]--;
        }

        if((right->first - pos) <= min(h, right->second)){
            S[m[pos]]++;
            S[m[right->first]]--;
        }

        s.insert({pos, h});
    }

    sort(arr + 1, arr + N + 1, compare);

    int ans = 0, now = 0;
    for(i = 1;i <= N;i++){
        now += S[i];
        if(now > 0) ans += (arr[i + 1].locate - arr[i].locate);
    }
    cout << ans;
    return 0;
}