#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int a[maxn];
bool vis[maxn];
int n,k;
struct link
{
    int l,r,dis;
    bool operator < (const link& b)const
    {
        if(dis!=b.dis)return dis<b.dis;
        return l<=b.l || (l==b.l && r<=b.r);
    }
    bool operator == (const link& b)const
    {
        if(l==b.l && r==b.r && dis==b.dis)return 1;
        return 0;
    }
};
/*
struct node
{
    link val;
    int r;
    node *ch[2];
    node(link v)
    {
        val=v;
        ch[0]=ch[1]=NULL;
        r=rand();
    }
};
void rot(node* &o,int d)
{
    node* k=o->ch[d^1];
    o->ch[d^1]=k->ch[d];
    k->ch[d]=o;
    o=k;
}
void insrt(node* &o,link x)
{
    if(o==NULL){o=new node(x);return ;}
    int d=x<o->val ? 0 : 1;
    insrt(o->ch[d],x);
    if(o->ch[d]->r>o->r)rot(o,d^1);
}
void remov(node* &o,link x)
{
    if(x==o->val)
    {
        if(o->ch[0]==NULL)o=o->ch[1];
        else if(o->ch[1]==NULL)o=o->ch[0];
        else
        {
            int d2=(o->ch[0]->r>o->ch[1]->r) ? 1 : 0;
            rot(o,d2);remov(o->ch[d2],x);
        }
        return ;
    }
    int d=x<o->val ? 0 : 1;
    if(o->ch[d])remov(o->ch[d],x);
}
link query_min(node *root)
{
    if(!root->ch[0])return root->val;
    return query_min(root->ch[0]);
}
node *root;
*/
int le[maxn],ri[maxn],val[maxn];
/*
le[i]為i所在鍊中如果i是右邊,則左邊為le[i]
ri[i]反之
val[i]為以i為左邊的鍊的鍊長
*/
set<link> s;
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)le[i]=i-1,ri[i]=(i+1)%(n+1),val[i]=a[i+1]-a[i];
    val[n]=0;
    for(int i=1;i<n;i++)s.insert((link){i,i+1,a[i+1]-a[i]});
    int ans=0;
    int cnt=0;
    while(cnt<k)
    {
        link t=*s.begin();
        int l=t.l,r=t.r;
        s.erase(s.begin());
        if(vis[l] || vis[r])continue;
        vis[l]=1,vis[r]=1;
        cnt++;
        ans+=t.dis;
        int dis1=val[le[l]],dis2=val[r];
        int flag=0;
        int ll=le[l],rr=ri[r];
        if(ll)s.erase((link){ll,l,dis1}),flag++;
        if(rr)s.erase((link){r,rr,dis2}),flag++;
        if(flag==2)s.insert((link){ll,rr,dis1-t.dis+dis2}),ri[ll]=rr,le[rr]=ll,val[ll]=dis1-t.dis+dis2;
    }
    printf("%d\n",ans);
    return 0;
}
