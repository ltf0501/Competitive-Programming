#include<bits/stdc++.h>
//#include "lib1956.h"
#define maxn 200000+10
using namespace std;
int w[maxn],re[maxn];
bool cmp(int i,int j)
{
    return w[i]<w[j];
}
int r[maxn];
int solve(int l,int u,int *w,int n,int *result)
{
    for(int i=0;i<n;i++)r[i]=i;
    sort(r,r+n,cmp);
    sort(w,w+n);
    int k=0;
    int sum=0;
    for(k=0;k<n;k++)
    {
        sum+=w[k];
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
    int sum2=0;
    bool flag=0;
    for(int i=n-1;i>=n-k;i--)
    {
        sum2+=w[i];
        if(sum2>=l){flag=1;break;}
    }
    if(!flag)return 0;
    for(int i=0;i<k;i++)result[i]=r[i];
    for(int i=0;i<k;i++)
    {
        result[i]=r[i+n-k];
        sum+=(w[i+n-k]-w[i]);
        if(sum>=l)
            return k;
    }
}
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
