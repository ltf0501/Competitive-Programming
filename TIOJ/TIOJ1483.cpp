/*#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define mod 1000000007
#define maxn 1000+10
int c[maxn][maxn],dp[maxn][maxn];
int n,m;
struct node
{
    int x,y;
};
void update(int x,int y,int val)
{
    for(int i=x;i<maxn;i+=(i&-i))
        for(int j=y;j<maxn;j+=(j&-j))c[i][j]=(c[i][j]+val)%mod;
}
int query(int x,int y)
{
    int ans=0;
    for(int i=x;i>0;i-=(i&-i))
        for(int j=y;j>0;j-=(j&-j))ans=(ans+c[i][j])%mod;
    return ans;
}
vector<node> v[maxn];
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        memset(c,0,sizeof(c));
        for(int i=0;i<maxn;i++)v[i].clear();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                int x;scanf("%d",&x);
                v[x].push_back((node){i,j});
            }
        for(int i=0;i<maxn;i++)
        {
            for(int j=0;j<v[i].size();i++)dp[v[i][j].x][v[i][j].y]=1+query(v[i][j].x,v[i][j].y);
            for(int j=0;j<v[i].size();j++)update(v[i][j].x,v[i][j].y,dp[v[i][j].x][v[i][j].y]);
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)printf("%d ",dp[i][j]);
            puts("");
        }

        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)ans=(ans+dp[i][j])%mod;
        printf("%d\n",ans);
    }
    return 0;
}
*/
#include<bits/stdc++.h>
#define lowbit(x) (x&-x)
#define MOD 1000000007
using namespace std;
const int maxn=1000+10 ;

int bit[maxn][maxn] ;
void modify(int x,int y,int val)
{
    for(int i=x;i<maxn;i+=lowbit(i))
        for(int j=y;j<maxn;j+=lowbit(j))
        bit[i][j]=(bit[i][j]+val)%MOD ;
}

int query(int x,int y)
{
    int ret=0 ;
    for(int i=x;i;i-=lowbit(i))
        for(int j=y;j;j-=lowbit(j))
        ret=(ret+bit[i][j])%MOD ;
    return ret ;
}

struct P{int x,y;};
vector<P> v[maxn] ;
int ans[maxn][maxn] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        memset(bit,0,sizeof(bit)) ;
        for(int i=0;i<maxn;i++) v[i].clear() ;
        int n,m ; scanf("%d%d",&n,&m) ;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        {
            int x ; scanf("%d",&x) ;
            if(x<0) abort() ;
            v[x].push_back((P){i,j}) ;
        }
        for(int i=0;i<maxn;i++) if(!v[i].empty())
        {
            for(int j=0;j<v[i].size();j++) ans[v[i][j].x][v[i][j].y]=1+query(v[i][j].x,v[i][j].y) ;
            for(int j=0;j<v[i].size();j++) modify(v[i][j].x,v[i][j].y,ans[v[i][j].x][v[i][j].y]) ;
        }
        int Ans=0 ;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
            Ans=(Ans+ans[i][j])%MOD ;
        printf("%d\n",Ans) ;
    }
}
