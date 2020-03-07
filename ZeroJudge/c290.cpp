#include<bits/stdc++.h>
using namespace std;
string s;
main()
{
    cin>>s;
    int ans=0;
    int flag=1;
    for(int i=0;i<s.size();i++)
        ans+=(s[i]-'0')*flag,flag=-flag;
    cout<<abs(ans)<<'\n';
    return 0;
}
