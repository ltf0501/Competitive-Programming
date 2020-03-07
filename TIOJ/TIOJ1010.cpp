#include<bits/stdc++.h>
using namespace std;
string a,b;
bool cmp(int len)
{
    for(int i=0;i<len;i++)
        if(a[i]!=b[b.size()-len+i])return 0;
    return 1;
}
main()
{

    cin>>a>>b;
    int l=min(a.size(),b.size());
    for(int i=l;l>=0;i--)
        if(cmp(i)){printf("%d\n",i);break;}
    return 0;
}
