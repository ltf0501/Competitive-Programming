#include<bits/stdc++.h>
using namespace std;
int n;
int x[3],y[3];
main()
{
    scanf("%d",&n);
    for(int i=0;i<3;i++)scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=2;i++)x[i]-=x[0],y[i]-=y[0];
    if(x[1]*x[2]>0 && y[1]*y[2]>0)puts("Yes");
    else puts("No");
    return 0;
}
