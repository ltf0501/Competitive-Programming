#include<cstdio>

main()
{
    int n;
    int A[10]={0,1,2,3,4,5,6,7,8,10};
    while(scanf("%d",&n)==1)
    {
        int C[10];
        for(int i=1;i<=9;i++)scanf("%d",&C[i]);
        n/=8;
        int ans=0,sol=1;
        for(;;)
        {
            int i;
            for(i=1;i<=9;i++)if(C[i])break;
            if(i==10)break;

            int dp[100]={},sour[100][2];
            dp[0]=1;
            for(i=9;i>=1;i--)
            {
                if(C[i])
                {
                    for(int j=n;j>=0;j--)
                    {
                        if(dp[j]==0)
                        {
                            for(int k=1;k<=C[i];k++)
                            {
                                if(j-k*A[i]<0)continue;
                                if(dp[j-k*A[i]])
                                {
                                    dp[j]=1;
                                    sour[j][0]=i;
                                    sour[j][1]=k;
                                    break;
                                }
                            }
                        }
                    }
                }
            }

            int tmp=n;
            while(tmp>=0 &&dp[tmp]==0)tmp--;
            if(tmp==0){sol=0;break;}

            while(tmp)
            {
                C[sour[tmp][0]]-=sour[tmp][1];
                tmp-=A[sour[tmp][0]]*sour[tmp][1];
            }
            ans++;
        }
        if(sol)printf("%d\n",ans);
        else puts("NO SOLUTION!!");
    }
    return 0;
}
