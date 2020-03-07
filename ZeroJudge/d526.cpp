#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    node *ch[2];
    node(int val=0);
};
node::node(int val)
{
    this->val=val;
    ch[0]=ch[1]=NULL;
}
void insrt(node* &o,int a)
{
    if(o==NULL)
    {
        o=new node(a);
        return ;
    }
    if(a>o->val)insrt(o->ch[1],a);
    if(a<o->val)insrt(o->ch[0],a);
}
void print_ans(node* &o)
{
    printf("%d ",o->val);
    if(o->ch[0]!=NULL)print_ans(o->ch[0]);
    if(o->ch[1]!=NULL)print_ans(o->ch[1]);

    delete o;
    o=NULL;
}
main()
{
    int n;
    while(~scanf("%d",&n))
    {
        node *root=NULL;
        for(int i=1;i<=n;i++)
        {
            int a;
            scanf("%d",&a);
            insrt(root,a);
        }
        print_ans(root);
        puts("");
    }
    return 0;
}
