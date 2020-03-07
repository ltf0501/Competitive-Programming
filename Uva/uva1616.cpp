#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define pii pair<int,int>
#define F first
#define S second
const long double eps=1e-10;
pii a[maxn];
int n;
bool check(long double m)
{
    __float128 le=0;
    for(int i=1;i<=n;i++)
    {
        le=max(le,(__float128)a[i].F);
        __float128 ri=le+m;
        if(ri>a[i].S)return 0;
        le=ri;
    }
    return 1;
}
main()
{
    //freopen("caravan.in","r",stdin);freopen("caravan.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i].F,&a[i].S);
    sort(a+1,a+n+1);
    __float128 l=0,r=1e6;
    __float128 ans=0;
    while(r-l>1e-12)
    {
        __float128 m=(l+r)/2;
        if(check(m))ans=m,l=m;
        else r=m;
    }
    int p=0,q=1;
    //printf("%.12lf\n",(long double )ans);
    for(int i=1;i<=n;i++)
    {
        int tmp=round((long double )ans*i);
       // printf("%d ",tmp);
        //printf("%.12lf\n",fabs((long double)tmp/i-(long double)ans));
        if(fabs((long double)tmp/i-(long double)ans)<fabs((long double)p/q-(long double)ans))
            p=tmp,q=i;
    }
    int g=__gcd(p,q);
    p/=g,q/=g;
    printf("%d/%d\n",p,q);
    return 0;
}
