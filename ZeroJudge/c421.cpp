#include<bits/stdc++.h>
using namespace std;
multiset<int> s;
main()
{
    int x;
    while(~scanf("%d",&x) && x)
    {
        if(x>0)s.insert(x);
        else if(x==-1)
        {
            if(s.empty())continue;
            else
            {
                auto it=s.begin();
                printf("%d ",*it);
                s.erase(it);
            }
        }
        else
        {
            if(s.empty())continue;
            else
            {
                auto it=--s.end();
                printf("%d ",*it);
                s.erase(it);
            }
        }
    }
    return 0;
}
