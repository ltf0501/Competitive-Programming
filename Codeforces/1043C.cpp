#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
char c[maxn];
bool ans[maxn];
main()
{
    scanf("%s",c);
    int n=strlen(c);
    for(int i=1;i<n;i++)if(c[i]=='a')
        ans[i-1]^=1,ans[i]=1;
    for(int i=0;i<n;i++)printf("%d ",ans[i]);
    return 0;
}
