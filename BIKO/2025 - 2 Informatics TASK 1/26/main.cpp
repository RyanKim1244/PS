#include <cstdio>
#include <cstring>
 
int main(void)
{
    char str[55];
    fgets(str, 55, stdin);
    int len = strlen(str),i,sum=10;
    while(str[len-1]=='\n'||str[len-1]=='\r') str[--len] = 0;
    for (i = 1; i < len; i++) {
        if (str[i - 1] != str[i]) sum += 10;
        else if (str[i - 1] == str[i]) sum += 5;
    }
    printf("%d", sum);
    return 0;
}