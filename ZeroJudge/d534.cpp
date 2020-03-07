#include<cstdio>
#include<algorithm>
using namespace std;

main()
{
    int x1,x2,y1,y2;
    while(scanf("%d%d%d%d",&x1,&x2,&y1,&y2)==4)
    {
        if(x1+x2!=y1+y2){puts("No solutions.");continue;}
        int a[5];

        if(x1<=x2 && y1<=y2)
        {
            a[1]=0;a[2]=x1;a[3]=y1;a[4]=x2-y1;
        }
        else if(x1>x2 && y1<=y2)
        {
            a[3]=0;a[1]=y1;a[4]=x2;a[2]=x1-y1;
        }
        else if(x1<=x2 && y1>y2)
        {
            a[2]=0;a[1]=x1;a[4]=y2;a[3]=y1-x1;
        }
        else if(x1>x2 && y1>y2)
        {
            a[4]=0;a[2]=y2;a[3]=x2;a[1]=x1-y2;
        }
        int b[5];
        b[1]=a[1];b[2]=a[2];b[3]=a[3];b[4]=a[4];
        sort(b+1,b+5);
        if(b[1]!=0 || b[2]!=1 || b[3]!=2 || b[4]!=3)puts("No solutions.");
        else printf("%d %d\n%d %d\n",a[1],a[2],a[3],a[4]);
    }
    return 0;
}
