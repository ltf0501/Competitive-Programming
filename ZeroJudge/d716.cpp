#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
int n;
int a[maxn];
set<int> s;
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        s.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        int l=0,r=0;
        int ans=0;
        while(r<n)
        {
            if(s.find(a[r+1])!=s.end())s.erase(a[++l]);
            else s.insert(a[++r]),ans=max(ans,r-l);
        }
        printf("%d\n",ans);
    }
    return 0;
}
