#include<bits/stdc++.h>
using namespace std;
#define maxn 30000+5
int p[maxn],sz[maxn];
int finds(int x)
{
    return p[x]==x ? x : p[x]=finds(p[x]);
}
void Union(int x,int y)
{
    x=finds(x),y=finds(y);
    if(x!=y)
    {
        if(sz[x]<sz[y])
            p[x]=y,sz[y]+=sz[x];
        else
            p[y]=x,sz[x]+=sz[y];
    }
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,m;scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)p[i]=i,sz[i]=1;
        for(int i=0;i<m;i++)
        {
            int x,y;scanf("%d%d",&x,&y);
            if(finds(x)!=finds(y))Union(x,y);
        }
        int ans=0;
        for(int i=1;i<=n;i++)ans=max(ans,sz[i]);
        printf("%d\n",ans);
    }
    return 0;
}
