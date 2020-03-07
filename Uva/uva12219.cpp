#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
const int mx=50000+10000;
struct node
{
    char name[10];
    int r,l;
    bool operator < (const node& p)const
    {
        int t=strcmp(name,p.name);
        if(t==0)
        {
            if(l==p.l)return r<p.r;
            return l<p.l;
        }
        if(t>0)
        return true;
        return false;
    }
};
map<node,int> mp;
vector<node> idcache;

int num,p;
char name[mx][10],s[mx*10];
bool used[mx];
vector<int>g[mx];
void init()
{
    for(int i=0;i<mx;i++) g[i].clear();
    mp.clear();num=1;p=0;
    memset(used,0,sizeof(used));
}
int dfs()
{
    int id=num++;
    int k=0;
    node t;t.l=t.r=0;
    for(;isalpha(s[p]);p++)
    {
        t.name[k++]=s[p];
    }
    t.name[k]=0;
    if(s[p]=='(')
    {
        p++;
        t.l=dfs();p++;
        t.r=dfs();p++;
    }
    if(mp.find(t)==mp.end())//¨S§ä¨ìt
    {
        mp[t]=id;
        strcpy(name[id],t.name);//printf("%d ",id);puts(name[id]);
        g[id].push_back(t.l);
        g[id].push_back(t.r);
    }
    else num--;
    return mp[t];
}
void print_ans(int u)
{
    used[u]=true;
    printf("%s",name[u]);
    if(g[u].size()==2 && g[u][0])
    {
        printf("(");
        int v;
        v=g[u][0];
        if(!used[v])print_ans(g[u][0]);
        else printf("%d",v);
        printf(",");
        v=g[u][1];
        if(!used[v])
        print_ans(g[u][1]);
        else printf("%d",v);
        printf(")");
    }
}
main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%s",s);
        int len=strlen(s);
        dfs();
        print_ans(1);
        printf("\n");
    }
    return 0;
}
