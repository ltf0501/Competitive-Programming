#include<cstdio>
#include<algorithm>
using namespace std;
main()
{
    int t,s[505];
    scanf("%d",&t);
    while(t--)
    {
        int r;
        scanf("%d",&r);
        for(int i=0;i<r;i++)scanf("%d",&s[i]);
        sort(s,s+r);
        int p=r/2;
        int sum=0;
        for(int i=0;i<r;i++)sum+=abs(s[p]-s[i]);
        printf("%d\n",sum);
    }
    return 0;
}
/*
2
2 2 4
3 2 4 6

2
4
*/
