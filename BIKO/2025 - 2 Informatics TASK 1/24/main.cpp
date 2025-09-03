#include <cstdio>

int n,m,arr[1005][1005],front,top,dx[5] = { -1,0,1,0 }, dy[5] = { 0,1,0,-1 },que[4][1000005],max = -9,ch[1005][1005];

void push(int i,int j,int now){
    if(ch[i][j] || arr[i][j] == -1||(arr[i][j] != 0 && arr[i][j] <= now) || i<1 || j<1 || i>n || j>m) return;
    que[0][top] = i,que[1][top] = j, que[2][top++] = now;
    arr[i][j] = now+1;
    ch[i][j] = 1;
}

void pop(){front++;}

void BFS()
{
    int k;
    while(front < top){
        int x = que[0][front], y = que[1][front], now = que[2][front];
        for(k = 0;k < 4;k++){
            int nx = x + dx[k], ny = y + dy[k];
            push(nx,ny,now+1);
        }
        pop();
    }
    front = top = 0;
}

int main(void)
{
    int ch = 0,i,j;
    scanf("%d %d",&m,&n);
    for(i = 1;i <= n;i++){
        for(j = 1;j <= m;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j] == 0) ch = 1;
        }
    }
    if(!ch) {
        printf("0");
        return 0;
    }
    for(i = 1;i <= n;i++){
        for(j = 1;j <= m;j++){
            if(arr[i][j] == 1) push(i,j,0);
        }
    }
    BFS();
    for(i = 1;i <= n;i++){
        for(j = 1;j <= m;j++){
            if(arr[i][j] > max) max = arr[i][j];
            if(arr[i][j] == 0){
                printf("-1");
                return 0;
            }
        }
    }
    printf("%d",max-1);
    return 0;
}
