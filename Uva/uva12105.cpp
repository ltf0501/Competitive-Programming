#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define INF 0x3f3f3f3f
int n,m;
int c[]={6,2,5,5,4,5,6,3,7,6};
int mod[10][110],d[110][3300];
//d(i,j)表除以m於j的i位數至少幾火柴
//mod(i,j)表i*10^((j-1))%m
int dp()
{
    memset(d,INF,sizeof(d));
    d[0][0]=0;
    for(int i=0;i<=9;i++)d[1][i%m]=min(c[i],d[1][i%m]);
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(d[i][j]<=n)
            {
                for(int k=0;k<=9;k++)d[i+1][(j*10+k)%m]=min(d[i][j]+c[k],d[i+1][(j*10+k)%m]);
            }
        }
    }
    for(int i=n/2;i>=1;i--)
        if(d[i][0]<=n)return i;
    return -1;
}
void dfs(int pos,int x,int sum)
{
    if(pos==0)return;
    for(int i=9;i>=0;i--)
    {
        for(int j=0;j<m;j++)
        {
            if((j+mod[i][pos])%m==x)
            {
                if(c[i]+d[pos-1][j]<=sum)
                {
                    printf("%d",i);
                    dfs(pos-1,j,sum-c[i]);
                    return;
                }
            }
        }
    }
}
main()
{
    int cas=0;
    while(scanf("%d",&n)==1 && n)
    {
        scanf("%d",&m);
        printf("Case %d: ",++cas);
        memset(mod,0,sizeof(mod));
        for(int i=1; i<=9; i++)
        {
            mod[i][1]=i%m;
            for(int j=2;j<=100;j++)mod[i][j]=mod[i][j-1]*10%m;
        }
        int len=dp();
        if(len==-1)printf("-1");
        else
        {

            for(int i=9;i>=0;i--)
            {
                if(c[i]+d[len-1][(m-mod[i][len])%m]<=n)
                {
                    printf("%d",i);
                    dfs(len-1,(m-mod[i][len])%m,n-c[i]);
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
