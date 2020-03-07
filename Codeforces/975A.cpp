#include<bits/stdc++.h>
using namespace std;
set<int> S;
main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        int t=0;
        for(auto c : s)t|=1<<(c-'a');
        S.insert(t);
    }
    printf("%d\n",S.size());
    return 0;
}
