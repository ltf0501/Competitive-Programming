#include<bits/stdc++.h>
using namespace std;
int n;
char c[105];
main()
{
    scanf("%d",&n);
    scanf("%s",c+1);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(i<n && c[i]!=c[i+1])cnt++,i++;
    }
    printf("%d\n",n-cnt);
    return 0;
}
