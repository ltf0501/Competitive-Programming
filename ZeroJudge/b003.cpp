#include<cstdio>
#include<algorithm>
using namespace std;

main()
{
    int n,k;
    while(scanf("%d",&k)==1)
    {
        k=abs(k);
        int cur=0;
        while(cur*(cur+1)<2*k)cur++;
        if(k&1 &&(cur+1)%4==0)cur+=2;
        else if(k&1 &&cur%4==0)cur++;
        else if(!(k&1) &&(cur+3)%4==0)cur+=2;
        else if(!(k&1) &&(cur+2)%4==0)cur++;
        printf("%d\n",cur);
    }
    return 0;
}
