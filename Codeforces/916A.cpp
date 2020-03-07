#include<bits/stdc++.h>
using namespace std;
int x,w,h;
bool check(int w,int h)
{
    return (w-7)%10==0 || (h-7)%10==0;
}
main()
{
    scanf("%d%d%d",&x,&w,&h);
    for(int i=0;;i++)
    {
        if(check(w,h))return 0*printf("%d\n",i);
        if(h>=x)h-=x;
        else
        {
            h+=(60-x);
            w--;
            if(w<0)w+=24;
        }
    }
    return 0;
}

