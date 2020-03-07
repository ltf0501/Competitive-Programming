#include<algorithm>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;

main()
{
    string s;
    while(getline(cin,s))
    {
        int len=s.size();
        for(int i=0;i<s.size();i++)s[i]-=7;
        cout<<s<<endl;
    }
    return 0;
}
