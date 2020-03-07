#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 100000+10
int sum[maxn],tmax[maxn],n;
main()
{
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        memset(sum,0,sizeof(sum));
        memset(tmax,0,sizeof(tmax));
        int a,b,c;
        scanf("%d",&n);
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            sum[a]+=c;
            sum[b]+=c;
            tmax[a]=max(tmax[a],c);
            tmax[b]=max(tmax[b],c);
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            if(tmax[i]>sum[i]-tmax[i])ans+=2*tmax[i]-sum[i];
            else if(sum[i]&1)ans++;
        }
        printf("Case #%d: %lld\n",++cas,ans>>1);

    }
    return 0;
}
