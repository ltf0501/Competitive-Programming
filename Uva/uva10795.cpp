#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 100
#define LL long long
using namespace std;
int st[MAXN],ed[MAXN];
LL fun(int *p,int i,int final)
{
if(i==0)return 0;
if(p[i]==final)return fun(p,i-1,final);
return fun(p,i-1,6-final-p[i])+(1LL<<(i-1));
}
int main()
{
int n;
int cas=1;
while(~scanf("%d",&n)&&n)
{
for(int i=1; i<=n; i++)
scanf("%d",&st[i]);
for(int i=1; i<=n; i++)
scanf("%d",&ed[i]);
int k=n;
while(st[k]==ed[k]&&k)k--;
LL ans=0;
if(k!=0)
{
int tem=6-st[k]-ed[k];
ans=fun(st,k-1,tem)+fun(ed,k-1,tem)+1;
}
printf("Case %d: %lld\n",cas++,ans);
}
return 0;
}
