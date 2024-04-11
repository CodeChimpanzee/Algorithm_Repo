#include<stdio.h>

int bits = 0;

void intoTheUnknown(int r, int c, int size)
{
    if(!size) return;

    bits += r >= ((1<<size)>>1);
    bits <<= 1;
    bits += c >= ((1<<size)>>1);
    bits <<= 1;
    intoTheUnknown(r&(((1<<size)>>1)-1), c&(((1<<size)>>1)-1), size-1);
}

int main(void)
{
    int n, r, c;
    scanf("%d %d %d",&n,&r,&c);
    intoTheUnknown(r,c,n);
    printf("%d",bits >> 1);
}