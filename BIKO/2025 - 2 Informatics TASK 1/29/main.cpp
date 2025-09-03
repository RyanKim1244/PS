#include <cstdio>
 
char str[20];
int h, arr[5][5], st = 1, a[3][3], arr2[5];
 
int main(void)
{
    a[0][0] = 0, a[0][1] = 1, a[1][0] = 2, a[1][1] = 3;
    arr2[0] = 2, arr2[1] = 3, arr2[2] = 0, arr2[3] = 1;
    int k,check1 = 0, check2 = 0, index1, index2;
    char s1, s2;
    scanf("%d",&k);
    for(int i = 1;i <= 2 * k;i++){
        scanf(" %c",&str[i]);
    }
    scanf("%d",&h);
    for(int i = 2 * k;i >= 1;i--){
        if(!check1 && (str[i] == 'R' || str[i] == 'L')) {
            if(str[i] == 'R') index1 = 1;
            else index1 = 0;
            check1 = 1;
        }
        if(!check2 && (str[i] == 'D' || str[i] == 'U')){
            if(str[i] == 'D') index2 = 1;
            else index2 = 0;
            check2 = 1;
        }
        if(check1 && check2) break;
    }
    arr[index2][index1] = h;
    if(index2 == 0){
        arr[1][index1] = arr2[arr[index2][index1]];
    }
    else{
        arr[0][index1] = arr2[arr[index2][index1]];
    }
    if(index1 == 0){
        if(arr[0][index1] % 2 == 0) arr[0][1] = arr[0][0] + 1;
        else arr[0][1] = arr[0][0] - 1;
        if(arr[1][0] % 2 == 0) arr[1][1] = arr[1][0] + 1;
        else arr[1][1] = arr[1][0] - 1;
    }
    else{
        if(arr[0][1] % 2 == 0) arr[0][0] = arr[0][1] + 1;
        else arr[0][0] = arr[0][1] - 1;
        if(arr[1][1] % 2 == 0) arr[1][0] = arr[1][1] + 1;
        else arr[1][0] = arr[1][1] - 1;
    }
    for(int i = 0;i < (1 << k);i++){
        for(int j = 0;j < (1 << k);j++){
            printf("%d ",arr[i%2][j%2]);
        }
        puts("");
    }
    return 0;
}