#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
int a[maxn],n;
bool check(int k,int i,int j)
{
    return 1ll*(i-k)*(a[j]-a[k])==1ll*(j-k)*(a[i]-a[k]);
}
bool par(int i,int j,int p,int q)
{
    return 1ll*(i-j)*(a[p]-a[q])==1ll*(p-q)*(a[i]-a[j]);
}
vector<int> v;
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int t=0;
    for(int i=3;i<=n;i++)
        if(!check(1,2,i))v.push_back(i);
    if(!v.size())return 0*puts("NO");

    for(int t : v)
    {
        bool flag=1;
        for(int i=1;i<=n;i++)if(i!=t)
        {
            if(!par(1,2,t,i) && !check(1,2,i)){flag=0;break;}
        }
        if(flag)return 0*puts("YES");
        flag=1;
        for(int i=1;i<=n;i++)if(i!=t)
        {
            if(!par(1,t,2,i) && !check(1,t,i)){flag=0;break;}
        }
        if(flag)return 0*puts("YES");
    }
    bool flag=1;
    flag=1;
    for(int i=4;i<=n;i++)if(!check(2,3,i)){flag=0;break;}
    if(flag)return 0*puts("YES");
    puts("NO");
    return 0;
}
/*
5
-954618456 -522919664 -248330428 -130850748 300848044
*/
