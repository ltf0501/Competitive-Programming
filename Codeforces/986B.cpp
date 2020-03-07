#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long
int n,a[maxn];
int bit[maxn];
void add(int x,int d)
{
    for(int i=x;i<=n;i+=i&-i)bit[i]+=d;
}
int query(int x)
{
    if(!x)return 0;
    int ret=0;
    for(int i=x;i;i-=i&-i)ret+=bit[i];
    return ret;
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    ll num=0;
    for(int i=n;i>=1;i--)
    {
        num+=query(a[i]-1);
        add(a[i],1);
    }
    if((n+num)&1)puts("Um_nik");
    else puts("Petr");
    return 0;
}
