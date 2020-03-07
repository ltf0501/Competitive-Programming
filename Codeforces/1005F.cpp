#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define pii pair<int,int>
#define F first
#define S second
vector<int> pre[maxn],v;
vector<pii> g[maxn];
int d[maxn];
int n,m,k;
queue<int> q;
vector<vector<int> > ans;
void dfs(int now)
{
    if(!k)return ;
    if(now==n+1)
    {
        k--;
        ans.push_back(v);
        return ;
    }
    for(int id : pre[now])
    {
        v[id]=1,dfs(now+1),v[id]=0;
    }
}
main()
{
    scanf("%d%d%d",&n,&m,&k);
    v.resize(m);
    for(int i=0;i<m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(pii(y,i)),g[y].push_back(pii(x,i));
    }
    q.push(1);
    for(int i=2;i<=n;i++)d[i]=maxn;
    while(!q.empty())
    {
        int x=q.front();q.pop();
        //printf("%d\n",x);
        for(pii u : g[x])
        {
            //printf("%d ",u.F);
            if(d[u.F]>d[x]+1)
            {
                d[u.F]=d[x]+1;
                pre[u.F].clear();
                pre[u.F].push_back(u.S);
                q.push(u.F);
            }
            else if(d[u.F]==d[x]+1)pre[u.F].push_back(u.S);
        }
    }
   // for(int i=1;i<=n;i++)printf("%d ",d[i]);
    dfs(2);
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
    {
        for(int j : ans[i])printf("%d",j);puts("");
    }
    return 0;
}
