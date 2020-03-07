#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define INF 1000000
#define maxn 50+2
int G[maxn][maxn][maxn];
int d[maxn][maxn][maxn],t[maxn][maxn][maxn];
const int dx[]={1,-1,0,0,0,0},dy[]={0,0,1,-1,0,0},dz[]={0,0,0,0,1,-1};
void print(int x,int y,int z)
{
    if(!x && !y && !z){printf("(1,1,1)");return ;}
    int type=t[x][y][z];
    print(x-dx[type],y-dy[type],z-dz[type]);
    printf("->(%d,%d,%d)",x+1,y+1,z+1);
}
main()
{
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    for(int i=0;i<z;i++)for(int j=0;j<y;j++)for(int k=0;k<x;k++)scanf("%d",&G[k][j][i]),d[k][j][i]=INF;
    d[0][0][0]=1;
    queue<int> q;
    if(!G[0][0][0])for(int i=0;i<3;i++)q.push(0);
    while(!q.empty())
    {
        int a=q.front();q.pop();
        int b=q.front();q.pop();
        int c=q.front();q.pop();
        for(int i=0;i<6;i++)
        {
            int da=a+dx[i],db=b+dy[i],dc=c+dz[i];
            if(da<0 || da>=x || db<0 || db>=y || dc<0 || dc>=z)continue;
            if(G[da][db][dc] || d[da][db][dc]!=INF)continue;
            d[da][db][dc]=d[a][b][c]+1;
            t[da][db][dc]=i;
            q.push(da);q.push(db);q.push(dc);
        }
    }
    /*
    for(int k=0;k<z;k++)
    {
        for(int j=0;j<y;j++)
        {
            for(int i=0;i<x;i++)printf("%d ",d[i][j][k]);
            puts("");
        }
        puts("");
    }
    */
    if(d[x-1][y-1][z-1]==INF)puts("no route");
    else print(x-1,y-1,z-1),puts("");

    return 0;
}
