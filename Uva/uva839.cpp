#include<cstdio>
using namespace std;

bool solve(int &w)
{
    int w1,d1,w2,d2;
    bool b1=true,b2=true;
    scanf("%d%d%d%d",&w1,&d1,&w2,&d2);
    if(!w1)b1=solve(w1);
    if(!w2)b2=solve(w2);
    w=w1+w2;
    return b1 && b2 && (w1*d1==w2*d2);
}

main()
{
    int t,w;
    scanf("%d",&t);
    while(t--)
    {
        if(solve(w))printf("YES\n");else printf("NO\n");
        if(t)printf("\n");
    }
}
