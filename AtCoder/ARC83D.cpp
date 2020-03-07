#include<bits/stdc++.h>
using namespace std;
#define maxn 305
#define ll long long
ll dis[maxn][maxn];
ll a[maxn][maxn];
bool ok[maxn][maxn];
struct node
{
    int u,v;
    ll dis;
    bool operator < (const node& b)const{return dis<b.dis;}
}V[maxn*maxn];
main()
{
    int n;scanf("%d",&n);
    int cur=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
    {
        scanf("%lld",&dis[i][j]);
        if(i<j)V[++cur]={i,j,dis[i][j]};
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dis[i][j]>dis[i][k]+dis[k][j]){puts("-1");return 0;}
            }
        }
    }
    sort(V+1,V+cur+1);
    for(int i=1;i<=cur;i++)
    {
        int u=V[i].u,v=V[i].v,d=V[i].dis;
        if(ok[u][v])continue;
        a[u][v]=d;
        ok[u][v]=1,ok[v][u]=1;
        for(int t=1;t<=n;t++)
        {
            if(t==u || t==v)continue;
            if(d+dis[v][t]==dis[u][t])ok[u][t]=1,ok[t][u]=1;
            if(d+dis[u][t]==dis[v][t])ok[v][t]=1,ok[t][v]=1;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        ans+=a[i][j];
    printf("%lld\n",ans);
    return 0;
}
