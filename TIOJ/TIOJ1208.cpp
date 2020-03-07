#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 20000+5
int n,k;
int a[maxn],S[maxn],s[maxn],t[maxn];
int mrge(int l,int r,int q)
{
    if(l>=r)return 0;
    int m=l+(r-l)/2;
    int cnt=0;
    cnt+=mrge(l,m,q);
    cnt+=mrge(m+1,r,q);
    int p=m+1;
    for(int i=l;i<=m;i++)
    {
        while(p<=r && s[p]-s[i]<=q)p++;
        cnt+=r-p+1;
    }
    int i=l,idx=l,j=m+1;
    while(i<=m && j<=r)
    {
        if(s[i]<s[j])t[idx++]=s[i++];
        else t[idx++]=s[j++];
    }
    while(i<=m)t[idx++]=s[i++];
    while(j<=r)t[idx++]=s[j++];
    memcpy(s+l,t+l,sizeof(int)*(r-l+1));
    return cnt;
}
bool check(int q)
{
    memcpy(s,S,sizeof(S));
    int cnt=mrge(0,n,q);
    return cnt>k-1;
}
main()
{
    while(~scanf("%d%d",&n,&k) && n+k)
    {
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        S[0]=0;
        for(int i=1;i<=n;i++)S[i]=S[i-1]+a[i-1];
        int l=n*(-10000)-1,r=n*10000;
        while(r-l>1)
        {
            int m=l+(r-l)/2;
            if(check(m))l=m;
            else r=m;
        }
        printf("%d\n",r);
    }
    return 0;
}
