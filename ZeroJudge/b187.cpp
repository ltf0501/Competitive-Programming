#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int trans(char a)
{
    if(a>='0' && a<='9')return a-'0';
    if(a>='A' && a<='F')return a-'A'+10;
}

main()
{
    string s;
    puts("�Q���i���ܪk  �۹������Q�i���ܪk");
    while(cin>>s)
    {
        int a=16*trans(s[0])+trans(s[1]);
        cout<<"      "<<s;
        printf("                 %d\n",a);
    }
    return 0;
}
