#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n,a[maxn];
set<int> s;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        if(x!=0)s.insert(x);
    }
    printf("%d\n",s.size());
    return 0;
}

