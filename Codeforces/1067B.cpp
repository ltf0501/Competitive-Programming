#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
vector<int> g[maxn],tmp;
queue<int> q;
int n,k;
int deg1[maxn],deg2[maxn];
bool vis[maxn];
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
        deg1[x]++,deg1[y]++;
        deg2[x]++,deg2[y]++;
    }
    int cnt=n,cal=0;
    for(int i=1;i<=n;i++)if(deg1[i]==1)q.push(i);
    while(cnt>1)
    {
        while(!q.empty())
        {
            int u=q.front();q.pop();
            if(vis[u])continue;
            vis[u]=1,cnt--;
            for(int v : g[u])
            {
                if(!vis[v])
                {
                    deg2[v]--;
                    if(deg2[v]==1)tmp.push_back(v);
                }

            }
        }
        cal++;
        for(int u : tmp)if(deg1[u]-deg2[u]<3)return 0*puts("No");
        for(int u : tmp){q.push(u);}
        tmp.clear();
    }
    if(cnt==1 && cal==k)puts("Yes");
    else puts("No");
    return 0;
}
