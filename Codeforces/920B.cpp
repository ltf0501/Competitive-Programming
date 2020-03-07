#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
int l[maxn],r[maxn];
int n;
int ans[maxn];
queue<int> q;
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        while(!q.empty())q.pop();
        memset(ans,0,sizeof(ans));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d%d",&l[i],&r[i]);
        int cur=1;
        for(int i=1;i<=5000;i++)
        {
            while(cur<=n && l[cur]==i)q.push(cur++);
            //printf("%d\n",cur);
            while(!q.empty() && r[q.front()]<i)q.pop();
            if(q.empty())continue;
            int ii=q.front();q.pop();
            //printf("%d ",ii);
            ans[ii]=i;
        }
        for(int i=1;i<=n;i++)printf("%d ",ans[i]);puts("");
    }
    return 0;
}

