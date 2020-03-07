#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=21;
int n,m,k;
int a[maxn][maxn][maxn];
int b[maxn][maxn];
int dir[4][2]= {-1,0,1,0,0,-1,0,1};
struct node
{
    int x,y,step,zhangai;
    void boom(int nx,int ny,int nstep,int nzhangai)
    {
        x=nx;
        y=ny;
        step=nstep;
        zhangai=nzhangai;
    }
};


int bfs()
{
    queue<node>q;
    while(!q.empty())
        q.pop();
    node u,v;
    u.boom(1,1,0,0);         //起点
    q.push(u);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int xx=u.x;
            int yy=u.y;
            int sstep=u.step;
            int szhangai=u.zhangai;
            xx+=dir[i][0];
            yy+=dir[i][1];
            sstep+=1;
            if(xx>n||xx<1||yy>m||yy<1)
                continue;
            if(b[xx][yy]==1)
                szhangai++;
            else
                szhangai=0;
            if(szhangai>k)
                continue;
            if(a[xx][yy][szhangai]==1)  //如果没有这一步会超时
                continue;
            if(xx==n&&yy==m)
                return sstep;
            v.boom(xx,yy,sstep,szhangai);
            q.push(v);
            a[xx][yy][szhangai]=1;
        }
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&n,&m,&k);
        memset(a,0,sizeof(a));        //每次都要
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                scanf("%d",&b[i][j]);
        int total=bfs();
        printf("%d\n",total);
    }
    return 0;
}
