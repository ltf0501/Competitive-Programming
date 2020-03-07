#include<bits/stdc++.h>
using namespace std;
struct pos
{
    int x,y,t,d;
};
queue<pos> q;
bool vis[101][101][101];
main()
{
    int x,y,d;
    while(~scanf("%d%d%d",&x,&y,&d) && x+y+d)
    {
        memset(vis,0,sizeof(vis));
        if(d%__gcd(x,y)!=0){puts("No");continue;}
        while(!q.empty())q.pop();
        q.push({0,0,0,0});
        while(!q.empty())
        {
            pos t=q.front();q.pop();
            if(vis[t.x][t.y][t.d])continue;
            vis[t.x][t.y][t.d]=1;
            //printf("%d %d %d %d\n",t.x,t.y,t.d,t.t);
            if(t.d==d){printf("%d\n",t.t);break;}
            if(t.x)q.push({0,t.y,t.t+1,t.d});
            if(t.y)q.push({t.x,0,t.t+1,t.d});
            if(t.x<x)q.push({x,t.y,t.t+1,t.d});
            if(t.y<y)q.push({t.x,y,t.t+1,t.d});
            if(t.x && t.x+t.y<=y)q.push({0,t.x+t.y,t.t+1,t.d});
            if(t.y && t.x+t.y<=x)q.push({t.x+t.y,0,t.t+1,t.d});
            if(t.x+t.y>=y)q.push({t.x-(y-t.y),y,t.t+1,t.d});
            if(t.x+t.y>=x)q.push({x,t.y-(x-t.x),t.t+1,t.d});
            if(t.x && t.x+t.d<=d)q.push({0,t.y,t.t+1,t.x+t.d});
            if(t.y && t.y+t.d<=d)q.push({t.x,0,t.t+1,t.y+t.d});
        }
    }
    return 0;
}
