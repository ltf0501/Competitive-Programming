#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 20000+10
#define maxm 100000+10
int p[maxn];
int n,m,k;
struct edge
{
    int u,v,c;
}e[maxm];
int findset(int x)
{
    return p[x]==x ? x : p[x]=findset(p[x]);
}
main()
{
    while(scanf("%d%d%d",&n,&m,&k)==3)
    {
        for(int i=1;i<=m;i++)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].c);
        for(int i=1;i<=n;i++)p[i]=i;

    }
    return 0;
}

