#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
char c[maxn];
int n;
main()
{
    scanf("%d",&n);
    scanf("%s",c+1);
    int id=n;
    for(int i=1;i<n;i++)if(c[i]>c[i+1]){id=i;break;}
    for(int i=1;i<=n;i++)
    {
        if(i!=id)putchar(c[i]);
    }
    return 0;
}

