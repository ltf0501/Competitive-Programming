#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 5000+10
long long A[maxn];
main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)scanf("%lld",&A[i]);
        sort(A,A+n);
        long long ans=0;
        for(int x=0;x<=n-3;x++)
        {
            int y=x+1,z=x+2;
            while(y<=n-2 && z<=n-1)
            {
                long long y_cnt=1,z_cnt=1;
                if(A[x]+A[y]<A[z]){y++;y_cnt=1;continue;}
                if(A[x]+A[y]>A[z]){z++;z_cnt=1;continue;}
                if(A[x]+A[y]==A[z])
                {

                    while(A[x]+A[++y]==A[z] && y<=n-2)y_cnt++;
                    while(A[x]+A[y-1]==A[++z] && z<=n-1)z_cnt++;
                    long long cnt=y_cnt*z_cnt;
                   /* for(int s=y-y_cnt+1;s<=y;s++)
                        for(int t=z-z_cnt+1;t<=z;t++)printf("%d %d %d\n",x,s,t);
                    printf("\n");*/

                    ans+=cnt;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
9
1 1 1 2 2 2 3 3 3

36
*/
