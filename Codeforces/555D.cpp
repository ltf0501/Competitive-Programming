#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define pii pair<int,int>
#define F first
#define S second
pii a[maxn];
int b[maxn],c[maxn];
int n,m;
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        a[i]=pii(x,i);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)b[a[i].S]=i,c[i]=a[i].F;
    while(m--)
    {
        int x,l;scanf("%d%d",&x,&l);
        int d=1;
        int kk=b[x];
        int dis=c[kk]+l*d;
        int k=upper_bound(c+1,c+n+1,dis)-c-1;
        l-=abs(c[k]-c[kk]);
        kk=k,d=-d;
        while(1)
        {
            dis=c[kk]+l*d;
            if(d==1)k=upper_bound(c+1,c+n+1,dis)-c-1;
            else k=lower_bound(c+1,c+n+1,dis)-c;
            if(k==kk)break;
            int t=abs(c[k]-c[kk]);
            if((l/t)%2==1)d=-d,kk=k;
            l%=t;
        }
        printf("%d\n",a[kk].S);
    }
    return 0;
}
