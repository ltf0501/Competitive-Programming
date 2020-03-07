#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

void build(int left,int right,int height)
{
    if(height==0 || (left>right)) return;
    //下一個root應盡可能靠左,所以把右子樹填滿
    int right_space=(1<<(height-1))-1;
    int root=right-right_space;
    if(root<left) root=left;
    printf(" %d",root);


    build(left,root - 1,height-1);
    build(root+1,right,height-1);
}

main()
{
    int t=1;
    int n,h;
    while(scanf("%d %d",&n,&h)==2 &&(n || h))
    {
        printf("Case %d:",t++);
        if((1<<h)-1<n)
        {
            printf(" Impossible.\n");
            continue;
        }
        if(h>n)h=n;
        build(1,n,h);
        printf("\n");
    }
    return 0;
}
