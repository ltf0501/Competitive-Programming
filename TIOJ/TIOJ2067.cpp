#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
            for(int k=0;k<i;k++)printf("%c",'a'+k);
        printf("%c\n",'a');
    }
    return 0;
}
