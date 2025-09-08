#include <bits/stdc++.h>

using namespace std;

int N, K;

struct Data{
    int number, gold, silver, bronze;
}arr[1005];

bool compare(const Data&a, const Data&b){
    if(a.gold == b.gold && a.silver == b.silver) return a.bronze < b.bronze;
    if(a.gold == b.gold) return a.silver < b.silver;
    return a.gold < b.gold;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j, tar;
    cin >> N >> K;
    for(i = 1;i <= N;i++){
        cin >> arr[i].number >> arr[i].gold >> arr[i].silver >> arr[i].bronze;

        if(K == arr[i].number) tar = i;
    }

    int ans = 0;
    for(i = N;i >= 1;i--){
        if(compare(arr[tar], arr[i])) ans++;
    } 
    cout << ans + 1;
    return 0;
}