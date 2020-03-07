#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
int a[maxn][2];
int st[maxn<<2][2];
void push_up(int l,int r,int o)
{
    int m=(l+r)>>1;
    for(int i=0;i<2;i++)
    {
        int tmp1=st[o<<1][i];
        if(tmp1==-1 || a[m+1][1]<a[m][tmp1]){st[o][i]=-1;continue;}
        int tmp2=a[m+1][0]>=a[m][tmp1]?0:1;
        st[o][i]=st[o<<1|1][tmp2];
    }
}
void build(int l,int r,int o)
{
    if(l==r){st[o][0]=0,st[o][1]=1;return ;}
    int m=(l+r)>>1;
    build(l,m,o<<1),build(m+1,r,o<<1|1);
    push_up(l,r,o);
}
void update(int l,int r,int o,int pos)
{
    if(l==r)return ;
    int m=(l+r)>>1;
    if(pos<=m)update(l,m,o<<1,pos);
    else update(m+1,r,o<<1|1,pos);
    push_up(l,r,o);
}
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i][0],&a[i][1]);
        if(a[i][0]>a[i][1])swap(a[i][0],a[i][1]);
    }
    int q;scanf("%d",&q);
    build(1,n,1);
    while(q--)
    {
        int l,r;scanf("%d%d",&l,&r);
        swap(a[l][0],a[r][0]);
        swap(a[l][1],a[r][1]);
        update(1,n,1,l);
        update(1,n,1,r);
        //printf("%d ",st[1][0]);
        puts(st[1][0]==-1 ? "NIE" : "TAK");
    }
    return 0;
}
