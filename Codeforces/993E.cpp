#include<bits/stdc++.h>
using namespace std;
#define maxn 800010
#define lowbit(n) (n&-n)
#define ll long long
typedef complex<double> complex_t;
const double pi=acos(-1);
complex_t eps[maxn],inv_eps[maxn];
int a[maxn],num[maxn];
complex_t u[maxn],v[maxn];
ll ans[maxn];
void pre(int n)
{
    for(int i=0;i<n;i++)
    {
        eps[i]=complex_t(cos(2.0*pi*i/n),sin(2.0*pi*i/n));
        inv_eps[i]=conj(eps[i]);
    }
}
void bit_reverse(int n,complex_t *x)
{
	for(int i=0,j=0;i<n;i++)
	{
		if(i>j)swap(x[i],x[j]);
		for(int l=n>>1;(j^=l)<l;l>>=1);
	}
}
void fft(int n,complex_t *x,complex_t *w)
{
	bit_reverse(n,x);
	for(int i=2;i<=n;i<<=1)
	{
		int m=i>>1;
		for(int j=0;j<n;j+=i)
		{
			for(int k=0;k<m;k++)
			{
				complex_t z=x[j+m+k]*w[n/i*k];
				x[j+m+k]=x[j+k]-z;
				x[j+k]+=z;
			}
		}
	}
}
main()
{
    int n,x;scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)num[i]=num[i-1]+(a[i]<x);
    for(int i=0;i<=n;i++)u[num[i]]+=1;
    for(int i=0;i<=n;i++)v[i]=u[n-i];
    //for(int i=0;i<=n;i++)printf("%d ",num[i]);puts("");
    //for(int i=0;i<=n;i++)printf("%.0f ",u[i].real());puts("");
    //for(int i=0;i<=n;i++)printf("%.0f ",v[i].real());puts("");
    int l=0;
    ll umr=0;
	while(l<=n)
    {
		int r=l;
		while(r<=n && num[r]==num[l])r++;
		umr+=1ll*(r-l)*(r-l-1)/2;
		l=r;
	}
	int N=n;
    if(n>400)
    {
        while(lowbit(N)<N)N+=lowbit(N);
        N*=2;
        //printf("%d\n",N);
        pre(N);
        fft(N,v,eps),fft(N,u,eps);
        for(int i=0;i<N;i++)v[i]*=u[i];
        fft(N,v,inv_eps);
        //for(int i=0;i<2*N;i++)printf("%.0f %.0f\n",v[i].real(),v[i].imag());
    }
    else
    {
        for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)ans[i+j]+=1ll*(ll)v[i].real()*(ll)u[j].real();
        printf("%lld ",umr);
        for(int i=1;i<=n;i++)printf("%lld ",ans[i+n]);return 0;
    }
	printf("%lld ",umr);
	for(int i=1;i<=n;i++)v[i+n]/=N;
    for(int i=1;i<=n;i++)printf("%lld ",(ll)(v[i+n].real()+0.5));
    return 0;
}
