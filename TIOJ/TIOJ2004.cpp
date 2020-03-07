#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
ll mypow(int a,int n)
{
    if(n==0)return 1;
    if(n==1)return a;
    ll ret=mypow(a,n>>1);
    ret=ret*ret%mod;
    if(n&1)ret=ret*a%mod;
    return ret;
}
template<class T>
T input(T ___)
{
  T _=0,__=1; char tc=getchar();
  while((tc<'0'||tc>'9')&&tc!='-') tc=getchar();
  if(tc=='-') tc=getchar(),__=-1;
  while(tc>='0'&&tc<='9') _=_*10+(tc-'0'),tc=getchar();
  return _*__;
}
main()
{
    int t;t=input(t);
    while(t--)
    {
        int n;n=input(n);
        printf("%lld\n",mypow(4,n-1));
    }
    return 0;
}
