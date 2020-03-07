#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
char c[maxn][maxn];
int n,m;
bool ok[maxn][maxn];
bool check(int x,int y){return x>=0 && x<n && y>=0 && y<m;}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",c[i]);
    for(int i=1;i<n-1;i++)for(int j=1;j<m-1;j++)
    {
        bool flag=1;
        for(int x=-1;x<=1;x++)for(int y=-1;y<=1;y++)
        {
            if(!x && !y)continue;
            if(c[i+x][j+y]=='.'){flag=0;break;}
        }
        if(flag)ok[i][j]=1;
    }
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(c[i][j]=='#')
    {
        bool flag=0;
        for(int x=-1;x<=1;x++)for(int y=-1;y<=1;y++)
        {
            if(!x && !y)continue;
            if(check(i+x,j+y) && ok[i+x][j+y]){flag=1;break;}
        }
        if(!flag)return 0*puts("NO");


    }
    puts("YES");
    return 0;
}
