#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 10000+5
#define maxm 1000000+5
int p[maxn],u[maxm],v[maxm],w[maxm],r[maxm];
int n,m;
int cmp(int i,int j)
{
    return w[i]<w[j];
}
int finds(int x)
{
    return p[x]==x ? x : p[x]=finds(p[x]);
}
int kruskal()
{
    int ans=0;
    for(int i=1;i<=n;i++)p[i]=i;
    for(int i=1;i<=m;i++)r[i]=i;
    sort(r+1,r+m+1,cmp);
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        int e=r[i];
        int x=finds(u[e]),y=finds(v[e]);
        if(x!=y)ans+=w[e],p[x]=y,cnt++;
        if(cnt==n-1)return ans;
    }
    return -1;
}
main()
{
    while(~scanf("%d%d",&n,&m) && n+m)
    {
        for(int i=1;i<=m;i++)scanf("%d%d%d",&u[i],&v[i],&w[i]);
        int ans=kruskal();
        printf("%d\n",ans);
    }
    return 0;
}
