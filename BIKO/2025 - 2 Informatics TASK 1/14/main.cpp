#include <cstdio>
#include <algorithm>

using namespace std;

int a, b, a_last, b_last, fr, r;
int chk[5][100005], chk2[5][100005], q[4][1000005], check[100005], check1[100005];

void push(int A, int B, int C)
{
    if(chk[check[A]][B] || chk2[check1[B]][A]) return;
    q[1][r] = A, q[2][r] = B, q[3][r++] = C;
}

void Do(int A, int B, int C)
{
    int AA = A, BB = B;
    A = a, push(A, B, C + 1), A = AA;
    B = b, push(A, B, C + 1), B = BB;
    A = 0, push(A, B, C + 1), A = AA;
    B = 0, push(A, B, C + 1), B = BB;
    if(A + B > b){
        A = (A + B) - b, B = b;
        push(A, B, C + 1);
        A = AA, B = BB;
    }
    else B = A + B, A = 0, push(A, B, C + 1), A = AA, B = BB;
    if(A + B > a) {
        B = (A + B) - a, A = a;
        push(A, B, C + 1);
    }
    else A = A + B, B = 0, push(A, B, C + 1);
}

void BFS()
{
    while(fr < r){
        int A = q[1][fr], B = q[2][fr], C = q[3][fr];
        if(A == 0 || A == a){
            if(!chk[check[A]][B]) {
                chk[check[A]][B] = C;
                Do(A, B, C);
            }
        }
        else if(B == 0 || B == b){
            if(!chk2[check1[B]][A]){
                chk2[check1[B]][A] = C;
                Do(A, B, C);
            }
        }
        fr++;
    }
}

int main(void)
{
    scanf("%d %d %d %d", &a, &b, &a_last, &b_last);
    check[0] = 1, check[a] = 2;
    check1[0] = 1, check1[b] = 2;
    push(0, 0, 1);
    BFS();
    if(a_last == 0 || a_last == a) printf("%d", chk[check[a_last]][b_last] - 1);
    else if(b_last == 0 || b_last == b) printf("%d", chk2[check1[b_last]][a_last] - 1);
    else printf("-1");
    return 0;
}
