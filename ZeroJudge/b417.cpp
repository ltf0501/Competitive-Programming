#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10,maxq=1e6+10;
int a[maxn],cnt[maxn],cnt_cnt[maxn],SZ;
struct Q
{
    int l,r,B,id;
    void input(int i)
    {
        scanf("%d%d",&l,&r);
        B=l/SZ,id=i;
    }
    bool operator < (const Q& b)const
    {
        if(B!=b.B)return B<b.B;
        return r<b.r;
    }
}q[maxq];
int cur_ans=0;
int ans1[maxq],ans2[maxq];
void add(int x)
{
    cnt[x]++;
    cnt_cnt[cnt[x]-1]--;
    cnt_cnt[cnt[x]]++;
    if(cnt_cnt[cnt[x]]==1)cur_ans=max(cur_ans,cnt[x]);
}
void sub(int x)
{
    cnt[x]--;
    cnt_cnt[cnt[x]]++;
    cnt_cnt[cnt[x]+1]--;
    if(!cnt_cnt[cnt[x]+1] && cur_ans==cnt[x]+1)cur_ans--;
}
main()
{
    int n,m;scanf("%d%d",&n,&m);
    SZ=(int)sqrt(n+0.5);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)q[i].input(i);
    sort(q+1,q+m+1);
    cnt_cnt[0]=n;
    for(int i=1,L=1,R=0;i<=m;i++)
    {
        while(R<q[i].r)add(a[++R]);
        while(L>q[i].l)add(a[--L]);
        while(R>q[i].r)sub(a[R--]);
        while(L<q[i].l)sub(a[L++]);
        ans1[q[i].id]=cur_ans,ans2[q[i].id]=cnt_cnt[cur_ans];
    }
    for(int i=1;i<=m;i++)printf("%d %d\n",ans1[i],ans2[i]);
    return 0;
}
