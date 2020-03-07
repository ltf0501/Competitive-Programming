#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
#define maxn 10000000+10
main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        int len=s1.size();
        int flag=1;
        int m;
        for(int i=0;i<len;i++)
        {
            if(s1[i]==s2[i]){m=i;break;}
        }
        //printf("%d\n",m);
        for(int i=0;i<=m;i++)
        {
            s2[i]='0'+'1'-s2[i];
        }

        for(int i=0;i<len;i++)printf("%c",s2[i]);


        printf("\n");
    }
    return 0;
}
