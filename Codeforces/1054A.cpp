#include<bits/stdc++.h>
using namespace std;

main()
{
    int x,y,z,t1,t2,t3;scanf("%d%d%d%d%d%d",&x,&y,&z,&t1,&t2,&t3);
    int p=abs(x-y)*t1;
    int q=abs(x-z)*t2+2*t3+abs(x-y)*t2+t3;
    //printf("%d %d\n",p,q);
    puts(q<=p ? "YES" : "NO");
    return 0;
}

