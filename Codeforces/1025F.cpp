#include<bits/stdc++.h>
using namespace std;
#define maxn 2010
#define ll long long
#define ALL(v) v.begin(),v.end()
typedef long double ld;
int n;
int x[maxn],y[maxn];
const ld PI=acos(-1.0);
ll ans;
vector<ld> v;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++)
    {
        v.clear();
        for(int j=1;j<=n;j++)if(j!=i)
            v.push_back(atan2((ld)(y[j]-y[i]),(ld)(x[j]-x[i])));
        sort(ALL(v));
        for(int j=0;j<n-1;j++)v.push_back(v[j]+2*PI);
        int r=0;
        for(int j=0;j<n-1;j++)
        {
            while(v[r+1]-v[j]<PI)r++;
            ans+=1ll*(r-j)*(r-j-1)/2*(n-2-r+j)*(n-3-r+j)/2;
        }
    }
    printf("%lld\n",ans/2);
    return 0;
}
