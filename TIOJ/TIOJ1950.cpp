#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 100000+10
int n,m;
int nxt[maxn],p[maxn],cnt;
bool vis[maxn];
int finds(int x)
{
    while(x!=p[x])p[x]=p[p[x]],x=p[x];
    return x;
}
/*
void unions(int x,int y)
{
    int proot=finds(x),qroot=finds(y);
    p[proot]=qroot;
}
*/
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)p[i]=i;
    for(int i=1;i<=n;i++)
    {
        int a;scanf("%d",&a);
        nxt[i]=a;
    }
    cnt=0;
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            vis[i]=1;
            cnt++;
            int id=nxt[i];
            while(!vis[id])
            {
                vis[id]=1;
                p[id]=i;
                id=nxt[id];
            }
        }
    printf("%d\n",n-cnt);
    /*
    for(int i=1;i<=n;i++)printf("%d ",p[i]);
    puts("");
    */
    while(m--)
    {
        int x,y;scanf("%d%d",&x,&y);
        int xroot=finds(x),yroot=finds(y);
        for(int i=1;i<=n;i++)printf("%d ",p[i]);
        puts("");
        if(xroot!=yroot)
        {
            p[xroot]=yroot,cnt--;
            swap(nxt[x],nxt[y]);
        }
        else
        {
             p[x]=nxt[y],p[y]=nxt[x],p[nxt[x]]=nxt[x],p[nxt[y]]=nxt[y],cnt++;
             swap(nxt[x],nxt[y]);
        }

        //printf("%d\n",n-cnt);
    }
    for(int i=1;i<=n;i++)printf("%d ",p[i]);
        puts("");
    return 0;
}
