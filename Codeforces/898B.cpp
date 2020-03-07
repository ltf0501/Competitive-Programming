#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,a,b;scanf("%d%d%d",&n,&a,&b);
    //if(n%__gcd(a,b)!=0){puts("NO");return ;}

    for(int i=0;i*a<=n;i++)
    {
        int k=i*a;
        if((n-k)%b==0)
        {
            int j=(n-k)/b;
            puts("YES");
            printf("%d %d\n",i,j);
            return 0;
        }
    }
    puts("NO");
    return 0;
}
