#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};//¤U¤W¥k¥ª
int d[4][maxn][maxn];
int n,m;
char c[maxn][maxn];
struct P{int x,y,d;};
vector<P>ans;
int sum[2][maxn][maxn];
bool check(int x,int y)
{
    int umr=sum[0][x][y]+sum[1][x][y];
    return (umr>0)^(c[x][y]=='*')^1;
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",c[i]);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)
    {
        if(i>0)
        {
            if(c[i][j]=='*')d[0][i][j]=d[0][i-1][j]+1;
        }
        else d[0][i][j]=(c[i][j]=='*');
        if(j>0)
        {
            if(c[i][j]=='*')d[2][i][j]=d[2][i][j-1]+1;
        }
        else d[2][i][j]=(c[i][j]=='*');
    }
    for(int i=n-1;i>=0;i--)for(int j=m-1;j>=0;j--)
    {
        if(i<n-1)
        {
            if(c[i][j]=='*')d[1][i][j]=d[1][i+1][j]+1;
        }
        else d[1][i][j]=(c[i][j]=='*');
        if(j<m-1)
        {
            if(c[i][j]=='*')d[3][i][j]=d[3][i][j+1]+1;
        }
        else d[3][i][j]=(c[i][j]=='*');
    }
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(c[i][j]=='*')
    {
        int s=min({d[0][i][j],d[1][i][j],d[2][i][j],d[3][i][j]})-1;
        if(s)ans.push_back({i,j,s});
    }
    for(auto s : ans)
    {
        int x=s.x,y=s.y,d=s.d;
        sum[0][x-d][y]++,sum[0][x+d+1][y]--;
        sum[1][x][y-d]++,sum[1][x][y+d+1]--;
    }
    for(int i=1;i<n;i++)for(int j=1;j<m;j++)
        sum[0][i][j]+=sum[0][i-1][j],
        sum[1][i][j]+=sum[1][i][j-1];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)
        if(!check(i,j))return 0*puts("-1");
    printf("%d\n",ans.size());
    for(auto s : ans)printf("%d %d %d\n",s.x+1,s.y+1,s.d);
    return 0;
}
