#include<bits/stdc++.h>
using namespace std;
bool flag=0;
bool query(int x,int y)
{
    cout<<x<<' '<<y<<endl;
    string s;
    cin>>s;
    bool ok=(s=="white");
    if(flag)ok^=1;
    return ok;
}
main()
{
    int n;cin>>n;
    int x=0;
    bool flag=query(x,1);
    x++;
    while(x<n)
    {
        if(query(x,1))break;
        x++;
    }
    if(x==n)return cout<<0<<' '<<2<<' '<<1<<' '<<2<<endl,0;
    x--;
    int l=1,r=999999999;
    for(int i=x+2;i<n;i++)
    {
        int m=(l+r)>>1;
        if(query(x,m))r=m;
        else l=m;
    }
    cout<<x<<' '<<r-1<<' '<<x+1<<' '<<0<<endl;
    return 0;
}
