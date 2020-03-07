#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int p[maxn];
void init(int n)
{
    for(int i=1;i<=n;i++)p[i]=i;
}
int finds(int x){return p[x]==x ? x : p[x]=finds(p[x]);}
void Union(int x,int y)
{
    int u=finds(x),v=finds(y);
    if(u==v)return ;
    p[v]=u;
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,m;scanf("%d%d",&n,&m);
        init(n);
        while(m--)
        {
            int a,b;scanf("%d%d",&a,&b);
            Union(a,b);
        }
        for(int i=1;i<=n;i++)printf("%d\n",finds(i));
    }
    return 0;
}
