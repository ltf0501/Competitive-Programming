#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 222;

int d[MAXN][MAXN][MAXN];

int col[MAXN],num[MAXN];

int dfs(int i,int j,int k)
{
    if(i > j) return 0;
    if(d[i][j][k] != -1) return d[i][j][k];
    d[i][j][k] = dfs(i,j-1,0) + (k + num[j])*(k + num[j]);
    for(int pos = j-1;pos >= i; pos --)
    {
        if(col[pos] == col[j])
            d[i][j][k] = max(d[i][j][k],dfs(i,pos,k + num[j]) + dfs(pos + 1,j-1,0));
    }
    return d[i][j][k];
}

int main()
{
    int _;
    scanf("%d",&_);
    for(int cas = 1;cas <= _ ;cas ++)
    {
        int n;
        scanf("%d",&n);
        int tot = 0;
        memset(d,-1,sizeof(d));
        for(int i = 1;i<=n;i++)
        {
            int a;
            scanf("%d",&a);
            if(tot == 0 || a != col[tot])
            {
                d[tot][tot][0] = num[tot]*num[tot];
                tot++;
                col[tot] = a;
                num[tot] = 1;
            }
            else
            {
                num[tot]++;
            }
        }
        //for(int i = 1;i<=tot;i++)
            //printf("col[i] = %d,num[i] = %d\n",col[i],num[i]);
        printf("Case %d: %d\n",cas,dfs(1,tot,0));
    }
    return 0;
}
