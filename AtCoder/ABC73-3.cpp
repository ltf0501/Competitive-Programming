#include<bits/stdc++.h>
using namespace std;
set<int> s;
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        if(s.find(x)!=s.end())s.erase(x);
        else s.insert(x);
    }
    printf("%d\n",s.size());
    return 0;
}

