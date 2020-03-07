#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
int cnt[10];
char c[maxn];
int dp[10001][10001];
char ans[maxn];
int flag;
main()
{
    scanf("%s",c);
    int n=strlen(c);
    for(int i=0;i<n;i++)cnt[c[i]-'0']++;
    for(int i=0;i<10;i++)if(cnt[i]>=1000)
    {
        for(int j=0;j<1000;j++)printf("%d",i);return 0;
    }
    for(int i=0;i<n;i++)dp[i][i]=1;
    for(int len=1;len<n;len++)for(int i=0;i+len<n;i++)
    {
        int j=i+len;
        dp[i][j]=max({dp[i+1][j-1]+2*(c[i]==c[j]),dp[i][j-1],dp[i+1][j]});
    }
    int sz=0;
    int l=0,r=n-1;
    while(l<=r)
    {
        if(l==r){flag=1,ans[sz++]=c[l];break;}
        if(c[l]==c[r] && dp[l][r]==dp[l+1][r-1]+2)ans[sz++]=c[l],l++,r--;
        else if(dp[l][r]==dp[l+1][r])l++;
        else r--;
    }
    for(int i=0;i<sz;i++)printf("%c",ans[i]);
    for(int i=sz-1-flag;i>=0;i--)printf("%c",ans[i]);
    return 0;
}
