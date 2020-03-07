#include<bits/stdc++.h>
using namespace std;
#define maxn 55
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
struct P{int x,y,t;};
queue<P> q;
int n,m;
char c[maxn][maxn];
int d[maxn][maxn];
main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",c[i]);
    int cnt=0;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)
        if(c[i][j]=='.')cnt++;
    q.push({0,0,1});
    while(!q.empty())
    {
        P t=q.front();q.pop();
        if(d[t.x][t.y])continue;
        d[t.x][t.y]=t.t;
        for(int i=0;i<4;i++)
        {
            int a=t.x+dx[i],b=t.y+dy[i];
            if(a<0 || a>=n || b<0 || b>=m)continue;
            if(c[a][b]=='#' || d[a][b])continue;
            q.push({a,b,t.t+1});
        }
    }
    /*
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)printf("%d ",d[i][j]);puts("");
    }
    */
    if(!d[n-1][m-1])return 0*puts("-1");
    printf("%d\n",cnt-d[n-1][m-1]);
    return 0;
}
