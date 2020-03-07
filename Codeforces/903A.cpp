#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;scanf("%d",&n);
    while(n--)
    {
        int x;scanf("%d",&x);
        bool flag=0;
        for(int i=0;i*3<=x;i++)
        {
            if((x-3*i)%7==0){flag=1;break;}
        }
        puts(flag?"YES" :"NO");
    }
    return 0;
}
