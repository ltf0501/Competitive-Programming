#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define pii pair<int,int>
#define F first
#define S second
int n,m,d;
int a[maxn],b[maxn];
set<pii> s;
main()
{
    scanf("%d%d%d",&n,&m,&d);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)s.insert(pii(a[i],i));
    int ans=0;
    while(!s.empty())
    {
        ans++;
        int id=s.begin()->S;s.erase(s.begin());
        while(1)
        {
            b[id]=ans;
            if(s.empty())break;
            auto it=s.lower_bound(pii(a[id]+d+1,-1));
            if(it==s.end())break;
            id=it->S;
            s.erase(it);
        }
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)printf("%d ",b[i]);
    return 0;
}
