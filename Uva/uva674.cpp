#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

main()
{
    int t;cin>>t;
    while(t--)
    {
        int sl=0,sr=0,ml=0,mr=0;
        string s;
        cin>>s;
        int flag=1,len=s.size();
        for(int i=0;i<len;i++)
        {
            if(s[i]=='(')sl++;
            if(s[i]==')')sr++;
            if(s[i]=='[')ml++;
            if(s[i]==']')mr++;
            if(sr>sl || mr>ml){flag=0;break;}
        }
        if(!(sl==sr && ml==mr))flag=0;
        //printf("%d %d %d %d\n",sl,sr,ml,mr);
        if(flag==1)puts("Yes");
        else puts("No");
    }
}
