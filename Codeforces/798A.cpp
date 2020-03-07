#include<bits/stdc++.h>
using namespace std;
string s;
main()
{
    cin>>s;
    int len=s.size();
    int cnt=0;
    for(int i=0;i<len-1-i;i++)
        if(s[i]!=s[len-1-i])cnt++;
    if(cnt==1)puts("YES");
    else
    {
        if(cnt==0 && len&1)puts("YES");
        else puts("NO");
    }
    return 0;
}
