#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
int n,m;
int a[maxn];
int num[maxn<<1];
ll cal(int x)
{
    memset(num,0,sizeof(num));
    int sum=n;
    ll ret=0,now=0;
    num[sum]=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<x)now-=num[--sum];
        else now+=num[sum++];
        ret+=now;
        num[sum]++;
    }
    return ret;
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    printf("%lld\n",cal(m)-cal(m+1));
    return 0;
}
