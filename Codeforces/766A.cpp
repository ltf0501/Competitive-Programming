#include<bits/stdc++.h>
using namespace std;

main()
{
    string s,t;
    cin>>s>>t;
    if(s==t)puts("-1");
    else printf("%d\n",max(s.size(),t.size()));
    return 0;
}
