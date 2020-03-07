#include<bits/stdc++.h>
using namespace std;
string s,t;
main()
{
    cin>>s>>t;
    reverse(s.begin(),s.end()),reverse(t.begin(),t.end());
    int n=s.size(),m=t.size();
    int k=-1;
    for(int i=0;i<min(n,m);i++)
        if(s[i]!=t[i]){k=i;break;}
    if(k==-1)k=min(n,m);
    printf("%d\n",n+m-2*k);
    return 0;
}
