#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 100000+10
int n,s,A[maxn],B[maxn];
main()
{

    while(scanf("%d%d",&n,&s)==2)
    {
        B[0]=0;
        for(int i=1;i<=n;i++){scanf("%d",&A[i]);B[i]=B[i-1]+A[i];}
        //對j=1~n取i最大使Bi<Bj-S
        int cur=1;
        int ans=n+1;
        for(int j=1;j<=n;j++)
        {
            if(B[cur-1]>B[j]-s)continue;
            while(B[cur]<=B[j]-s)cur++;
            ans=min(ans,j-cur+1);
        }
        printf("%d\n",ans==n+1?0:ans);
    }
    return 0;
}
