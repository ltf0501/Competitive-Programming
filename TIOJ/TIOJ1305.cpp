#include<cstdio>
#include<algorithm>
#include<ctime>
using namespace std;

struct node
{
    int val,sz,r;
    node* ch[2];
    int cmp(int k)
    {
        if(k==val)return -1;
        return k<val ? 0 : 1;
    }
    node(int v=0)
    {
        sz=1;
        ch[0]=ch[1]=NULL;
        val=v;
        r=rand();
    }
    void maintain()
    {
        sz=1;
        if(ch[0]!=NULL)sz+=ch[0]->sz;
        if(ch[1]!=NULL)sz+=ch[1]->sz;
    }
};
void rot(node* &o,int d)//¥ª±Ûd=0 ¥k±Ûd=1
{
    node* k=o->ch[d^1];
    o->ch[d^1]=k->ch[d];
    k->ch[d]=o;
    o->maintain();k->maintain();
    o=k;
}
/*
int finds(node* o,int x)
{
    while(o!=NULL)
    {
        int d=o->cmp(x);
        if(d==-1)return 1;
        o=o->ch[d];
    }
    return 0;
}
*/
void insrt(node* &o,int x)
{
    if(o==NULL)
    {
        o=new node(x);
        return ;
    }
    int d=o->cmp(x);
    if(d==-1)return ;
    insrt(o->ch[d],x);
    o->maintain();
    if(o->ch[d]->r>o->r)rot(o,d^1);
}
void remov(node* &o,int x)
{
    if(o==NULL)return ;
    int d=o->cmp(x);
    if(d==-1)
    {
        node* u=o;
        if(o->ch[0]!=NULL && o->ch[1]!=NULL)
        {
            int d2=(o->ch[0]->r>o->ch[1]->r ? 1 : 0);
            rot(o,d2);remov(o->ch[d2],x);
        }
        else
        {
            if(o->ch[0]==NULL)o=o->ch[1];else o=o->ch[0];
        }
    }
    else remov(o->ch[d],x);
    if(o!=NULL)o->maintain();
}
/*
void print_ans(node* o)
{
    if(o->ch[0]!=NULL)print_ans(o->ch[0]);
    printf("%d ",o->val);
    if(o->ch[1]!=NULL)print_ans(o->ch[1]);
}
*/
int kth(node* o,int k)
{
    if(o==NULL || k<=0 || k>o->sz)return 0;
    int s=(o->ch[0]==NULL ? 0 : o->ch[0]->sz);
    if(k==s+1)return o->val;
    else if(k<=s)return kth(o->ch[0],k);
    else return kth(o->ch[1],k-s-1);
}
main()
{
    char ch[6];
    srand(time(0));
    node* root=NULL;
    while(scanf("%s",ch) && ch[0]!='e')
    {
        int x;scanf("%d",&x);
        //int d=finds(root,x);
        if(ch[0]=='i')
        {
            //if(d)continue;
            insrt(root,x);
        }
        else if(ch[0]=='r')
        {
            //if(!d)continue;
            remov(root,x);
        }
        else if(ch[0]=='a')
        {
            if(root==NULL || x<1 || x>root->sz)puts("error");
            else
            {
                printf("%d\n",kth(root,x));
            }
        }
        //print_ans(root);puts("");
    }
    return 0;
}
