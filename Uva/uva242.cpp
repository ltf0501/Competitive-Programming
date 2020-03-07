#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define INF 0x3f3f3f3f
int a[20][20],dp[1024],ans[20];
main()
{
    int s;
    while(scanf("%d",&s)==1 && s)
    {
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i][0]);
            for(int j=1;j<=a[i][0];j++)scanf("%d",&a[i][j]);
            memset(dp,INF,sizeof(dp));
            dp[0]=0;
            for(int j=1;j<=1024;j++)
            {
                for(int k=1;k<=a[i][0] && j>=a[i][k];k++)dp[j]=min(dp[j],dp[j-a[i][k]]+1);
                if(dp[j]>s){ans[i]=j-1;break;}
            }
        }
        /*
        for(int i=0;i<n;i++)printf("%d ",ans[i]);
        puts("");
        */
        int Ans=-1,cnt=0;
        for(int i=0;i<n;i++)
        {
            if(ans[i]>Ans){Ans=ans[i];cnt=i;}
            else if(ans[i]==Ans && a[i][0]<a[cnt][0])cnt=i;
            else if(ans[i]==Ans && a[i][0]==a[cnt][0])
            {
                int ok=0;
                for(int j=a[i][0];j>=0;j--)
                {
                    if(a[i][j]<a[cnt][j]){ok=1;break;}
                    if(a[i][j]>a[cnt][j])break;
                }
                if(ok)cnt=i;
            }
        }
        printf("max coverage =%4d :",Ans);
        for(int i=1;i<=a[cnt][0];i++)printf("%3d",a[cnt][i]);
        puts("");
    }
    return 0;
}
