#include<bits/stdc++.h>
using namespace std;
int a[6][3];
main()
{
    a[0][0]=a[1][1]=a[2][2]=a[3][2]=a[4][1]=a[5][0]=0;
    a[0][1]=a[1][0]=a[2][0]=a[3][1]=a[4][2]=a[5][2]=1;
    a[0][2]=a[1][2]=a[2][1]=a[3][0]=a[4][0]=a[5][1]=2;
    int n,x;scanf("%d%d",&n,&x);
    printf("%d\n",a[n%6][x]);
    return 0;
}
