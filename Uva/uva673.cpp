#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int Check(string s)
{
    int sta[200],idx=-1;
    for(int i=0;s[i];i++)
    {
        switch(s[i])
        {
            case '(':
                sta[++idx]='(';
                break;
            case '[':
                sta[++idx]='[';
                break;
            case ')':
                if(idx<0)return 0;
                if(sta[idx]=='(')idx--;
                else return 0;
                break;
            case ']':
                if(idx<0)return 0;
                if(sta[idx]=='[')idx--;
                else return 0;
                break;
        }
    }
    if(idx==-1)return 1;
    return 0;
}
main()
{
    int t;cin>>t;
    getchar();
    while(t--)
    {
        int sl=0,sr=0,ml=0,mr=0;
        string s;
        getline(cin,s);
        if(Check(s))puts("Yes");
        else puts("No");
    }
    return 0;
}
