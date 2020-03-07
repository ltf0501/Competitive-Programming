#include<bits/stdc++.h>
using namespace std;
#define maxn 205
#define mod 998244353
int x[maxn],y[maxn];
inline int mul(int a, int b) {
  return (long long) a * b % mod;
}

inline int pow(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

void add(int &a,int b)
{
    a+=b;
    if(a>=mod)a-=mod;
}
main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d%d",&x[i],&y[i]);
    int ans=pow(2,n);
    add(ans,mod-1);
    add(ans,mod-n);
    add(ans,mod-n*(n-1)/2);
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)
    {
        int a=y[j]-y[i];
        int b=x[i]-x[j];
        int c=-a*x[i]-b*y[i];
        int cnt=2;
        for(int k=0;k<n;k++)
        {
            if (k==i || k==j)continue;
            int z=a*x[k]+b*y[k]+c;
            if(z!=0)continue;
            if(k<j)break;
            cnt++;
        }
        add(ans,mod-pow(2,cnt));
        add(ans,1);
        add(ans,cnt);
        add(ans,cnt*(cnt-1)/2);
    }
    printf("%d\n",ans);
    return 0;
}
