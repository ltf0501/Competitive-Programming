#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define maxm 1000010
int a[maxn];
int n,m,k;
int c[maxm];
void add(int x,int d)
{
    for(int i=x;i<maxm;i+=i&-i)
        c[i]+=d;
}
int query(int x)
{
    int ret=0;
    for(int i=x;i;i-=i&-i)
        ret+=c[i];
    return ret;
}
main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(query(a[i])>=k-1)ans++;
        else add(a[i],1),add(a[i]+m,-1);
    }
    printf("%d\n",ans);
    return 0;
}
