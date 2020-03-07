#include<bits/stdc++.h>
using namespace std;
int c[3][6];
bool vis[1005];
void gao3(int p,int q,int r)
{
    for(int i=0;i<6;i++)for(int j=0;j<6;j++)for(int k=0;k<6;k++)
    {
        int now=c[p][i]*100+c[q][j]*10+c[r][k];
        vis[now]=1;
    }
}
void gao2(int p,int q)
{
    for(int i=0;i<6;i++)for(int j=0;j<6;j++)
    {
        int now=c[p][i]*10+c[q][j];
        vis[now]=1;
    }
}
void gao1(int p)
{
    for(int i=0;i<6;i++)vis[c[p][i]]=1;
}
main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<6;j++)scanf("%d",&c[i][j]);
    if(n==1)
    {
        gao1(0);
        for(int i=1;;i++)if(!vis[i])return 0*printf("%d\n",i-1);
    }
    if(n==2)
    {
        gao1(0);gao1(1);
        gao2(0,1);gao2(1,0);
        for(int i=1;;i++)if(!vis[i])return 0*printf("%d\n",i-1);
    }
    if(n==3)
    {
        gao1(0);gao1(1);gao1(2);
        gao2(0,1);gao2(1,0);gao2(0,2);gao2(2,0);gao2(1,2);gao2(2,1);
        gao3(0,1,2);gao3(0,2,1);gao3(1,0,2);gao3(1,2,0);gao3(2,0,1);gao3(2,1,0);
        for(int i=1;;i++)if(!vis[i])return 0*printf("%d\n",i-1);
    }
    return 0;
}
