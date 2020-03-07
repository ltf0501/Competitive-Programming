#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+5;
int n,k,l;
long long L[maxn],R[maxn];
int d[maxn];
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&k,&l);
        for(int i=0;i<n;i++)scanf("%d",&d[i]);
        int mid=0;
        while(mid<n && d[mid]<=l/2)
        {
            R[mid+1]=2*d[mid];
            if(mid+1-k>0)R[mid+1]+=R[mid+1-k];
            mid++;
        }
        for(int i=0;i<n-mid;i++)
        {
            L[i+1]=2*(l-d[n-1-i]);
            if(i+1-k>0)L[i+1]+=L[i+1-k];
        }
        long long ans=R[mid]+L[n-mid];
        for(int i=0;i<=k;i++)
        {
            long long tmp=l;
            if(mid-i>0)tmp+=R[mid-i];
            if(n-mid-k+i>0)tmp+=L[n-mid-k+i];
            ans=min(ans,tmp);
        }
        printf("%lld\n",ans);
    }

    return 0;
}
