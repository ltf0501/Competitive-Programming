#include<bits/stdc++.h>
using namespace std;
#define maxn (1<<11)+1
int a[maxn][maxn],now=-1;
void dfs(int x,int y,int n,int px,int py,int qx,int qy,int rx,int ry)
{
    if(n==1)
    {
        a[x][y]=++now;
        a[x+px][y+py]=++now;x+=px,y+=py;
        a[x+qx][y+qy]=++now;x+=qx,y+=qy;
        a[x+rx][y+ry]=++now;
        return ;
    }
    dfs(x,y,n-1,py,px,qy,qx,ry,rx);
    x+=px*(1<<(n-1)),y+=py*(1<<(n-1));
    dfs(x,y,n-1,px,py,qx,qy,rx,ry);
    x+=qx*(1<<(n-1)),y+=qy*(1<<(n-1));
    dfs(x,y,n-1,px,py,qx,qy,rx,ry);
    x+=qx*((1<<(n-1))-1)+rx,y+=qy*((1<<(n-1))-1)+ry;
    dfs(x,y,n-1,-py,-px,-qy,-qx,-ry,-rx);
}
main()
{
    int n;scanf("%d",&n);
    if(!n){puts("0");return 0;}
    dfs(1,1,n,1,0,0,1,-1,0);
    for(int i=1;i<=(1<<n);i++)
    {
        for(int j=1;j<=(1<<n);j++)printf("%d ",a[i][j]);
        puts("");
    }
    return 0;
}
