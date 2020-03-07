#include<bits/stdc++.h>
using namespace std;
#define maxn 300010
int a[maxn];
vector<int> x,y,now;
bool vis[maxn];
bool cmp(int x,int y){return x>y;}
deque<int> dq;
main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n/2;i++)
        {
            int k;scanf("%d",&k);
            vis[k]=1;
            x.push_back(k);
        }
        sort(x.begin(),x.end());
        for(int v : x)dq.push_back(v);
        for(int i=1;i<=n;i++)
            if(!vis[k])y.push_back(i);
        sort(y.begin(),y.end());
        int cnt=0,ans=0,cur=0;
        while(cur<y.size())
        {
            int v=y[cur];
            while(x.front()<v)x.pop_front(),cnt++;
        }
    }
    return 0;
}
