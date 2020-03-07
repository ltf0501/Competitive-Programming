
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

pair<int,int> a[2505];
int f[2505][55];
int h[2505][55];
int cnt[2505];
int n,c,m;
void pre()
{
    sort(a+1,a+c+1);
    c=unique(a+1,a+c+1)-a-1;
    int p;
    for(int i=1;i<=c;i++)
    {
        p=i,m++;
        while(a[p].first==a[p+1].first && p<c)p++;
        for(int j=i;j<=p;++j)h[m][a[j].second]=1;
        cnt[m]=p-i+1;
        i=p;
    }
}
int dp()
{
    int k=0,ans=0x3f3f3f3f;
    memset(f,127,sizeof(f));
    for(int i=1;i<=n;i++)
        if(h[1][i])
            f[1][i]=cnt[1];
    for(int i=2;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(h[i][j])
                for(int k=1;k<=n;k++)
                {    if(h[i][k] && (cnt[i]==1 || k!=j))
                        f[i][j]=min(f[i][j],f[i-1][k]+cnt[i]-1);
                    else f[i][j]=min(f[i][j],f[i-1][k]+cnt[i]);
                }
    for(int i=1;i<=n;i++)
        ans=min(ans,f[m][i]);
    return ans*2-n-1;
}
main()
{
    int cas=0,t;
    while(scanf("%d",&n)!=EOF)
    {
        memset(cnt,0,sizeof(cnt));
        memset(h,0,sizeof(h));
        m=c=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&t);
            for(int j=1;j<=t;j++)
            {
                scanf("%d",&a[++c].first);
                a[c].second=i;
            }
        }
        pre();
        printf("Case %d: %d\n",++cas,dp());

    }
    return 0;
}

