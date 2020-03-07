#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define INF 10000000

main()
{
    int d,N,M,ans;
    int seat[20][2];

    while(scanf("%d%d",&N,&M)==2)
    {
        for(int i=0;i<M;i++)scanf("%d%d",&seat[i][0],&seat[i][1]);
        //for(int i=0;i<M;i++)printf("%d %d\n",seat[i][0],seat[i][1]);
        int ans=INF;
        for(int i=0;i<M;i++)
            for(int j=i+1;j<M;j++)
            {
                d=(seat[i][0]-seat[j][0])*(seat[i][0]-seat[j][0])+(seat[i][1]-seat[j][1])*(seat[i][1]-seat[j][1]);
                ans=min(ans,d);
            }
        printf("%.04f\n",sqrt(ans));
    }

    return 0;
}
