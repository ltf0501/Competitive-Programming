#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>
using namespace std;
#define maxn 100000+10
int p[111],r[111],A[maxn],mi[maxn*4];
char op[111];
void pushup(int id)
{
    mi[id]=min(mi[id*2],mi[id*2+1]);
}
void build(int l,int r,int id)
{
    if(l==r)
    {
        mi[id]=A[l];
        return ;
    }
    int m=l+(r-l)/2;
    build(l,m,id*2);
    build(m+1,r,id*2+1);
    pushup(id);
}
void update(int x,int v,int l,int r,int id)
{
    if(l==r)
    {
        A[l]=mi[id]=v;
        return ;
    }
    int m=l+(r-l)/2;
    if(x<=m)update(x,v,l,m,id*2);
    else update(x,v,m+1,r,id*2+1);
    pushup(id);
}
int query(int L,int R,int l,int r,int id)
{
    if(L<=l && r<=R)return mi[id];
    int ans=maxn;
    int m=l+(r-l)/2;
    if(L<=m)ans=min(ans,query(L,R,l,m,id*2));
    if(m<R)ans=min(ans,query(L,R,m+1,r,id*2+1));
    return ans;
}
main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&A[i]);
    build(1,n,1);
    while(q--)
    {
        scanf("%s",op);
        int k=0,len=strlen(op);
        p[0]=0;
        for(int i=6;i<len;i++)
            if(isdigit(op[i]))
                p[k]=p[k]*10+op[i]-'0';
            else p[++k]=0;
        if(op[0]=='q')
            printf("%d\n",query(p[0],p[1],1,n,1));
        else
        {
            for(int i=0;i<k;i++)
                r[i]=A[p[i]];
            for(int i=0;i<k;i++)
                update(p[i],r[(i+1)%k],1,n,1);
        }
    }
    return 0;
}
