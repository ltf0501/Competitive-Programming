#include<bits/stdc++.h>
using namespace std;
#define maxn 300010
int a[maxn];
vector<int> v;
int mex[maxn],cnt[maxn],ans[maxn];
struct blabla{int a,b,c;}bla[maxn];
struct Q
{
    int l,r,t,b1,b2,id;
    bool operator < (const Q& b)const
    {
        if(b1!=b.b1)return b1<b.b1;
        if(b.b2!=b.b2)return b2<b.b2;
        return t<b.t;
    }
}q[maxn];
struct M{int x,old,nw;}m[maxn];
void add(int x)
{
    mex[cnt[x]]--;
    cnt[x]++;
    mex[cnt[x]]++;
}
void sub(int x)
{
    mex[cnt[x]]--;
    cnt[x]--;
    mex[cnt[x]]++;
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
    int SZ=(int)pow(n,2.0/3);SZ=max(SZ,1);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),v.push_back(a[i]);
    for(int i=1;i<=tt;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a==2)v.push_back(c);
        bla[i]=(blabla){a,b,c};
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for(int i=1;i<=n;i++)a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
    int now=0,t=-1;
    for(int i=1;i<=tt;i++)
    {
        int type=bla[i].a;
        if(type==1)
        {
            int l=bla[i].b,r=bla[i].c;
            q[++now]=(Q){l,r,t,l/SZ,r/SZ,i};
        }
        else
        {
            int x=bla[i].b,y=bla[i].c;
            y=lower_bound(v.begin(),v.end(),y)-v.begin()+1;
            m[++t]=(M){x,a[x],y};
            a[x]=y;
        }
    }
    sort(q+1,q+now+1);
    memset(ans,-1,sizeof(ans));
    for(int i=1,L=1,R=0;i<=now;i++)
    {
        while(R<q[i].r)add(a[++R]);
        while(L>q[i].l)add(a[--L]);
        while(R>q[i].r)sub(a[R--]);
        while(L<q[i].l)sub(a[L++]);
        while(q[i].t>t)addtime(++t,L,R);
        while(q[i].t<t)subtime(t--,L,R);
        for(int j=1;;j++)if(!mex[j])
        {
            ans[q[i].id]=j;break;
        }
    }
    for(int i=1;i<=tt;i++)if(ans[i]!=-1)printf("%d\n",ans[i]);
    return 0;
}
