#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long
int p[maxn],id[maxn],sz[maxn];
int finds(int x){return p[x]==x ? x : p[x]=finds(p[x]);}
ll val[maxn],ans;
vector<int> g[maxn];
int n;
bool cmp(int x,int y){return val[x]<val[y];}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%I64d",&val[i]),id[i]=i;
    sort(id+1,id+n+1,cmp);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    for(int i=1;i<=n;i++)p[i]=i,sz[i]=1;
    for(int i=1;i<=n;i++)for(int j : g[id[i]])if(val[id[i]]>val[j] || (val[id[i]]==val[j] && id[i]>j))
    {
        int a=finds(id[i]),b=finds(j);
        ans+=val[id[i]]*sz[a]*sz[b];
        if(sz[a]>sz[b])sz[a]+=sz[b],p[b]=a;
        else sz[b]+=sz[a],p[a]=b;
    }
    for(int i=1;i<=n;i++)p[i]=i,sz[i]=1;
    for(int i=n;i>=1;i--)for(int j : g[id[i]])if(val[id[i]]<val[j] || (val[id[i]]==val[j] && id[i]<j))
    {
        int a=finds(id[i]),b=finds(j);
        ans-=val[id[i]]*sz[a]*sz[b];
        if(sz[a]>sz[b])sz[a]+=sz[b],p[b]=a;
        else sz[b]+=sz[a],p[a]=b;
    }
    printf("%I64d\n",ans);
    return 0;
}
