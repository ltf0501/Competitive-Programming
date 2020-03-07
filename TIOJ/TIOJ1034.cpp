#include<bits/stdc++.h>
using namespace std;
#define INF 100000000;
int dp[22][22][22][22];
int A[22][22];
bool vis[405];
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int n;
int id(int x,int y)
{
    return n*(x-1)+y;
}
struct P
{
    int d,id;
    bool operator < (const P& b)const
    {
        return d>b.d;
    }
};
priority_queue<P> pq;
main()
{
    scanf("%d",&n);
    for(int a=0;a<=21;a++)for(int b=0;b<=21;b++)for(int c=0;c<=21;c++)for(int d=0;d<=21;d++)dp[a][b][c][d]=INF;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&A[i][j]);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
    {
        memset(vis,0,sizeof(vis));
        pq.push({A[i][j],id(i,j)});
        dp[i][j][i][j]=A[i][j];
        while(!pq.empty())
        {
            P t=pq.top();pq.pop();
            int u=t.id;
            if(vis[u])continue;
            int x=(u-1)/n+1,y=(u-1)%n+1;
            vis[u]=1;
            for(int m=0;m<4;m++)
            {
                int a=x+dx[m],b=y+dy[m];

                if(0<a && a<=n && 0<b && b<=n)
                {
                    if(dp[i][j][a][b]>t.d+A[a][b])
                    {
                        dp[i][j][a][b]=t.d+A[a][b];
                        pq.push({dp[i][j][a][b],id(a,b)});
                    }
                }
            }
        }
    }
    int q;scanf("%d",&q);
    while(q--)
    {
        int x,y,a,b;scanf("%d%d%d%d",&x,&y,&a,&b);
        if(x>a)swap(x,a),swap(y,b);
        int ans=INF;
        if(y<=b)
        {
            for(int i=x;i<=a;i++)for(int j=y;j<=b;j++)
                ans=min(ans,dp[x][y][i][j]+dp[i][j][a][b]-2*A[i][j]);
        }
        else
        {
            for(int i=x;i<=a;i++)for(int j=y;j>=b;j--)
                ans=min(ans,dp[x][y][i][j]+dp[i][j][a][b]-2*A[i][j]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
