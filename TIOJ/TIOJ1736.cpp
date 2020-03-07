#include<bits/stdc++.h>
using namespace std;
#define maxn 200000+10
int L[maxn],R[maxn];
int lo[maxn],hi[maxn];
main()
{
    int n;scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&L[i],&R[i]);
        L[i]=(L[i]==-1)?0:L[i];
        R[i]=(R[i]==-1)?0:R[i];
    }
    for(int i=n;i>=1;i--)
    {
        int l=L[i],r=R[i];
        if(hi[r]>lo[l])ans++;
        lo[i]=min(lo[l],lo[r])+1;
        hi[i]=max(hi[l],hi[r])+1;
        if((lo[l]!=hi[l] && lo[r]!=hi[r]) || hi[i]-lo[i]>1){puts("-1");return 0;}
    }
    printf("%d\n",ans);
    return 0;
}
