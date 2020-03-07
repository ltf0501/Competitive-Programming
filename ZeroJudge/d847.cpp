#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
#define val 1010
int x[maxn],y[maxn];
int id[maxn];
int n;
bool cmp(int i,int j){return x[i]<x[j] || (x[i]==x[j] && y[i]>y[j]);}
int c[val],ans[maxn];
void add(int x,int d)
{
    while(x<=1000)c[x]+=d,x+=(x&-x);
}
int query(int x)
{
    int ret=0;
    while(x)ret+=c[x],x-=(x&-x);
    return ret;
}
main()
{
    while(~scanf("%d",&n))
    {
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)id[i]=i;
        for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
        sort(id+1,id+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            int s=id[i];
            ans[s]=query(y[s]-1);
            add(y[s],1);
        }
        for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
    }
    return 0;
}
