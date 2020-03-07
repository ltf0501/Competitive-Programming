#include<bits/stdc++.h>
#define maxn 4000003
using namespace std;
int vis[maxn],n,m,num[maxn],ans;
int point[maxn],nxt[maxn],v[maxn],tot,l[maxn],r[maxn],mark[maxn];
void add(int x,int y)
{
    tot++;nxt[tot]=point[x];point[x]=tot;v[tot]=y;
    tot++;nxt[tot]=point[y];point[y]=tot;v[tot]=x;
}
void del(int x)
{
    vis[x]=1;
    r[l[x]]=r[x];
    l[r[x]]=l[x];
}
void bfs(int x)
{
    queue<int> q;q.push(x);
    while(!q.empty())
    {
        int now=q.front();q.pop();
        num[ans]++;
        for(int i=point[now];i;i=nxt[i])mark[v[i]]=1;
        for(int i=r[0];i;i=r[i])
            if(!vis[i] && !mark[i]) del(i),q.push(i);
        for(int i=point[now];i;i=nxt[i])mark[v[i]]=0;
    }
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        add(x,y);
    }
    for(int i=0;i<=n;i++)l[i]=i-1,r[i]=i+1;
    r[n]=0;
    for(int i=1;i<=n;i++)if(!vis[i])
    {
        ans++;
        del(i);
        bfs(i);
    }
    sort(num+1,num+ans+1);
    printf("%d\n",ans);
    for(int i=1;i<=ans;i++)printf("%d ",num[i]);
    puts("");
    return 0;
}
