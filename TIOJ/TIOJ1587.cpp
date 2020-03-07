#include<bits/stdc++.h>
using namespace std;
string s;
main()
{
    cin.tie(0);ios::sync_with_stdio(false);
    cin>>s;
    cout<<s;
    for(int i=s.size()-2;i>=0;i--)cout<<s[i];
    return 0;
}
