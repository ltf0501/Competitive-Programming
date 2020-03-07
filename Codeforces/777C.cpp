#include<bits/stdc++.h>
using namespace std;
#define maxn 100000+10
int a[maxn],d[maxn],c[maxn];
main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<n*m;i++)scanf("%d",&a[i]);
    memset(d,-1,sizeof(d));
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(c[j]>i)continue;
            while(c[j]<n-1 && a[c[j]*m+j]<=a[c[j]*m+m+j])c[j]++;
            d[i]=max(d[i],c[j]-1);
            c[j]++;
        }
        if(i)d[i]=max(d[i],d[i-1]);
    }
    //for(int i=0;i<n-1;i++)printf("%d ",d[i]);puts("");
    int k;scanf("%d",&k);
    while(k--)
    {
        int l,r;scanf("%d%d",&l,&r);
        if(l==r){puts("Yes");continue;}
        l--;r-=2;
        if(d[l]>=r)puts("Yes");else puts("No");
    }
    return 0;
}
