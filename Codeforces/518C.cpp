#include<bits/stdc++.h>
using namespace std;
#define maxn 100000+5
#define ll long long
int a[maxn],c[maxn];
main()
{
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)scanf("%d",&a[i]),c[a[i]]=i;
    ll ans=0;
    for(int i=0;i<m;i++)
    {
        int x;scanf("%d",&x);
        ans+=(c[x]/k+1);
        x=c[x];
        if(x)
        {
            swap(a[x-1],a[x]);
            c[a[x-1]]=x-1,c[a[x]]=x;
        }
    }
    printf("%I64d\n",ans);
    return 0;
}

