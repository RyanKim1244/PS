#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void)
{
    int x1,x2,y1,y2,x11,x22,y11,y22;
    scanf("%d %d %d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x11,&y11,&x22,&y22);
    if(x1 > x22 || x11 > x2 || y1 > y22 || y11 > y2) printf("NULL");
    else if((x2 == x11 && y2 == y11) || (x1 == x22 && y1 == y22) || (y1 == y22 && x2 == x11) || (x1 == x22 && y2 == y11)) printf("POINT");
    else if((x2 == x11) || (x22 == x1) || (y2 == y11) || (y22 == y1)) printf("LINE");
    else printf("FACE");
    return 0;
}