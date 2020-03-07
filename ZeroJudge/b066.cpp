#include<cstdio>
#include<algorithm>
#include<cstring>
int dp[8192]={};/*0 win, 1 unsure*/
int LK[13][7]={
        {2,3,-1},
        {2,5,-1},
        {0,1,3,5,6,-1},
        {0,2,4,6,7,-1},
        {3,7,-1},
        {1,2,6,8,9,-1},
        {2,3,5,7,9,10,-1},
        {3,4,6,10,11,-1},
        {5,9,-1},
        {5,6,8,10,12,-1},
        {6,7,9,11,12,-1},
        {7,10,-1},
        {9,10,-1}
};
void Build()
{
    int tn,t;
    for(int a=1;a<=8191;a++)
    {
        tn=a;
        for(int b=0;b<13;b++)
        {
            t=tn&(1<<b);
            if(t==0)
            {
                t=tn|(1<<b);
                dp[t]|=!dp[tn];
            }
        }
        for(int b=0;b<13;b++)
            for(int c=0;LK[b][c]>=0;c++)
            {
                t=tn&((1<<b)|(1<<LK[b][c]));
                if(t==0)
                {
                    t=tn|(1<<b)|(1<<LK[b][c]);
                    dp[t]|=!dp[tn];
                }
            }
    }
}
main()
{
    Build();
    int n,x,a;
    while(scanf("%d",&n)==1)
    {
        while(n--)
            scanf("%d",&x),printf("%d ",dp[x]);
        puts("");
    }
    return 0;
}
