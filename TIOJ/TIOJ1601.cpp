#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 205
main()
{
    int r[maxn];
    int n,m,cas=0;
    while(~scanf("%d%d",&n,&m))
    {
        int ans=0;
        memset(r,0,sizeof(r));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                int k;
                scanf("%d",&k);
                if(k)r[i]++;
            }
        sort(r,r+n);
        int cur=0;
        for(int i=1;i<=m;i++)
        {
            while(r[cur]<i)cur++;
            ans=max(ans,2*(i+n-cur));
        }
        printf("Case %d: %d\n",++cas,ans);
    }

    return 0;
}
