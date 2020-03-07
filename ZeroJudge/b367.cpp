#include<cstdio>
#include<algorithm>
#include<cstring>

main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int g[15][15],n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)scanf("%d",&g[i][j]);
        }
        int check=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(g[i][j]!=g[n+1-i][m+1-j]){check=0;break;}
            }
            if(!check)break;
        }
        if(check)puts("go forward");
        else puts("keep defending");
    }
    return 0;
}
