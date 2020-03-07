#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
int n;
int a[maxn];
char c[maxn];
struct ii
{
    int x;
    bool operator < (const ii& b)const
    {
        return a[x]<a[b.x];
    }
};
set<ii> s1,s2;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    scanf("%s",c+1);
    for(int i=1;i<=n;i++)s1.insert((ii){i});
    for(int i=1;i<=2*n;i++)
    {
        if(c[i]=='0')
        {
            auto it=s1.begin();
            int s=it->x;
            printf("%d ",s);
            s1.erase(it);
            s2.insert((ii){s});
        }
        else
        {
            auto it=(--s2.end());
            int s=it->x;
            printf("%d ",s);
            s2.erase(it);
        }
    }
    return 0;
}
