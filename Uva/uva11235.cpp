#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n;
int a[maxn],h[maxn];
int len[maxn<<2];
struct Q
{
    int l,r;
}seg[maxn];
void push_up(int o)
{
    len[o]=max(len[o<<1],len[o<<1|1]);
}
void build(int l,int r,int o)
{
    if(l==r)
    {
        len[o]=seg[l].r-seg[l].l+1;
        return ;
    }
    int m=(l+r)>>1;
    build(l,m,o<<1);
    build(m+1,r,o<<1|1);
    push_up(o);
}
int query(int l,int r,int o,int ql,int qr)
{
    if(ql<=l && r<=qr)return len[o];
    int m=(l+r)>>1;
    int ans=-1;
    if(ql<=m)ans=max(ans,query(l,m,o<<1,ql,qr));
    if(qr>=m+1)ans=max(ans,query(m+1,r,o<<1|1,ql,qr));
    return ans;
}
main()
{
    while(~scanf("%d",&n) && n)
    {
        int q;scanf("%d",&q);
        int cnt=0,pre=1000000000;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]!=pre)
            {
                cnt++;
                pre=a[i];
                seg[cnt].l=seg[cnt].r=i;
            }
            else seg[cnt].r=i;
            h[i]=cnt;
        }
        build(1,cnt,1);
        while(q--)
        {
            int l,r;scanf("%d%d",&l,&r);
            int pos1=h[l],pos2=h[r];
            if(pos1==pos2)printf("%d\n",r-l+1);
            else
            {
                int len1=seg[pos1].r-l+1,len2=r-seg[pos2].l+1,len3=0;
                if(pos2-pos1>1)len3=query(1,cnt,1,pos1+1,pos2-1);
                printf("%d\n",max(max(len1,len2),len3));
            }
        }
    }
    return 0;
}
