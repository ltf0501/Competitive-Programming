#include<bits/stdc++.h>
using namespace std;
char c[2];
main()
{
    scanf("%s",c);
    for(int i=0;i<5;i++)
    {
        char s[2];scanf("%s",s);
        if(s[0]==c[0] || s[1]==c[1])return 0*puts("YES");
    }
    puts("NO");
    return 0;
}

