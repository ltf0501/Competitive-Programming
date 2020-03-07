#include<bits/stdc++.h>
using namespace std;
const int maxp=1.5e7+10;
#define maxn 300010
int a[maxn];
int p[maxp],num[maxp];
void pre()
{
    for(int i=2;i<maxp;i++)if(!p[i])
        for(int j=i;j<maxp;j+=i)p[j]=i;
}
main()
{
    pre();
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int g=a[1];
    for(int i=2;i<=n;i++)g=__gcd(g,a[i]);
    for(int i=1;i<=n;i++)a[i]/=g;
    for(int i=1;i<=n;i++)
    {
        int x=a[i];
        while(x>1)
        {
            int tmp=p[x];
            num[tmp]++;
            while(x%tmp==0)x/=tmp;
        }
    }
    int mx=0;
    for(int i=1;i<maxp;i++)mx=max(mx,num[i]);
    if(mx)printf("%d\n",n-mx);
    else puts("-1");
    return 0;
}
