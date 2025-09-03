#include <cstdio>
#include <algorithm>

using namespace std;

int arr[300005];

int main(void){
    int N;
    int i, j;
    scanf("%d", &N);
    
    for(i = 1;i <= N;i++){
        scanf("%d", &arr[i]);
    }
    
    int c = 1, ans = 0;
    for(i = 1;i <= N;i++){
        if(c == 0 && arr[i] % 2 == 0) c = 1, ans++;
        if(c == 1 && arr[i] % 2 == 1) c = 0, ans++;
    }
    
    c = 0;
    int cnt = 0;
    for(i = 1;i <= N;i++){
        if(c == 0 && arr[i] % 2 == 0) c = 1, cnt++;
        if(c == 1 && arr[i] % 2 == 1) c = 0, cnt++;
    }
    
    printf("%d", max(ans, cnt));
    return 0;
}
