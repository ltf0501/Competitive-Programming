#include<bits/stdc++.h>
using namespace std;
const int mod=20071027;
#define maxn 400010
char s[maxn],s1[105];
int ch[maxn][30],dp[maxn];
bool isword[maxn];
int cnt=0;
void insrt(char *s)
{
    int cur=0;
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(ch[cur][s[i]-'a']==0)ch[cur][s[i]-'a']=++cnt;
        cur=ch[cur][s[i]-'a'];
    }
    isword[cur]=1;
}
void f(int i)
{
    int tmp=dp[i-1];
    int cur=0;
    while(1)
    {
        cur=ch[cur][s[i]-'a'];
        if(!cur)break;
        if(isword[cur])dp[i]=(dp[i]+tmp)%mod;
        i++;
    }
}
void init()
{
    memset(ch,0,sizeof(ch));
    memset(dp,0,sizeof(dp));
    memset(isword,0,sizeof(isword));
    cnt=0;
}
main()
{
    int cas=0;
    while(~scanf("%s",s+1))
    {
        init();
        int n;scanf("%d",&n);
        while(n--)
        {
            scanf("%s",s1);
            insrt(s1);
        }
        int len=strlen(s+1);
        dp[0]=1;
        for(int i=1;i<=len;i++)
            if(dp[i-1])f(i);
        printf("Case %d: %d\n",++cas,dp[len]);
    }
    return 0;
}

