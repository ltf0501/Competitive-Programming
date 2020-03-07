#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
int a[maxn];
int n,k,A,B;
ll cal(int l,int r)
{
    int i1=lower_bound(a+1,a+k+1,l)-a;
    int i2=upper_bound(a+1,a+k+1,r)-a;
    ll res;
    if(i1==i2)res=A;
    else res=1ll*B*(i2-i1)*(r-l+1);
    if(l==r || i1==i2)return res;
    int m=(l+r)>>1;
    ll tmp=cal(l,m)+cal(m+1,r);
    return min(tmp,res);
}
main()
{
    scanf("%d%d%d%d",&n,&k,&A,&B);
    for(int i=1;i<=k;i++)scanf("%d",&a[i]);
    sort(a+1,a+k+1);
    int len=(1<<n);
    printf("%lld\n",cal(1,len));
    return 0;
}
