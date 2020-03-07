#include<bits/stdc++.h>
using namespace std;
string s,t;
main()
{
    cin>>s>>t;
    int n;scanf("%d",&n);
    cout<<s<<' '<<t<<endl;
    while(n--)
    {
        string a,b;cin>>a>>b;
        if(a==s)s=b;else t=b;
        cout<<s<<' '<<t<<endl;
    }
    return 0;
}
