#include<bits/stdc++.h>
using namespace std;
int a[20];
set<int> s;
set<int>::iterator it;
main()
{
    int n;
    while(scanf("%d",&n))
    {
        s.clear();
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        s.insert(0);
        s.insert(a[0]);
        for(int i=1;i<n;i++)
        {
            set<int> s1;
            for(it=s.begin();it!=s.end();it++)s1.insert(*it+a[i]);
            for(it=s1.begin();it!=s1.end();it++)s.insert(*it);
            s1.clear();
        }
        //for(it=s.begin();it!=s.end();it++)printf("%d ",*it);puts("");
        printf("%d\n",s.size()-1);
    }

    return 0;
}
