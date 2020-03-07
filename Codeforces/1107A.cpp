#include<bits/stdc++.h>
using namespace std;
char c[305];
main()
{
    int q;scanf("%d",&q);
    while(q--)
    {
        int n;scanf("%d",&n);
        scanf("%s",c);
        if(n==2 && c[0]>=c[1])puts("NO");
        else
        {
            puts("YES");
            puts("2");
            printf("%c ",c[0]);
            for(int i=1;i<n;i++)printf("%c",c[i]);puts("");
        }
    }
    return 0;
}

