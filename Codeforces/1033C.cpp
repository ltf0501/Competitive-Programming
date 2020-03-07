#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n;
int a[maxn],pos[maxn];
bool dp[maxn];
main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]),pos[a[i]]=i;
    for(int i=n;i;i--)
    {
        //printf("%d: ",i);
        int k1=pos[i]/i,k2=(n-1-pos[i])/i;
        for(int j=pos[i]-k1*i;j<=pos[i]+k2*i;j+=i)
            if(a[j]>i)dp[i]|=(dp[a[j]]^1);
    }
   // for(int i=1;i<=n;i++)printf("%d ",dp[i]);puts("");
    for(int i=0;i<n;i++)putchar(dp[a[i]] ? 'A' : 'B');
    return 0;
}
