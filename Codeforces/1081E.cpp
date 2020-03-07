#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
vector<int> fac[maxn];
vector<ll> ans;
void pre()
{
    for(int i=1;i<maxn;i++)
        for(ll j=1ll*i*i+i;j<maxn;j+=i)
            fac[j].push_back(i);
}
main()
{
    pre();
    int n;scanf("%d",&n);
    ll cur=0;
    for(int i=1;i<=n/2;i++)
    {
        int x;scanf("%d",&x);
        if(x%2==0 && x%4!=0)return 0*puts("No");
        bool flag=0;
        for(int i=(int)fac[x].size()-1;i>=0;i--)
        {
            int p=fac[x][i],q=x/p;//a=(p+q)/2,b=(q-p)/2=>b^2>cur
            //printf("%d %d\n",p,q);
            if((p+q)&1)continue;
            ll b=(q-p)/2,a=(p+q)/2;
            if(b*b<=cur || b==0)continue;
            ans.push_back(b*b-cur),ans.push_back(x);
            //printf("%lld %lld\n",b*b-cur,(ll)x);
            cur=a*a;flag=1;break;
        }
        if(!flag)return 0*puts("No");
    }
    puts("Yes");
    for(ll s : ans)printf("%lld ",s);
    return 0;
}
