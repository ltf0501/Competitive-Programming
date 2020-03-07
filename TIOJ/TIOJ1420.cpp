#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
#define maxc 50000+5
int a,b,c;
struct node
{
    int x,y;
    bool operator < (const node& b)const
    {
        return x<b.x || (x==b.x && y<b.y);
    }
}p[maxc];
int vis[maxc];
map<int,node> m;
map<node,int> M;
map<node,int>::iterator it;
void dfs(int u)
{
    vis[u]=1;
    for(int dx=-2;dx<=2;dx++)
    {
        for(int dy=-2;dy<=2;dy++)
        {
            if(!dx && !dy)continue;
            int x=m[u].x+dx,y=m[u].y+dy;
            if(x<=0 || x>a || y<=0 || y>b)continue;
            it=M.find((node){x,y});
            if(it!=M.end() && !vis[M[(node){x,y}]])
            {
               // printf("%d %d %d\n",x,y,M[(node){x,y}]);
                dfs(M[(node){x,y}]);
            }
        }
    }
}
main()
{
    while(scanf("%d%d%d",&a,&b,&c)==3)
    {
        for(int i=1;i<=c;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            m[i]=(node){p[i].x,p[i].y};
            M[(node){p[i].x,p[i].y}]=i;
        }
        //for(it=M.begin();it!=M.end();it++)printf("%d %d\n",(it->first).x,(it->first).y);
        memset(vis,0,sizeof(vis));
        int ans=0;
        for(int i=1;i<=c;i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(i);
                /*
                for(int i=1;i<=c;i++)printf("%d ",vis[i]);
                puts("");
                */
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
