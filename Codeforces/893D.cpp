#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
int a[maxn];
ll sum[maxn],suf[maxn];
int n,d;
main()
{
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
    suf[n]=sum[n];
    for(int i=n-1;i>=1;i--)suf[i]=max(suf[i+1],sum[i]);
    //for(int i=1;i<=n;i++)printf("%d ",sum[i]);puts("");
    //for(int i=n;i>=1;i--)printf("%d ",suf[i]);puts("");
    ll add=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=0 && sum[i]+add>d){puts("-1");return 0;}
        //printf("%d %d %d\n",sum[i-1],add,suf[i]);
        if(a[i]==0)
        {
            if(sum[i-1]+add<0)
            {
                if(sum[i-1]+d<suf[i]){puts("-1");return 0;}
                cnt++;
                add+=(d-suf[i]-add);
            }
        }

    }
    printf("%d\n",cnt);
    return 0;
}
