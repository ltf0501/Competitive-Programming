#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
vector<int> g[maxn];
int in[maxn];
queue<int> s;
main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)g[i].clear();
        memset(in,0,sizeof(in));
        while(!s.empty())s.pop();
        for(int i=0;i<m;i++)
        {
            int x,y;scanf("%d%d",&x,&y);
            g[x].push_back(y);
            in[y]++;
        }
        for(int i=0;i<n;i++)
        {
            int x;scanf("%d",&x);
            s.push(x);
        }
        bool flag=1;
        while(!s.empty())
        {
            int t=s.front();s.pop();
            if(in[t]){flag=0;break;}
            for(int v : g[t])in[v]--;
        }
        puts(flag ? "YES" : "NO");
    }

    return 0;
}
