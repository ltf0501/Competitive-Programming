#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
int n,m;
int a[maxn];
bool check(int k)
{
    int sum=0;
    int s=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>k)return 0;
        if(sum+a[i]>k)s++,sum=a[i];
        else sum+=a[i];
    }
    return s<=m;
}
main()
{
    while(~scanf("%d%d",&n,&m) && n+m)
    {
        int sum=0;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
        int l=0,r=sum;
        while(r-l>1)
        {
            int mid=(l+r)>>1;
            if(check(mid))r=mid;
            else l=mid;
        }
        printf("%d\n",r);
    }
    return 0;
}
