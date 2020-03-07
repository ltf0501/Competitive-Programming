#include<bits/stdc++.h>
using namespace std;
int n;
int query(int x)
{
    x%=n;if(x<=0)x+=n;
    printf("%d\n",x);fflush(stdout);
    int a;scanf("%d",&a);
    return a;
}
main()
{
    scanf("%d",&n);
    if(n%4==2){printf("! -1\n");fflush(stdout);return 0;}
    int s=query(0),t=query(n/2);
    if(s==t){printf("! %d\n",n/2);fflush(stdout);return 0;}
    int now=0;
    int l=0,r=n/2;
    while(1)
    {
        int m=(l+r)>>1;
        int p=query(m),q=query(m+n/2);
        if(p==q){printf("! %d\n",m);fflush(stdout);return 0;}
        if((p<q)^(s<t))r=m;
        else l=m+1;
    }
    return 0;
}
