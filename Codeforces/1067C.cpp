#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
int n;
main()
{
    scanf("%d",&n);
    for(int i=1;n;i++)
    {
        if(i&1)printf("%d %d\n",i,0),n--;
        else
        {
            printf("%d %d\n",i,-1);
            if(!(--n))break;
            printf("%d %d\n",i,1);
            n--;
        }
    }
    return 0;
}
