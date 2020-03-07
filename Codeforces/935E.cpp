#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
#define INF 100000000
struct node
{
    node *l,*r;
    int val,num;
    int mi[105],mx[105];
    node(int v=-1)
    {
        l=r=NULL;
        val=v;
        num=0;
    }
}*root;
char c[maxn];
int a,b,n;
node *build(int l,int r)
{
    if(c[l]!='(')
    {
        node *o=new node(c[l]-'0');
        return o;
    }
    int cnt=0;
    node *o=new node();
    for(int i=l+1;i<r;i++)
    {
        if(c[i]=='(')cnt++;
        else if(c[i]==')')cnt--;
        if(cnt==0 && c[i]=='?')
        {
            o->l=build(l+1,i-1);
            o->r=build(i+1,r-1);
            o->num=o->l->num+o->r->num+1;
            return o;
        }
    }
}
void dfs1(node *o)//a<b
{
    if(o->val>=0)
    {
        o->mi[0]=o->mx[0]=o->val;
        for(int i=1;i<=100;i++)
            o->mi[i]=INF,o->mx[i]=-INF;
        return ;
    }
    dfs1(o->l),dfs1(o->r);
    for(int i=0;i<=100;i++)
    {
        o->mi[i]=INF,o->mx[i]=-INF;
        if(i>o->num)continue;
        for(int j=0;j<=min(i-1,o->l->num);j++)//+
        {
            int k=i-1-j;
            if(k>o->r->num || k>100)continue;
            o->mi[i]=min(o->mi[i],o->l->mi[j]+o->r->mi[k]);
            o->mx[i]=max(o->mx[i],o->l->mx[j]+o->r->mx[k]);
        }
        for(int j=0;j<=min(i,o->l->num);j++)//-
        {
            int k=i-j;
            if(k>o->r->num || k>100)continue;
            o->mi[i]=min(o->mi[i],o->l->mi[j]-o->r->mx[k]);
            o->mx[i]=max(o->mx[i],o->l->mx[j]-o->r->mi[k]);
        }
    }
}
void dfs2(node *o)//a>b
{
    if(o->val>=0)
    {
        o->mi[0]=o->mx[0]=o->val;
        for(int i=1;i<=100;i++)
            o->mi[i]=INF,o->mx[i]=-INF;
        return ;
    }
    dfs2(o->l),dfs2(o->r);
    for(int i=0;i<=100;i++)
    {
        o->mi[i]=INF,o->mx[i]=-INF;
        if(i>o->num)continue;
        for(int j=0;j<=min(i,o->l->num);j++)//+
        {
            int k=i-j;
            if(k>o->r->num || k>100)continue;
            o->mi[i]=min(o->mi[i],o->l->mi[j]+o->r->mi[k]);
            o->mx[i]=max(o->mx[i],o->l->mx[j]+o->r->mx[k]);
        }
        for(int j=0;j<=min(i-1,o->l->num);j++)//-
        {
            int k=i-1-j;
            if(k>o->r->num || k>100)continue;
            o->mi[i]=min(o->mi[i],o->l->mi[j]-o->r->mx[k]);
            o->mx[i]=max(o->mx[i],o->l->mx[j]-o->r->mi[k]);
        }
    }
}
/*
void print(node *o)
{
    if(o->l)print(o->l);
    puts("");
    for(int i=0;i<=2;i++)printf("%d ",o->mx[i]);puts("");
    for(int i=0;i<=2;i++)printf("%d ",o->mi[i]);puts("");
    if(o->r)print(o->r);
}
*/
main()
{
    scanf("%s",c);
    n=strlen(c);
    scanf("%d%d",&a,&b);
    root=build(0,n-1);
    if(a<b)
    {
        dfs1(root);
        //print(root);
        printf("%d\n",root->mx[a]);
    }
    else
    {
        dfs2(root);
        //print(root);
        printf("%d\n",root->mx[b]);
    }
    return 0;
}
