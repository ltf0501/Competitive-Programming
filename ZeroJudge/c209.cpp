#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool a[105][60];
int time[60];
int h[105][60];
bool dfs(int l,int r,int cur)
{
    if(l==r)return 1;
    vector<int> block[105];
    int c[105][2],H[105];
    int cnt=0,hi=-1;
    for(int i=l;i<=r;i++)
    {
        if(h[i][cur]!=hi)block[++cnt].push_back(i),H[cnt]=h[i][cur],c[cnt][0]=c[cnt][1]=i,hi=h[i][cur];
        else block[cnt].push_back(i),c[cnt][1]=i;
    }
    for(int i=1;i<cnt;i++)
    {
        if(H[i]<H[i+1])
        {

        }
        else
        {

        }
    }
    return 1;
}
main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<60;i++)time[i]=-1;
    for(int i=0;i<n;i++)
    {
        ll x;scanf("%lld",&x);
        for(int j=0;j<60;j++)if(x&(1ll<<j))
        {
            a[i][j]=1;
            for(int k=j;k<60;k++)h[i][k]=j;
        }
    }
    ll ans=1;
    int now=n-1;
    bool flag=1;
    for(int i=59;i>=0;i--)
    {
        bool ok=0;
        int change=-1;
        for(int j=0;j<=now;j++)
        {
            if(a[j][i] && !ok){change=j,ok=1;continue;}
            if(ok && (!a[j][i])){flag=0;break;}
        }
        int check;
        if(!flag)break;
        if(change==0 || change==-1)ans*=2,check=2;
        else now=change-1,check=1;
        printf("%d: %d\n",i,check);
    }
    if(flag)printf("%lld\n",ans);
    else puts("0");
    return 0;
}
