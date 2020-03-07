#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 100+5
int n,r;
int g[maxn][maxn],cnt[maxn];
main()
{
    while(scanf("%d%d",&n,&r)==2)
    {
        memset(g,0,sizeof(g));
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=r;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            g[a][b]=g[b][a]=1;
            cnt[a]++;cnt[b]++;
        }
        int p;scanf("%d",&p);
        while(p--)
        {
            int k,u,v;
            scanf("%d",&k);
            if(k==1)
            {
                scanf("%d",&u);
                printf("%d\n",cnt[u]);
            }
            else if(k==2)
            {
                scanf("%d%d",&u,&v);
                if(g[u][v])puts("Yes");
                else puts("No");
            }
        }
    }
    return 0;
}
