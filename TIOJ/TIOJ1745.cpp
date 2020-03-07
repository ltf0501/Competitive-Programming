#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 1000000+10
#define ll long long
int n,a,b,c;
ll s[maxn],f[maxn];
int q[maxn];
ll H(int l,int k)
{
    return f[l]-f[k]+a*(s[l]*s[l]-s[k]*s[k])-b*(s[l]-s[k]);
}
main()
{
    scanf("%d%d%d%d",&n,&a,&b,&c);
    s[0]=0;
    for(int i=1;i<=n;i++)scanf("%lld",&s[i]),s[i]+=s[i-1];
    int l=0,r=0,ch;
    ll t,x,t1,t2;
    q[0]=0;
    for(int i=1;i<=n;i++)
    {
        while(l<r && H(q[l],q[l+1])<=2*a*s[i]*(s[q[l]]-s[q[l+1]]) )l++;
        ch=q[l];x=s[i]-s[ch];
        f[i]=f[ch]+a*x*x+b*x+c;
        while(l<r && H(q[r-1],q[r])*(s[q[r]]-s[i])<=H(q[r],i)*(s[q[r-1]]-s[q[r]]) )r--;
        q[++r]=i;
    }
    printf("%lld\n",f[n]);
    return 0;
}
