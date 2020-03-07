#include<bits/stdc++.h>
using namespace std;
string rev(string s)
{
    string t;
    int n=s.size();
    for(int i=0;i<n;i++)t+=s[n-i-1];
    return t;
}
main()
{
    string s;cin>>s;
    string t=rev(s);
    //cout<<t<<'\n';
    cout<<s<<t<<'\n';
    return 0;
}
