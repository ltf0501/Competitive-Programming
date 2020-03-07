#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
#define pii pair<int,int>
#define F first
#define S second
vector<int> g[maxn];
int n,m;
stack<pii> s;
int pre[maxn],dfs_clock,bcc_cnt;
bool iscut[maxn];
vector<int> bcc[maxn];
int cnt[maxn],bccno[maxn];
struct P
{
    int num,id;
    bool operator < (const P& b)const
    {
        if(num!=b.num)return num>b.num;
        return id<b.id;
    }
};
vector<P> ans;
int dfs(int u,int fa)
{
    int lowu=pre[u]=++dfs_clock;
    int ch=0;
    for(int v : g[u])if(v!=fa)
    {
        pii e=pii(u,v);
        if(!pre[v])
        {
            s.push(e);
            ch++;
            int lowv=dfs(v,u);
            lowu=min(lowu,lowv);
            if(lowv>=pre[u])
            {
                iscut[u]=1;
                bcc_cnt++;
                while(1)
                {
                    pii x=s.top();s.pop();
                    if(bccno[x.F]!=bcc_cnt)
                        bcc[bcc_cnt].push_back(x.F),bccno[x.F]=bcc_cnt;
                    if(bccno[x.S]!=bcc_cnt)
                        bcc[bcc_cnt].push_back(x.S),bccno[x.S]=bcc_cnt;
                    if(x.F==u && x.S==v)break;
                }
            }
        }
        else
        {
            s.push(e);
            lowu=min(lowu,pre[v]);
        }
    }
    if(fa<0 && ch==1)iscut[u]=0;
    return lowu;
}
void init()
{
    for(int i=0;i<n;i++)g[i].clear();
    memset(iscut,0,sizeof(iscut));
    memset(pre,0,sizeof(pre));
    memset(bccno,0,sizeof(bccno));
    dfs_clock=0;bcc_cnt=0;
    for(int i=1;i<=n;i++)bcc[i].clear();
    memset(cnt,0,sizeof(cnt));
    ans.clear();
}
main()
{
    while(scanf("%d%d",&n,&m) && n+m)
    {
        init();
        int x,y;
        while(~scanf("%d%d",&x,&y) && x>=0)
            g[x].push_back(y),g[y].push_back(x);
        dfs(0,-1);
        for(int i=1;i<=bcc_cnt;i++)
            for(int x : bcc[i])cnt[x]++;
        for(int i=0;i<n;i++)
        {
            if(iscut[i])ans.push_back((P){cnt[i],i});
            else ans.push_back((P){1,i});
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<m;i++)printf("%d %d\n",ans[i].id,ans[i].num);
        puts("");
    }
    return 0;
}
