#include<bits/stdc++.h>
using namespace std;
int n;
char c[105];
main()
{
    scanf("%d",&n);
    scanf("%s",c+1);
    for(int k=n/2;k>=2;k--)
    {
        bool flag=1;
        for(int i=1;i<=k;i++)if(c[i]!=c[i+k]){flag=0;break;}
        if(flag)return 0*printf("%d\n",n-k+1);
    }
    printf("%d\n",n);
    return 0;
}
