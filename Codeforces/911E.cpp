#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
int ans[maxn],cnt;
bool vis[maxn];
stack<int> s1,s2;
main()
{
    int n,k;scanf("%d%d",&n,&k);
    int cur=1;
    for(int i=1;i<=k;i++)
    {
        int x;scanf("%d",&x);
        ans[cnt++]=x;
        vis[x]=1;
        if(!s1.empty() && x>s1.top()){puts("-1");return 0;}
        s1.push(x);
        while(!s1.empty() && s1.top()==cur){s1.pop();cur++;}
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i])
        {
            while(!s2.empty())
            {
                ans[cnt++]=s2.top();
                s2.pop();
            }
        }
        else s2.push(i);
    }
    while(!s2.empty())
    {
        ans[cnt++]=s2.top();s2.pop();
    }
    for(int i=0;i<n;i++)printf("%d ",ans[i]);
    return 0;
}
