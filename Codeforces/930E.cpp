#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
const int mod=1e9+7;
int k,n,m;
int al[maxn],ar[maxn],bl[maxn],br[maxn];
int mx[2][maxn<<2];
ll dp[3][maxn<<2],s[2][maxn<<2];
vector<int> v;
ll pw(ll a,int n)
{
    int ret=1;
    while(n)
    {
        if(n&1)ret=ret*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ret;
}
main()
{
    scanf("%d%d%d",&k,&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&al[i],&ar[i]);
        v.push_back(al[i]),v.push_back(++ar[i]);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&bl[i],&br[i]);
        v.push_back(bl[i]),v.push_back(++br[i]);
    }
    v.push_back(1),v.push_back(k+1);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    int tot=v.size()-1;
    for(int i=1;i<=n;i++)
    {
        al[i]=lower_bound(v.begin(),v.end(),al[i])-v.begin()+1;
        ar[i]=lower_bound(v.begin(),v.end(),ar[i])-v.begin();
        mx[0][ar[i]]=max(mx[0][ar[i]],al[i]);
    }
    for(int i=1;i<=m;i++)
    {
        bl[i]=lower_bound(v.begin(),v.end(),bl[i])-v.begin()+1;
        br[i]=lower_bound(v.begin(),v.end(),br[i])-v.begin();
        mx[1][br[i]]=max(mx[1][br[i]],bl[i]);
    }
    dp[0][0]=s[0][0]=s[1][0]=1;
    int now1=0,now2=0;
    for(int i=1;i<=tot;i++)
    {
        dp[0][i]=(dp[0][i-1]+dp[1][i-1]+dp[2][i-1])*(pw(2,v[i]-v[i-1])-2)%mod;
        now1=max(now1,mx[0][i]);
        if(now1<i)dp[1][i]=(s[1][i-1]-s[1][now1]+dp[0][now1]+dp[2][now1]+mod)%mod;
        now2=max(now2,mx[1][i]);
        if(now2<i)dp[2][i]=(s[0][i-1]-s[0][now2]+dp[0][now2]+dp[1][now2]+mod)%mod;
        s[0][i]=(s[0][i-1]+dp[0][i]+dp[1][i])%mod;
        s[1][i]=(s[1][i-1]+dp[0][i]+dp[2][i])%mod;
    }
    ll ans=(dp[0][tot]+dp[1][tot]+dp[2][tot])%mod;
    printf("%lld\n",ans);
    return 0;
}
