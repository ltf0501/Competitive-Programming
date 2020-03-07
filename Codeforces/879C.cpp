#include<bits/stdc++.h>
using namespace std;
#define maxn 500050
char c[maxn],r[3];
int a[maxn];
int k[3];
main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>c[i]>>a[i];
    r[0]='|',r[1]='&',r[2]='^';
    k[0]=0,k[1]=1023,k[2]=0;
    int f=3;
    for(int i=1;i<=n;i++)
    {
        if(c[i]=='|')k[0]|=a[i];
        else if(c[i]=='&')k[1]&=a[i];
        else k[2]^=a[2];
        if(f==3 && c[i]=='|')f=0;
        else if(f==3 && c[i]=='&')f=1;
    }
    if(f==3)f=0;
    cout<<3<<'\n';
    cout<<r[f]<<' '<<k[f]<<'\n'<<r[f^1]<<' '<<k[f^1]<<'\n';
    cout<<r[2]<<' '<<k[2]<<'\n';
    return 0;
}
