#include<bits/stdc++.h>
using namespace std;
int d[10][10];
int cnt[10];
main()
{
    int h,w;scanf("%d%d",&h,&w);
    for(int i=0;i<10;i++)for(int j=0;j<10;j++)
        scanf("%d",&d[i][j]);
    for(int k=0;k<10;k++)
    {
        for(int i=0;i<10;i++)for(int j=0;j<10;j++)
            d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    }
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            int x;scanf("%d",&x);
            if(x>=0)cnt[x]++;
        }
    }
    int ans=0;
    for(int i=0;i<10;i++)ans+=cnt[i]*d[i][1];
    printf("%d\n",ans);
    return 0;
}
