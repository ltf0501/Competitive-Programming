#include<bits/stdc++.h>
using namespace std;
#define maxn 40010
#define maxq 400010
#define ll long long
const int mod=1e9+7;
int a[maxn];
vector<int> v;
int n,T;
struct Q
{
    int l,r,id,block;
    bool operator < (const Q& b)const
    {
        if(block!=b.block)return block<b.block;
        return r<b.r;
    }
}q[maxq];
ll ans[maxq],cur_ans;
int cnt[maxn];
void add(int x)
{
    cur_ans=(cur_ans+1ll*v[x]*(2*cnt[x]+1)%mod)%mod;
    cnt[x]++;
}
void sub(int x)
{
    cur_ans=(cur_ans-1ll*v[x]*(2*cnt[x]-1)%mod+mod)%mod;
    cnt[x]--;
}
main()
{
    scanf("%d%d",&n,&T);
    int SZ=(int)(sqrt(n+0.5)*1.4);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),v.push_back(a[i]);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for(int i=1;i<=n;i++)a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin();
    for(int i=1;i<=T;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        x++;
        q[i]=(Q){x,y,i,x/SZ};
    }
    sort(q+1,q+T+1);
    for(int i=1,L=1,R=0;i<=T;i++)
    {
        while(R<q[i].r)add(a[++R]);
        while(L>q[i].l)add(a[--L]);
        while(R>q[i].r)sub(a[R--]);
        while(L<q[i].l)sub(a[L++]);
        ans[q[i].id]=cur_ans;
    }
    for(int i=1;i<=T;i++)printf("%lld\n",ans[i]);
    return 0;
}
