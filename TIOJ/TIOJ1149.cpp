#include<bits/stdc++.h>
using namespace std;
#define maxn 105
vector<int> g[maxn];
int n,m;
int in[maxn],dfs_clock;
stack<int> s;
int sccno[maxn],scc_cnt;
int dfs(int u)
{
    int lowu=in[u]=++dfs_clock;
    s.push(u);
    for(int v : g[u])
    {
        if(!in[v])lowu=min(lowu,dfs(v));
        else if(!sccno[v])lowu=min(lowu,in[v]);
    }
    if(lowu==in[u])
    {
        scc_cnt++;
        while(1)
        {
            int x=s.top();s.pop();
            sccno[x]=scc_cnt;
            if(x==u)break;
        }
    }
    return lowu;
}
void init()
{
    for(int i=0;i<50;i++)g[i].clear();
    memset(sccno,0,sizeof(sccno));
    scc_cnt=0,dfs_clock=0;
}
main()
{
    int t;scanf("%d",&t);
    printf("%d\n",t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i=1;i<=m;i++)
        {
            char c[2],d[2];scanf("%s%s",c,d);
            int x=c[1]-'0',y=d[1]-'0';
            x--,y--;
            bool a=(c[0]=='m'),b=(d[0]=='m');
            g[(x<<1)^(a^1)].push_back((y<<1)^b);
            g[(y<<1)^(b^1)].push_back((x<<1)^a);
        }
        for(int i=0;i<2*n;i++)
            if(!in[i])dfs(i);
        bool flag=1;
        for(int i=0;i<n*2;i+=2)
            if(sccno[i]==sccno[i^1]){flag=0;break;}
        if(flag)printf("GOOD\n");
    }
    return 0;
}
