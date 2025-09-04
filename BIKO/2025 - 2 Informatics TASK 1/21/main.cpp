#include <bits/stdc++.h>

using namespace std;

int arr[25];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;

    for(i = 1;i <= 20;i++) arr[i] = i;

    for(i = 1;i <= 10;i++){
        int a, b; cin >> a >> b;

        for(j = a;j <= a + (b - a) / 2;j++) swap(arr[j], arr[a + b - j]); 
    }

    for(i = 1;i <= 20;i++) cout << arr[i] << " ";
    return 0;
}