#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;

struct Point
{
    int a,b;
    bool operator < (const Point& rhs)const
    {
        return a>rhs.a || (a==rhs.a && b>rhs.b);
    }
};
multiset<Point> S;
multiset<Point>::iterator it;
main()
{
    int t;scanf("%d",&t);
    int h[20000],w[20000];
    while(t--)
    {
        int n,m;
        S.clear();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%d%d",&h[i],&w[i]);
        int H=h[m],W=w[m];
        for(int i=1;i<=n;i++)
        {
            if(h[i]>=H && w[i]>=W)
            {
                Point P=(Point){h[i],w[i]};
                it=S.lower_bound(P);
                if(it==S.begin() || (--it)->b>w[i])
                {
                    S.insert(P);
                    it=S.upper_bound(P);
                    while(it!=S.end() && it->b>=w[i])S.erase(it++);
                }
            }
        }
        printf("%d\n",S.size());

    }
    return 0;
}
