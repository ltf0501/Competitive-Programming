#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100010
int a[maxn];
int n,m;
main()
{
    scanf("%d%d",&n,&m);
    ll sum=0,cnt=0;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
    sort(a+1,a+n+1);
    m=a[n];
    int now=1;
    for(int i=2;i<=n;i++)
        if(a[i]!=a[i-1] || (a[i]==a[i-1] && a[i]!=now))now++;
    cnt=n+max(m-now,0);
    printf("%lld\n",sum-cnt);
    return 0;
}
