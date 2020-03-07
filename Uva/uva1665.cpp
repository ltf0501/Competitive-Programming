#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 1005
#define maxm 100005
struct Point
{
    int h,x,y;
    bool operator < (const Point& rhs) const{return h<rhs.h;}
}data[maxn*maxn];
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};//左右下上
int n,m;
int N,M;
int fa[maxn*maxn],id[maxn][maxn],h[maxn][maxn];
int ans[maxm],t[maxm];

int finds(int x)
{
    return fa[x]==x?x:fa[x]=finds(fa[x]);
}
main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        N=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x;
                scanf("%d",&x);
                h[i][j]=x;
                data[N].h=x,data[N].x=i,data[N].y=j;
                N++;
                id[i][j]=i*m+j;
            }
        }
        sort(data,data+N);
        for(int i=0;i<N;i++)fa[i]=i;
        scanf("%d",&M);
        for(int i=0;i<M;i++)scanf("%d",t+i);
        int j=N-1,cnt=0;
        for(int i=M-1;i>=0;i--)
        {
            while(j>=0 && data[j].h>t[i])//按照高度遞減順序尋找t[i]年未被淹沒的節點j
            {
                cnt++;
                int u=data[j].x,v=data[j].y;

                for(int k=0;k<4;k++)
                {
                    int x=u+dx[k],y=v+dy[k];
                    if(x>=0 && x<n && 0<=y && y<m &&data[j].h<=h[x][y])
                    {
                        if(finds(id[u][v])!=finds(id[x][y]))
                        {
                            cnt--;
                            fa[fa[id[x][y]]]=fa[id[u][v]];
                        }
                    }
                }
                j--;
            }
            ans[i]=cnt;
        }
        for(int i=0;i<M;i++)printf("%d ",ans[i]);
        printf("\n");

    }
    return 0;
}
