#include<bits/stdc++.h>
using namespace std;
#define maxn 200000+10
#define INF 2147483647
int l1[maxn],r1[maxn],l2[maxn],r2[maxn];
main()
{
    int n;scanf("%d",&n);
    int L1=-1,R1=INF;
    for(int i=1;i<=n;i++)scanf("%d%d",&l1[i],&r1[i]),L1=max(L1,l1[i]),R1=min(R1,r1[i]);
    int m;scanf("%d",&m);
    int L2=-1,R2=INF;
    for(int i=1;i<=m;i++)scanf("%d%d",&l2[i],&r2[i]),L2=max(L2,l2[i]),R2=min(R2,r2[i]);
    //printf("%d %d %d %d\n",L1,R1,L2,R2);
    int ans=max(0,max(L1-R2,L2-R1));
    printf("%d\n",ans);
    return 0;
}
