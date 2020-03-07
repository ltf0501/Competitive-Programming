#include<bits/stdc++.h>
using namespace std;
#define maxn 1000+10
#define mod 1000000000+7
string s;
int n,a[30],dp[maxn],len[maxn];
main()
{
    scanf("%d",&n);cin>>s;
    for(int i=1;i<=26;i++)scanf("%d",&a[i]);
    int k=0;
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        int d=0;len[i]=n+1;
        for(int j=i-1;j>=0;j--)
        {
            d=max(d,i-a[s[j]-'a'+1]);
            if(d>j)break;
            dp[i]+=dp[j];dp[i]%=mod;
            len[i]=min(len[i],len[j]+1);
            k=max(k,i-j);
        }
    }
    //for(int i=1;i<=n;i++)printf("%d ",dp[i]);puts("");
    printf("%d\n%d\n%d\n",dp[n],k,len[n]);
    return 0;
}
