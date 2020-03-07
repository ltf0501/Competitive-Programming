#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
const int INF=1e9+7;
int bit[maxn];
int n,a[maxn],s[maxn],ans[maxn],g[maxn];
void add(int x,int d)
{
    for(int i=x;i<=n;i+=i&-i)bit[i]+=d;
}
int query(int x)
{
    int ret=0;
    for(int i=x;i;i-=i&-i)ret+=bit[i];
    return ret;
}
int check(int x)
{
    int ret=0,ans=0;
    for(int i=17;i>=0;i--)
    {
        ret+=(1<<i);
        if(ret<n && ans+bit[ret]<x)ans+=bit[ret];
        else ret-=(1<<i);
    }
    ret++;
    add(ret,-1);
    return ret;
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]++;
    for(int i=1;i<=n;i++)bit[i]++,bit[i+(i&-i)]+=bit[i];
    for(int i=n;i>=1;i--)s[check(a[i])]=i;
    for(int i=1;i<=n;i++)g[i]=INF;
    for(int i=1;i<=n;i++)
    {
        int k=lower_bound(g+1,g+n+1,s[i])-g;
        g[k]=s[i];
        ans[s[i]]=k;
    }
    for(int i=1;i<=n;i++)
    {
        ans[i]=max(ans[i],ans[i-1]);
        printf("%d\n",ans[i]);
    }
    return 0;
}
