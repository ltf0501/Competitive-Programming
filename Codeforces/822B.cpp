#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
char s[maxn],t[maxn];
int n,m;
vector<int> v1,v2;
main()
{
    scanf("%d%d",&n,&m);
    scanf("%s%s",s+1,t+1);
    int ans=maxn;
    for(int i=1;i+n-1<=m;i++)
    {
        int now=0;
        for(int j=1;j<=n;j++)if(s[j]!=t[i+j-1])now++,v2.push_back(j);
        //printf("%d\n",now);
        if(ans>now)v1=v2,ans=now;
        v2.clear();
    }
    printf("%d\n",ans);
    for(int i : v1)printf("%d ",i);
    return 0;
}
