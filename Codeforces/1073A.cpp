#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
char c[maxn];
main()
{
    int n;scanf("%d",&n);
    scanf("%s",c+1);
    for(int i=1;i<n;i++)
    {
        if(c[i]!=c[i+1])
        {
            puts("YES");
            printf("%c%c\n",c[i],c[i+1]);
            return 0;
        }
    }
    puts("NO");
    return 0;
}

