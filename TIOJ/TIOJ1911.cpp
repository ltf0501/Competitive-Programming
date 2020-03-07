#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;

main()
{
    int x;
    multiset<int> s;
    multiset<int>::iterator it;
    while(scanf("%d",&x)==1 && x)
    {
        if(x>0)s.insert(x);
        if(x==-1)
        {
            if(s.empty())continue;
            it=s.begin();
            int u=*it;
            printf("%d ",u);
            s.erase(it);
        }
        if(x==-2)
        {
            if(s.empty())continue;
            it=s.end();
            int u=*(--it);
            printf("%d ",u);
            s.erase(it);
        }
        /*
        for(it=s.begin();it!=s.end();it++)printf("%d ",*it);
        puts("");
        */
    }
    puts("");
    return 0;
}
