#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define maxn 100+10
struct point
{
    int x,y;
};
const int dx[]={0,0,-1,1};
const int dy[]={1,-1,0,0};//¤W¤U¥ª¥k


main()
{
    int S,N,M,G[maxn][maxn],time[maxn][maxn];
    queue<point> q;
    int cas=0;
    while(scanf("%d",&S)==1)
    {
        memset(G,0,sizeof(G));
        memset(time,0,sizeof(time));
        scanf("%d%d",&N,&M);
        for(int i=1;i<=N;i++)
            for(int j=1;j<=M;j++)scanf("%d",&G[i][j]);

        for(int j=1;j<=M;j++)
            if(G[1][j])
            {
                q.push( (point){1,j} );
                time[1][j]=1;
                break;
            }

        while(!q.empty())
        {
            point a=q.front();q.pop();
            for(int i=0;i<=3;i++)
            {
                if(S==2 && i==2)continue;
                int x=a.x+dx[i],y=a.y+dy[i];
                if(!time[x][y] && G[x][y]==1)
                {
                    time[x][y]=time[a.x][a.y]+1;
                    q.push( (point){x,y} );
                }
            }
        }

        printf("Case %d:\n",++cas);
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)printf("%d ",time[i][j]);
            printf("\n");
        }

    }
    return 0;
}
