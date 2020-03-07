#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
vector<int> g[maxn];
#define ll long long
int in[maxn],out[maxn],dfs_clock=0;
int n;
void dfs(int u,int fa)
{
    in[u]=++dfs_clock;
    for(int v : g[u])if(v!=fa)
        dfs(v,u);
    out[u]=dfs_clock;
}
ll c[3][maxn];
void update(int type,int x,int d)
{
    while(x<=dfs_clock)
    {
        c[type][x]+=d;
        x+=(x&-x);
    }
}
ll query(int type,int x)
{
    ll ret=0;
    while(x)
    {
        ret+=c[type][x];
        x-=(x&-x);
    }
    return ret;
}
main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs(1,0);
    int q;scanf("%d",&q);
    while(q--)
    {
        char s[5];scanf("%s",s);
        if(s[0]=='G')
        {
            int x,k;ll c;scanf("%d%d%lld",&x,&k,&c);
            if((x==1 && k!=2) || (in[x]==out[x] && k==2)){puts("ERROR");continue;}
            update(k,x,c);
        }
        else if(s[0]=='D')
        {
            int x,k;ll c;scanf("%d%d%lld",&x,&k,&c);
            if(query(k,out[x])-query(k,in[x]-1)<c){puts("ERROR");continue;}
            update(k,x,-c);
        }
        else
        {
            int x;scanf("%d",&x);
            printf("%lld",query(0,out[x])-query(0,in[x]-1));
            for(int i=1;i<3;i++)
                printf(" %lld",query(i,out[x])-query(i,in[x]-1));
            puts("");
        }
    }
    return 0;
}

