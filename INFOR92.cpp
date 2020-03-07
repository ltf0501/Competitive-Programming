#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int N=(int)5e6;
#define ll long long
int phi[N+1];
bool isnot_p[N+1];
ll S[N+1];
vector<int> p;
vector<pair<ll,ll> > ans[N+1];
ll cnt=0;
void pre()
{
    phi[1]=1;
    for(int i=2;i<=N;i++)
    {
        if(!isnot_p[i])
        {
            phi[i]=i-1;
            p.push_back(i);
        }
        for(int j=0;j<(int)p.size() && 1ll*i*p[j]<=N;j++)
        {
            isnot_p[i*p[j]]=1;
            if(i%p[j]==0)
            {
                phi[i*p[j]]=phi[i]*p[j];
                break;
            }
            else phi[i*p[j]]=phi[i]*(p[j]-1);
        }
    }
    for(int i=1;i<=N;i++)S[i]=(S[i-1]+phi[i])%mod;
    //for(int i=1;i<=50;i++)printf("%lld ",S[i]);puts("");
}
ll get_ans(ll n)
{
    ll idx=n%(N+1);
    for(int i=0;i<ans[idx].size();i++)
        if(ans[idx][i].first==n)
            return ans[idx][i].second;
    return -1;
}
ll cal(ll n)
{
    //printf("n = %lld\n",n);
    //cnt++;
    if((ll)n<=(ll)N)return S[n];
    ll ret=get_ans(n);
    if(ret>0)return ret;
    if(n%2==0)ret=1ll*(n/2)%mod*((n+1)%mod)%mod;
    else ret=1ll*((n+1)/2)%mod*(n%mod)%mod;
    for(ll i=2,j;i<=n;i=j+1)
    {
        j=n/(n/i);
        ret=(ret-1ll*(j-i+1)*cal(n/i)%mod)%mod;
        if(ret<0)ret+=mod;
    }
    ll idx=n%(N+1);
    ans[idx].push_back(make_pair(n,ret));
    return ret;
}
main()
{
    pre();
    //for(int i=1;i<=50;i++)printf("%lld ",cal(i));puts("");
    ll n;scanf("%lld",&n);
    printf("%lld\n",(cal(n)+mod-1)%mod);
    //printf("%lld\n",cnt);
    return 0;
}
