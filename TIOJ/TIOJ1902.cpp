#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define B 330
struct Q
{
    int l,r,id,block;
    bool operator < (const Q& b)const
    {
        return block==b.block ? r<b.r : block<b.block;
    }
}query[maxn+5];
int n,q;
int now=0;
void add(int x)
{
    now^=x;
}
int a[maxn],ans[maxn];
main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=q;i++)
    {
        int l,r;scanf("%d%d",&l,&r);
        query[i]={l,r,i,l/B};
    }
    sort(query+1,query+q+1);
    for(int i=1,l=1,r=0;i<=q;i++)
    {
        while(r<query[i].r)add(a[++r]);
        while(l>query[i].l)add(a[--l]);
        while(r>query[i].r)add(a[r--]);
        while(l<query[i].l)add(a[l++]);
        ans[query[i].id]=now;
    }
    for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
    return 0;
}
