#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 1000000+10
int n,p[maxn],s[maxn],h1[maxn],h2[maxn];
main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&p[i]);
        for(int i=1;i<=n;i++)scanf("%d",&s[i]);

        int level=s[1];
        for(int i=1;i<=n;i++)
        {
            if(p[i]>level)level=p[i];
            else if(s[i]<level)level=s[i];
            h1[i]=level;
        }

        level=s[n];
        for(int i=n;i>=1;i--)
        {
            if(p[i]>level)level=p[i];
            else if(s[i]<level)level=s[i];
            h2[i]=level;
        }
        /*
        for(int i=1;i<=n;i++)printf("%d ",h1[i]);
        printf("\n");
        for(int i=n;i>=1;i--)printf("%d ",h2[i]);
        printf("\n");
        */
        int ans=0;
        for(int i=1;i<=n;i++)ans+=min(h1[i],h2[i])-p[i];
        printf("%d\n",ans);
    }
    return 0;
}
