#include<bits/stdc++.h>
using namespace std;
#define maxn 50010
#define maxm 1000010
const int SZ=35;
struct Q
{
    int l,r,t,b1,b2,id;
    bool operator < (const Q& b)const
    {
        if(b1!=b.b1)return b1<b.b1;
        if(b2!=b.b2)return b2<b.b2;
        return t<b.t;
    }
}q[maxn];
struct M{int x,old,nw;}m[maxn];
int a[maxn],id[maxn];
int ans[maxn],cnt[maxm],cur_ans=0;
void add(int x)
{
    if(!cnt[x])cur_ans++;
    cnt[x]++;
}
void sub(int x)
{
    if(cnt[x]==1)cur_ans--;
    cnt[x]--;
}
void addtime(int t,int l,int r)
{
    if(l<=m[t].x && m[t].x<=r)
        sub(m[t].old),add(m[t].nw);
    a[m[t].x]=m[t].nw;
}
void subtime(int t,int l,int r)
{
    if(l<=m[t].x && m[t].x<=r)
        sub(m[t].nw),add(m[t].old);
    a[m[t].x]=m[t].old;
}
main()
{
    int n,tt;scanf("%d%d",&n,&tt);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    memset(ans,-1,sizeof(ans));
    int now=0,t=-1;
    for(int i=1;i<=tt;i++)
    {
        char c[2];
        scanf("%s",c);
        int x,y;scanf("%d%d",&x,&y);
        x++;
        if(c[0]=='Q')
        {
            q[++now]=(Q){x,y,t,x/SZ,y/SZ,i};
        }
        else
        {
            m[++t]=(M){x,a[x],y};
            a[x]=y;
        }
    }
    sort(q+1,q+now+1);
    for(int i=1,L=1,R=0;i<=now;i++)
    {
        //printf("%d\n",q[i].id);
        while(R<q[i].r)add(a[++R]);
        while(L>q[i].l)add(a[--L]);
        while(R>q[i].r)sub(a[R--]);
        while(L<q[i].l)sub(a[L++]);
        while(q[i].t>t)addtime(++t,L,R);
        while(q[i].t<t)subtime(t--,L,R);
        ans[q[i].id]=cur_ans;
        //printf("%d %d\n",i,cur_ans);
    }
    for(int i=1;i<=tt;i++)if(ans[i]!=-1)printf("%d\n",ans[i]);
    return 0;
}
