#include<bits/stdc++.h>
using namespace std;

main()
{
    int n,k;scanf("%d%d",&n,&k);
    int s=(n-1)/k,t=(n-1)%k,ans;
    if(t==0)ans=2*s;
    else if(t==1)ans=2*s+1;
    else ans=2*s+2;
    printf("%d\n",ans);
    for(int i=1;i<=k;i++)printf("%d %d\n",n,i);
    for(int i=1;i<=n-1-k;i++)printf("%d %d\n",i,i+k);
    return 0;
}
