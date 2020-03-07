#include<bits/stdc++.h>
using namespace std;
#define maxn 120010
map<int,int> mp;
int a[maxn];
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        mp[a[i]]++;
    }
    int num=0;
    for(int i=1;i<=n;i++)
    {
        bool ok=0;
        for(int j=0;j<31;j++)
        {
            int x=(1<<j)-a[i];
            if(mp.count(x) && (mp[x]>=2 ||(mp[x]==1 && x!=a[i])))ok=1;
        }
        if(!ok)num++;
    }
    printf("%d\n",num);
    return 0;
}
