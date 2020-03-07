#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define INF 100000000
int a[maxn],n,b;
int ok(int x,int k)
{
    if(!k){if(x)return INF;else return 0;}
    if(32-__builtin_clz(x)>k)return INF;
    else if(32-__builtin_clz(x)==k && x>(1<<(k-1)))return INF;
    if(x<=k)return 0;else x-=k;
    int s=0;
    for(int i=1;i<=20;i++)
    {
        if(((k-i)*(1<<i))>x+k){s=i-1;break;}
    }
    return ((x+k-(1<<(s+1)))+k-s-3)/(k-s-2)-1;
}
bool check(int m)
{
    int cnt=0;
    for(int i=1;i<=n;i++)
        cnt+=ok(a[i],m);
    //printf("%d\n",cnt);
    return cnt<=b;
}
main()
{
    scanf("%d%d",&n,&b);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int ans=1e6,aa=1<<20;
    for(;aa;aa>>=1)
        if(ans>=aa && check(ans-aa))ans-=aa;
    printf("%d\n",ans);
    return 0;
}
