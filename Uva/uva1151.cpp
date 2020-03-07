#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 1000+10
int n,q;
int c[2][10],s[8][maxn],p[maxn],l[maxn],indx;
struct Point
{
    int x,y;
}P[maxn];
struct edge
{
    int u,v,w;
    bool operator < (const edge& rhs) const
    {
        return w<rhs.w;
    }
}a[maxn*maxn/2];
int Find(int x)
{
    return x==p[x]?x:p[x]=Find(p[x]);
}
int Kruskal()//計算不買套餐
{
    int ans=0;
    l[0]=0;
    for(int i=0;i<indx;i++)
    {
        int x=Find(a[i].u),y=Find(a[i].v);
        if(x!=y)
        {
            ans+=a[i].w;
            p[x]=y;
            l[++l[0]]=i;
        }
    }
    return ans;
}
int Kruskal2()//買套餐後的最小生成樹
{
    int ans=0;
    for(int i=1;i<=l[0];i++)
    {
        int tmp=l[i];
        int x=Find(a[tmp].u),y=Find(a[tmp].v);
        if(x!=y)
        {
            p[x]=y;
            ans+=a[tmp].w;
        }
    }
    return ans;
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        for(int i=0;i<q;i++)
        {
            scanf("%d%d",&c[0][i],&c[1][i]);
            for(int j=0;j<c[0][i];j++)scanf("%d",&s[i][j]);
        }
        for(int i=0;i<n;i++)scanf("%d%d",&P[i].x,&P[i].y);
        indx=0;
        for(int i=0;i<n;i++)//计算權值
            for(int j=i+1;j<n;j++)
            {
                a[indx].u=i+1;
                a[indx].v=j+1;
                a[indx++].w=(P[i].x-P[j].x)*(P[i].x-P[j].x)+(P[i].y-P[j].y)*(P[i].y-P[j].y);
            }

        sort(a,a+indx);
        for(int i=0;i<n;i++)p[i]=i;
        int ans=Kruskal();

        for(int i=0;i<(1<<q);i++)//列舉套餐
        {
            int cost=0;
            for(int j=0;j<=n;j++)p[j]=j;

            for(int j=0;j<q;j++)
            {
                if(i&(1<<j))
                {
                    cost+=c[1][j];
                    for(int k=0;k<c[0][j]-1;k++)
                    {
                        int xx=Find(s[j][k]),yy=Find(s[j][k+1]);
                        if(xx!=yy)p[xx]=yy;
                    }
                }
            }
            ans=min(ans,cost+Kruskal2());
        }

        printf("%d\n",ans);
        if(t)puts("");
    }
    return 0;
}
/*
1
7 3
2 4 1 2
3 3 3 6 7
3 9 2 4 5
0 2
4 0
2 0
4 2
1 3
0 5
4 4

17
*/
