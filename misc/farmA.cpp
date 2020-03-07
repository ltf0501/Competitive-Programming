#include<bits/stdc++.h>
using namespace std;
#define maxn 500000+5
int dp[maxn][2];
set<int> s;
set<int>::iterator iter;
main()
{
    int n;scanf("%d",&n);
    int p;
    scanf("%d",&p);
    s.insert(p);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&p);
        iter=s.lower_bound(p);
        //if(iter!=s.end())printf("%d",*iter);
        int hi=*iter;
        if(iter!=s.end())dp[p][1]=dp[hi][1]+1;
        if(iter!=s.begin())
        {
            int lo=*(--iter);
            dp[p][0]=dp[lo][0]+1;
          //  printf("%d ",lo);
        }
        s.insert(p);
    }
    for(int i=1;i<=n;i++)printf("%d\n",dp[i][0]+dp[i][1]+1);
    return 0;
}
