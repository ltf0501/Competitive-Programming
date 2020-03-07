#include<bits/stdc++.h>
#include "lib1956.h"
#define maxn 200000+10
#define ll long long
using namespace std;
int ww[maxn];
bool cmp(int i,int j)
{
    return ww[i]<ww[j];
}
int r[maxn];
int solve(int l,int u,int *w,int n,int *result)
{
    for(int i=0;i<n;i++)r[i]=i;
    for(int i=0;i<n;i++)ww[i]=w[i];
    sort(r,r+n,cmp);
    sort(ww,ww+n);
    int k=0;
    ll sum=0;
    for(k=0;k<n;k++)
    {
        sum+=ww[k];
        if(sum>=l)break;
    }
    if(k==n)return 0;
    k++;
    if(sum<=u)
    {
        for(int i=0;i<k;i++)result[i]=r[i];
        return k;
    }
    k--;
    ll sum2=0;
    bool flag=0;
    for(int i=n-1;i>=n-k;i--)
    {
        sum2+=ww[i];
        if(sum2>=l){flag=1;break;}
    }
    if(!flag)return 0;
    for(int i=0;i<k;i++)result[i]=r[i];
    for(int i=0;i<k;i++)
    {
        result[i]=r[i+n-k];
        sum+=(ww[i+n-k]-ww[i]);
        if(sum>=l)
            return k;
    }
}
/*
main()
{
    int l,u,n;
    while(~scanf("%d%d%d",&l,&u,&n))
    {
        for(int i=0;i<n;i++)scanf("%d",&w[i]);
        int ans=solve(l,u,w,n,re);
        printf("%d\n",ans);
        for(int i=0;i<ans;i++)printf("%d ",re[i]);puts("");
        for(int i=0;i<ans;i++)printf("%d ",w[re[i]]);puts("");
    }
    return 0;
}
*/
