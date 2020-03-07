#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
int f(int n)
{
    int ret=1;
    while(n)
    {
        int a=n%10;
        if(a)ret*=a;
        n/=10;
    }
    return ret;
}
int g[maxn];
int cnt[10][maxn];
void init()
{
    for(int i=1;i<=9;i++)g[i]=i;
    for(int i=10;i<maxn;i++)g[i]=g[f(i)];
    for(int i=1;i<maxn;i++)
    {
        for(int j=1;j<=9;j++)cnt[j][i]=cnt[j][i-1];
        cnt[g[i]][i]++;
    }
}
main()
{
    init();
    int q;scanf("%d",&q);
    while(q--)
    {
        int l,r,k;scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",cnt[k][r]-cnt[k][l-1]);
    }
    return 0;
}

