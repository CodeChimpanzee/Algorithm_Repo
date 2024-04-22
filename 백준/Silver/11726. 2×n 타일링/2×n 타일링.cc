#include<stdio.h>
#include<cstring>

typedef long long ll;
ll memo[1001];

ll fillMeUp(int width)
{
    if(width < 0) return 0;
    if(width == 0) return 1;
    ll &res = memo[width];
    if(res != -1) return res;
    return res = (fillMeUp(width-1) + fillMeUp(width-2)) % 10007;
}

int main(void)
{
    int n;
    memset(memo, -1, sizeof(memo));
    scanf("%d",&n);
    printf("%d", fillMeUp(n)%10007);
}