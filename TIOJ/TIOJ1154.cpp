#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
bool g[130][130];
bool first;
void dfs(int x1,int x2,int y1,int y2)
{
    bool flag=1;
    bool m=g[x1][y1];
    for(int i=x1;i<=x2;i++)
        for(int j=y1;j<=y2;j++)if(g[i][j]!=m){flag=0;break;}
    if(first)printf(" ");
    first=1;
    if(flag)
    {
        if(m)printf("b");
        else printf("w");
        return ;
    }
    printf("g");
    dfs(x1,(x1+x2)/2,(y1+y2)/2+1,y2);
    dfs(x1,(x1+x2)/2,y1,(y1+y2)/2);
    dfs((x1+x2)/2+1,x2,y1,(y1+y2)/2);
    dfs((x1+x2)/2+1,x2,(y1+y2)/2+1,y2);
}
main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("\n");
            for(int j=0;j<n;j++)
            {
                char c;
                scanf("%c",&c);
                g[i][j]=c-'0';
            }
        }

        first=0;
        dfs(0,n-1,0,n-1);
        puts("");
    }

    return 0;
}
