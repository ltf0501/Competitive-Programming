#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
map<int,int> bit[maxn];
int n,m;
int query(int u,int x)
{
    int ret=0;
    for(int i=x;i;i-=i&-i)ret=max(bit[u][i],ret);
    return ret;
}
void add(int u,int x,int s)
{
    for(int i=x;i<maxn;i+=i&-i)bit[u][i]=max(bit[u][i],s);
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y,w;scanf("%d%d%d",&x,&y,&w);
        w++;
        add(y,w,query(x,w)+1);
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,query(i,maxn));
    printf("%d\n",ans);
    return 0;
}
