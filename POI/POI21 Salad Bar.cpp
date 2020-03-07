#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
int sum[maxn];
char c[maxn];
int up[maxn],dn[maxn];
stack<int> s1,s2;
main()
{
    int n;scanf("%d",&n);
    scanf("%s",c+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+(c[i]=='p'?1:-1);
    //for(int i=1;i<=n;i++)printf("%d ",sum[i]);puts("");
    for(int i=1;i<=n;i++)up[i]=n+1,dn[i]=n+1;
    for(int i=n;i>=0;i--)
    {
        dn[i]=n+1,up[i]=n+1;
        while(!s1.empty() && sum[s1.top()]>=sum[i])s1.pop();
        if(!s1.empty())dn[i]=s1.top();s1.push(i);
        while(!s2.empty() && sum[s2.top()]<sum[i])s2.pop();
        if(!s2.empty())up[i]=s2.top();s2.push(i);
    }
    //for(int i=1;i<=n;i++)printf("%d ",up[i]);puts("");
    //for(int i=1;i<=n;i++)printf("%d ",dn[i]);puts("");
    int ans=0;
    for(int i=0;i<=n;)
    {
        int j=i;
        while(up[j]!=n+1 && up[j]<=dn[i])j=up[j];
        ans=max(ans,j-i);
        i=j+1;
    }
    printf("%d\n",ans);
    return 0;
}
