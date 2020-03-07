#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

#define MIN(x,y,z) min((x),min((y),(z)))
const int maxn=10000+10;
const int INF=0x3f3f3f3f;
int C1,C2;
int n;
vector<int>G[maxn];
int d[maxn][3][4];

int dp(int u,int fa,int m,int k)
{
    int& ans=d[u][m][k];
    if(ans!=INF)return ans;

    int res=0;
    if(k==0)
    {
        res=INF;
        int tmp=0;
        for(int i=0;i<G[u].size();i++)
        {
            if(G[u][i]!=fa)tmp+=MIN(dp(G[u][i],u,0,1),dp(G[u][i],u,1,2),dp(G[u][i],u,2,3));
        }
        for(int i=0;i<G[u].size();i++)
            if(G[u][i]!=fa)
            res=min(res,tmp-MIN(dp(G[u][i],u,0,1),dp(G[u][i],u,1,2),dp(G[u][i],u,2,3))+ dp(G[u][i],u,2,3));
    }
    else
    {
        for(int i=0;i<G[u].size();i++)
            if(G[u][i]!=fa)
            res+=MIN(dp(G[u][i],u,0,k-1),dp(G[u][i],u,1,2),dp(G[u][i],u,2,3));

        int tmp=0;
        for(int i=0;i<G[u].size();i++)
            if(G[u][i]!=fa)
            tmp += MIN(dp(G[u][i],u,0,1),dp(G[u][i],u,1,2),dp(G[u][i],u,2,3));
        for(int i=0;i<G[u].size();i++)
            if(G[u][i]!=fa)
            res=min(res,tmp-MIN(dp(G[u][i],u,0,1),dp(G[u][i],u,1,2),dp(G[u][i],u,2,3))+dp(G[u][i],u,2,3));
    }
    if(m==1)res+=C1;
    if(m==2)res+=C2;
    return ans=res;
}
main()
{
    while(scanf("%d%d%d",&n,&C1,&C2)==3 && n)
    {
        int a,b;
        for(int i=0;i<maxn;i++)G[i].clear();
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        memset(d,INF,sizeof(d));
        printf("%d\n",MIN(dp(1,-1,0,1),dp(1,-1,1,2),dp(1,-1,2,3)));
    }
    return 0;
}
