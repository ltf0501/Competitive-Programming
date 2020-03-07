#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
bool ok(char s)
{
    return s=='a' || s=='e' || s=='i' || s=='o' || s=='u';
}
char a[maxn],b[maxn];
main()
{
    scanf("%s %s",a,b);
    int n=strlen(a);
    int m=strlen(b);
    if(n!=m)return 0*puts("No");
    for(int i=0;i<n;i++)
        if(ok(a[i])!=ok(b[i]))return 0*puts("No");
    puts("Yes");
    return 0;
}

