#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
char a[20][40];
int b[20][40];
main()
{
    for(int i=0;i<20;i++)
        for(int j=0;j<40;j++){a[i][j]='.';b[i][j]=0;}

    for(int i=0;i<=14;i++)
    {
        cin>>a[i];
        //for(int j=30;j>=1;j++)a[i][j]=a[i][j-1];
    }

    for(int i=0;i<=14;i++)
    {
        for(int j=0;j<=29;j++)
        {
            if(a[i][j]=='*'){b[i][j]=-1;continue;}
            for(int x=-1;x<=1;x++)
            {
                for(int y=-1;y<=1;y++)
                {
                    if(x==0 && y==0)continue;
                    if(i+x>=0 && j+y>=0)
                    {
                        if(a[i+x][j+y]=='*')b[i][j]++;
                    }
                }
            }
        }
    }

    for(int i=0;i<=14;i++)
    {
        for(int j=0;j<=29;j++)
        {
            if(b[i][j]==-1)printf("*");
            else if(b[i][j]==0)printf(".");
            else printf("%d",b[i][j]);
        }
        puts("");
    }
    return 0;
}
