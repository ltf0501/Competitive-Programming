#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
char c[maxn];
vector<int> cnt[2];
ll sum[maxn];
main()
{
    scanf("%s",c+1);
    int n=strlen(c+1);
    char cur='A';
    int now=1;
    bool flag=0;
    for(int i=1;i<=n;i++)
    {
        if(c[i]==cur)now++;
        else if(c[i]=='A'+'Q'-cur)
        {
            cnt[flag].push_back(now);
            flag^=1;
            now=1;
            cur='A'+'Q'-cur;
        }
        if(i==n)cnt[flag].push_back(now);
    }
    if(cnt[1].size()<=1)return 0*puts("0");
    sum[0]=cnt[1][0];
    for(int i=1;i<cnt[1].size();i++)sum[i]=sum[i-1]+cnt[1][i];
    int k=cnt[1].size();
    ll ans=0;
    for(int i=0;i<k-1;i++)ans+=1ll*sum[i]*(sum[k-1]-sum[i])*cnt[0][i+1];
    printf("%lld\n",ans);
    return 0;
}
