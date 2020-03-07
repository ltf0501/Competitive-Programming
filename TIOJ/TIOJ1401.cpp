#include<bits/stdc++.h>
using namespace std;
#define maxn 100000+10
#define pii pair<int,int>
#define F first
#define S second
int n;
pii x[maxn],y[maxn];
map<int,int> mp;
bool sol(pii *a)
{
    sort(a+1,a+n+1);
    mp.clear();
    for(int i=1,j=1;i<=n;i++)
    {
        while(j<=n && a[j].F<=i) mp[a[j].S]++,j++;
        map<int,int>::iterator it=mp.begin();
        if(it->F < i)return 0;
        if(!(--it->S))mp.erase(it);
    }
    return 1;
}
main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)scanf("%d%d%d%d",&x[i].F,&x[i].S,&y[i].F,&y[i].S);
        if(!sol(x) || !sol(y))puts("NO");
        else puts("YES");
    }
    return 0;
}
