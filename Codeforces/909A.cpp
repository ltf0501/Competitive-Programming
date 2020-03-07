#include<bits/stdc++.h>
using namespace std;
string s,t,ans;
main()
{
    cin>>s>>t;
    ans+=s[0];
    bool flag=0;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]>=t[0]){flag=1;ans+=t[0];break;}
        ans+=s[i];
    }
    if(!flag)ans+=t[0];
    cout<<ans;
    return 0;
}

