#include<bits/stdc++.h>
using namespace std;
string s;
int k;
set<string> ss;
main()
{
    cin>>s>>k;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        string t;
        for(int j=i;j<min(i+5,n);j++)
        {
            t+=s[j];
            ss.insert(t);
        }
    }
    auto it=ss.begin();
    k--;
    while(k--)it++;
    cout<<*it;
    return 0;
}
