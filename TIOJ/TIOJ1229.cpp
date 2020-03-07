#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 105
char c[maxn];
vector<int> s[maxn];
int a[maxn],vis[maxn];
int l,m,n;
main()
{
    while(scanf("%d",&l)==1)
    {
        scanf("%d%d",&n,&m);
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)s[i].clear();
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        int cur=0;

        for(int i=1;i<=n;i++)
        {
            if(vis[i])continue;
            vis[i]=1;cur++;
            s[cur].push_back(i);
            int j=i;
            while(a[j]!=s[cur][0])
            {
                j=a[j];
                vis[j]=1;
                s[cur].push_back(j);
            }
        }
        /*
        for(int u=1;u<=cur;u++)
        {
            for(int i=0;i<s[u].size();i++)printf("%d ",s[u][i]);
            puts("");
        }
        */
        while(l--)
        {
            scanf("%s",c+1);
            int k=m;
            while(k--)
            {
                for(int u=1;u<=cur;u++)
                {
                    for(int i=0;i<s[u].size();i++)
                    {
                        swap(c[s[u][0]],c[s[u][i]]);
                    }
                }
            }
            for(int i=1;i<=n;i++)printf("%c",c[i]);
            puts("");
        }
    }
    return 0;
}
