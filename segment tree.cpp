#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int mx[maxn*3],a[maxn];
void push_up(int id)
{
    mx[id]=max(mx[id<<1],mx[id<<1|1]);
}
void update(int l,int r,int id,int p,int x)//把a[p]改成x
{
    if(l==r)//表示區間內只剩一個數,直接修改
    {
        mx[id]=x;
        return ;
    }
    int m=(l+r)>>1;//m=(l+r)/2
    if(p<=m)update(l,m,id<<1,p,x);//若a[p]在區間[l,m]中則在[l,m]修改
    else update(m+1,r,id<<1|1,p,x);//否則在[m+1,r]修改
    push_up(id);//更新本區間的內容
}
int query(int l,int r,int id,int ql,int qr)//查詢[ql,qr]中最大值
{
    if(ql<=l && r<=qr)return mx[id];//目前區間完全包含在查詢區間內 直接返回
    int m=(l+r)>>1;
    int ans=0;
    if(ql<=m)ans=max(ans,query(l,m,id<<1,ql,qr));//ql<=m表示查詢區間有一部份在目前區間左半邊 遞迴找到這部分最大值
    if(m<qr)ans=max(ans,query(m+1,r,id<<1|1,ql,qr));//同上
    return ans;
}
void init()
{
    memset(mx,0,sizeof(mx));
}
main()
{
    int n;
    while(~scanf("%d",&n))
    {
        init();
        for(int i=1;i<=n;i++)//建立線段樹
        {
            scanf("%d",&a[i]);
            update(1,n,1,i,a[i]);
        }
        int q;scanf("%d",&q);
        while(q--)
        {
            int c,x,y;scanf("%d%d%d",&c,&x,&y);
            if(c==1)
            {
                update(1,n,1,x,y);//在[1,n]中修改a[x]=y
            }
            else
            {
                printf("%d\n",query(1,n,1,x,y));//在[1,n]中找到a[x]~a[y]最大值
            }
        }
    }
    return 0;
}
/*
Practice 1
請估計 update 和 query複雜度
Practice 2
請把建立線段樹時間改成O(n)
Practice 3
改成查詢區間和
*/
