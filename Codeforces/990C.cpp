#include<bits/stdc++.h>
using namespace std;
#define maxn 600010
#define add 300010
#define ll long long
char c[maxn];
vector<int> v[maxn];
int num[maxn],mi[maxn];
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",c);int len=strlen(c);
        mi[i]=maxn;
        for(int j=0;j<len;j++)
        {
            if(c[j]=='(')num[i]++;
            else num[i]--;
            mi[i]=min(mi[i],num[i]);
        }
        v[num[i]+add].push_back(mi[i]);
    }
    //for(int i=1;i<=n;i++)printf("%d %d\n",num[i],mi[i]);
    ll ans=0;
    for(int i=0;i<maxn;i++)sort(v[i].begin(),v[i].end());
    for(int i=1;i<=n;i++)if(mi[i]>=0)
    {
        int cur=add-num[i];
        int tmp=v[cur].end()-lower_bound(v[cur].begin(),v[cur].end(),-num[i]);
        ans+=tmp;
        //printf("%d: %d\n",i,tmp);
    }
    printf("%lld\n",ans);
    return 0;
}
