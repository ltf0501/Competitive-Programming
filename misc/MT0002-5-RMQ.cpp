#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1000010
ll a[maxn],sum[maxn];
ll mx[20][maxn];
int n;
ll k;
void build()
{
    for(int i=1;i<=n;i++)mx[0][i]=a[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+j-1<=n;i++)mx[j][i]=max(mx[j-1][i],mx[j-1][i+(1<<(j-1))]);
}
ll RMQ(int l,int r)
{
    int k=0;
    while((1<<(k+1))<=r-l+1)k++;
    return max(mx[k][l],mx[k][r-(1<<k)+1]);
}
bool check(int s)
{
    for(int i=1;i+s-1<=n;i++)
    {
        ll mx=RMQ(i,i+s-1);
        if(mx*s-(sum[i+s-1]-sum[i-1])<=k)return 1;
    }
    return 0;
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d %lld",&n,&k);
        memset(mx,0,sizeof(mx));
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]),sum[i]=sum[i-1]+a[i];
        build();
        int l=1,r=n+1;
        while(r-l>1)
        {
            int m=(l+r)>>1;
            if(check(m))l=m;
            else r=m;
        }
        printf("%d\n",l);
    }
    return 0;
}

