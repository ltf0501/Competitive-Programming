#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n,a[maxn];
int s,f;
int gao(int i,int j)
{
	if(i+j-1<=n)return a[i+j-1]-a[i-1];
	return a[n]-a[i-1]+a[j-(n-i+1)];
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]+=a[i-1];
    scanf("%d%d",&s,&f);
    int k=f-s;
    int ans=1,tmp=gao(s,k);
    for(int i=2;i<=n;i++)
    {
        int t;
        if(i>s)t=s-i+1+n;
        else t=s-i+1;
        if(tmp<gao(t,k))tmp=gao(t,k),ans=i;
    }
    printf("%d\n",ans);
    return 0;
}

