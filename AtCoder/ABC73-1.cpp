#include<bits/stdc++.h>
using namespace std;
char c[5];
main()
{
    scanf("%s",c);
    for(int i=0;i<strlen(c);i++)
    if(c[i]=='9'){puts("Yes");return 0;}
    puts("No");
    return 0;
}
