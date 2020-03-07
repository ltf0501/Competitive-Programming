#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
vector<int> dv[maxn];
void pre()
{
    for(int i=1;i<maxn;i++)for(int j=i;j<maxn;j+=i)dv[j].push_back(i);
}
struct node
{
    node* ch[2];
    int mi;
    node(int x)
    {
        ch[0]=ch[1]=NULL;
        mi=x;
    }
};
node *trie[maxn];
void insrt(int id,int x)
{
    if(!trie[id])trie[id]=new node(x);
    node *now=trie[id];
    for(int i=16;i>=0;i--)
    {
        if(now->mi>x)now->mi=x;
        bool k=(x&(1<<i));
        if(!now->ch[k])now->ch[k]=new node(x);
        now=now->ch[k];
    }
}
int query(int id,int x,int mx)
{
    if(!trie[id] || trie[id]->mi>mx)return -1;
    int ret=0;
    node *now=trie[id];
    for(int i=16;i>=0;i--)
    {
        bool k=(x&(1<<i));
        if(now->ch[k^1] && now->ch[k^1]->mi<=mx)
        {
            if(k^1)ret+=(1<<i);
            now=now->ch[k^1];
        }
        else
        {
            if(k)ret+=(1<<i);
            now=now->ch[k];
        }
    }
    return ret;
}
main()
{
    pre();
    int q;scanf("%d",&q);
    while(q--)
    {
        int type;scanf("%d",&type);
        if(type==1)
        {
            int x;scanf("%d",&x);
            for(int p : dv[x])insrt(p,x);
        }
        else
        {
            int x,k,s;scanf("%d%d%d",&x,&k,&s);
            if(x%k!=0){puts("-1");continue;}
            s-=x;
            printf("%d\n",query(k,x,s));
        }
    }
    return 0;
}
