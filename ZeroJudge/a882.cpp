#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

main()
{
    int t;cin>>t;
    while(t--)
    {
        int ans=0;
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='X')ans+=2;
            if(s[i]=='H')ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
