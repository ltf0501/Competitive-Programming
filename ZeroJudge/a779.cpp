#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cctype>
using namespace std;

main()
{
    string line;
    while(getline(cin,line))
    {
        string s;
        for(int i=0;i<line.size();i++)
        {
            if(line[i]<='Z' && line[i]>='A')s+=line[i]-'A'+'a';
            else if(line[i]<='z' && line[i]>='a')s+=line[i];
            else if(line[i]<='9' && line[i]>='0')s+=line[i];
        }
        int len=s.size();
        int flag=1;
        for(int i=0,j=s.size()-1;i<j;i++,j--)
        {
            if(s[i]!=s[j]){flag=0;break;}
        }
        cout<<line<<endl;
        if(flag)puts("-- is a palindrome");
        else puts("-- is not a palindrome");
    }
    return 0;
}
