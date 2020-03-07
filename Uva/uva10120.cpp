#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int n,m;

bool check(int now,int step)
{
    if(now<1 || now>n)return false;
    if(now==m)return true;
    return check(now+2*step-1,step+1) || check(now-2*step+1,step+1);
}

main()
{
    while(scanf("%d %d",&n,&m)==2 && (n || m))
    {
        if(n>=49 || check(1,2))printf("Let me try!\n");
        else printf("Don't make fun of me!\n");
    }
    return 0;
}
