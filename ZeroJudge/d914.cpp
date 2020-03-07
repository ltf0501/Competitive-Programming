#include<cstdio>

main()
{
    int n,m;
    while(scanf("%d",&n)==1)
    {
        int MapN[20][20]={0},MapM[20][20]={0};
        for(int i=0;i<n;i++)
        {
            int x,y,c;
            scanf("%d%d%d",&x,&y,&c);
            MapN[x][y]=c+1;
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            int x,y,c;
            scanf("%d%d%d",&x,&y,&c);
            MapM[x][y]=c+1;
        }
        int ans=0;
        for(int i=0;i<20;i++)
            for(int j=0;j<20;j++)
                if((MapN[i][j]==1 && MapM[i][j]==2) || (MapN[i][j]==2 && MapM[i][j]==1))ans+=2;
                else if((MapN[i][j]==1 && MapM[i][j]==0) || (MapN[i][j]==2 && MapM[i][j]==0) ||
                        (MapN[i][j]==0 && MapM[i][j]==1) || (MapN[i][j]==0 && MapM[i][j]==2))
                        ans++;

        printf("%d\n",ans);
    }
    return 0;
}
