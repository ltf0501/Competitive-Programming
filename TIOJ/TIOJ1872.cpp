#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e6+5,maxp=75000,mod=1e9+7;
struct Q
{
    int l,r,id;
    void input(int i)
    {
        scanf("%d%d",&l,&r);
        id=i;
    }
    bool operator < (const Q& b)const{return r<b.r;}
}que[maxn];
struct P{int pos,cnt;};
ll pw(ll a,int n)
{
    if(n==0)return 1;
    if(n==1)return a;
    ll ret=pw(a,n>>1);
    ret=ret*ret%mod;
    if(n&1)ret=ret*a%mod;
    return ret;
}
ll inv(ll x){return pw(x,mod-2);}
ll ans[maxn];
int a[maxn],ID[maxn],cnt;
vector<int> p;
stack<P> s[maxp];
bool vis[maxn];
void prime()
{
    for(int i=2;i*i<maxn;i++)if(!vis[i])
    {
        for(int j=i*i;j<maxn;j+=i)vis[j]=1;
    }
    for(int i=2;i<=1e6;i++)if(!vis[i])ID[i]=++cnt;
    for(int i=2;i*i<maxn;i++)if(!vis[i])p.push_back(i);
}
ll bit[maxn];
void update(int x,ll d)
{
    for(int i=x;i<=1e6;i+=i&-i)bit[i]=bit[i]*d%mod;
}
ll query(int x)
{
    ll ret=1;
    for(int i=x;i;i-=i&-i)ret=ret*bit[i]%mod;
    return ret;
}
main()
{
    prime();puts("XD");
    int n,q;scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=q;i++)que[i].input(i);
    sort(que+1,que+q+1);
    int now=1;
    for(int i=1;i<=n;i++)bit[i]=1;
    for(int i=1;i<=n;i++)
    {
        int num=a[i];
        for(int P : p)if(num%P==0)
        {
            int cnt=0;
            while(num%P==0)num/=P,cnt++;
            int idx=ID[P];
            int pre_cnt=0;
            while(!s[idx].empty() && s[idx].top().cnt<=cnt)
            {
                update(s[idx].top().pos,inv(pw(P,s[idx].top().cnt-pre_cnt)));
                pre_cnt=s[idx].top().cnt;
                s[idx].pop();
            }
            s[idx].push({i,cnt});
            update(i,pw(P,cnt));
        }
        if(num!=1)
        {
            int idx=ID[num];
            int pre_cnt=0;
            while(!s[idx].empty() && s[idx].top().cnt<=1)
            {
                update(s[idx].top().pos,inv(pw(num,s[idx].top().cnt-pre_cnt)));
                pre_cnt=s[idx].top().cnt;
                s[idx].pop();
            }
            s[idx].push({i,1});
            update(i,pw(num,1));
        }
        //printf("%lld\n",query(i));
        while(now<=q && que[now].r==i)
        {
            ans[que[now].id]=query(i)*inv(query(que[now].l-1))%mod;
            now++;
        }
    }
    for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
    return 0;
}
