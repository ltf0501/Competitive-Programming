#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int t[maxn],x[maxn],y[maxn];
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d%d",&t[i],&x[i],&y[i]);
    bool flag=1;
    for(int i=0;i<n;i++)
    {
        int tt=t[i+1]-t[i];
        int dis=abs(x[i+1]-x[i])+abs(y[i+1]-y[i]);
        if(tt<dis || (tt+dis)&1){flag=0;break;}
    }
    puts(flag ? "Yes" : "No");
    return 0;
}
