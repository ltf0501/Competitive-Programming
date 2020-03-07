#include<bits/stdc++.h>
using namespace std;
#define maxn 800010
int n,x;
int s[maxn];
main()
{
    scanf("%d%d",&n,&x);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int a,b;scanf("%d%d",&a,&b);
        s[a+b]++;
        if(s[a+b]==x)cnt++;
        if(s[a+b]==x+1)cnt--;
    }
    printf("%d\n",cnt);
    return 0;
}
