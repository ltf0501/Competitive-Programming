#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 300010
int a[maxn],b[maxn];
int n,m,ans;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)scanf("%d",&b[i]);
    ll cur_a=a[1],cur_b=b[1];
    int idx_a=1,idx_b=1;
    while(idx_a<=n && idx_b<=m)
    {
        if(cur_a==cur_b)ans++,cur_a=a[++idx_a],cur_b=b[++idx_b];
        else if(cur_a<cur_b)cur_a+=a[++idx_a];
        else cur_b+=b[++idx_b];
    }
    if(cur_a!=0 || cur_b!=0 || idx_a!=n+1 || idx_b!=m+1)puts("-1");
    else printf("%d\n",ans);
    return 0;
}
