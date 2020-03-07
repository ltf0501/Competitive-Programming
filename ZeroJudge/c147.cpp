#include<bits/stdc++.h>
using namespace std;
#define maxw 1000010
#define maxn 1010
const int INF=1e9+7;
int dp[maxw];
int w[maxn],v[maxn];
int n,m;
string s;
main()
{
    getline(cin,s);
    stringstream ss(s);
    int t;
    while(ss>>t)w[++n]=t;
    n=0;
    getline(cin,s);
    stringstream tt(s);
    while(tt>>t)v[++n]=t;
    /*
    for(int i=1;i<=n;i++)printf("%d ",w[i]);puts("");
    for(int i=1;i<=n;i++)printf("%d ",v[i]);puts("");
    */
    //printf("%d\n",n);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)dp[i]=-INF;
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1,j>=w[i];j--)
            if(j>=w[i])dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        //for(int j=1;j<=m;j++)printf("%d ",dp[j]);puts("");
    }
    int ans=0;
    for(int i=1;i<=m;i++)ans=max(ans,dp[i]);
    printf("%d\n",ans);
    return 0;
}
