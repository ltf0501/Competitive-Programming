#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
int d[maxn];
main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        d[x]++,d[y]++;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(d[i]&1)cnt++;
    puts((cnt==0 || cnt==2) ? "YES" : "NO");
    return 0;
}
