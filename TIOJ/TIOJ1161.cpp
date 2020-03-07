#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second
#define mkp make_pair
#define maxn 1000010
pii s[maxn];
multiset< int,greater<int> > ms;
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,k;scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
        {
            int x,y;scanf("%d%d",&x,&y);
            s[i]=mkp(x,y);
        }
        sort(s,s+n);
        int ans=2*maxn;
        ms.clear();
        for(int i=0;i<n;)
        {
            int j;
            for(j=i;j<n && s[j].F==s[i].F;j++)
            {
                ms.insert(s[j].S);
                if(ms.size()>k)ms.erase(ms.begin());
            }
            i=j;
            if(i>=k)ans=min(ans,s[i-1].F+(*ms.begin()));
        }
        printf("%d\n",ans);
    }
    return 0;
}
