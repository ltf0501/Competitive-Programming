#include<bits/stdc++.h>
using namespace std;

main()
{
    char s[4];
    scanf("%s",s);
    bool flag=0;
    if(s[0]==s[1] && s[1]==s[2])flag=1;
    if(s[1]==s[2] && s[2]==s[3])flag=1;
    puts(flag ? "Yes" : "No");
    return 0;
}

