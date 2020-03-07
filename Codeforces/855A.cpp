#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        if(mp.find(s)!=mp.end())puts("YES");
        else puts("NO"),mp[s]=1;
    }
    return 0;
}

