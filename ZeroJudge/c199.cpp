#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
int h[maxn];
main()
{
    int n;scanf("%d",&n);
    int cnt=0,j=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
        if(i==1 || i==2)continue;
        if(h[i]==h[i-1])continue;
        if(h[i-1]>h[j] && h[i-1]>h[i])cnt++;
        j=i-1;
    }
    printf("%d\n",cnt);
    return 0;
}
