#include<bits/stdc++.h>
using namespace std;
string s,t;
int a[55],b[55];
main()
{
    cin>>s>>t;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]<='Z')a[26+s[i]-'A']++;
        else a[s[i]-'a']++;

    }
    for(int i=0;i<t.size();i++)
    {
        if(t[i]<='Z')b[26+t[i]-'A']++;
        else b[t[i]-'a']++;
    }
    int f=0,l=0;
    for(int i=0;i<52;i++)
    {
        int k=min(a[i],b[i]);
        f+=k,a[i]-=k,b[i]-=k;
    }
    for(int i=0;i<52;i++)
    {
        int k=min(a[i],b[(i+26)%52]);
        l+=k,a[i]-=k,b[(i+26)%52]-=k;
    }
    printf("%d %d\n",f,l);
    return 0;
}

