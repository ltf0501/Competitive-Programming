#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n;
int a[maxn];
int nxt[maxn],now[maxn];
int bit[maxn];
int ans[maxn];
vector<int> v[maxn];
void add(int x,int d)
{
    for(int i=x;i<=n;i+=i&-i)bit[i]+=d;
}
int query(int x)
{
    int ret=0;
    for(int i=17;i>=0;i--)if(ret+(1<<i)<=n)
    {
        ret+=(1<<i);
        if(bit[ret]>x)ret-=(1<<i);
        else x-=bit[ret];
    }
    return ++ret;
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=n;i;i--)nxt[i]=now[a[i]],now[a[i]]=i;
    for(int i=1;i<=n;i++)if(now[i])add(now[i],1);
    for(int i=1;i<=n;i++)v[1].push_back(i);
    for(int i=1;i<=n;i++)
    {
        for(int j : v[i])
        {
            ans[j]++;
            int id=query(j);
            v[id].push_back(j);
        }
        add(i,-1);
        if(nxt[i])add(nxt[i],1);
    }
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);puts("");
    return 0;
}

