#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;
void  f(int x,int y);
char p[105][105];
int main()
{
    int a,b,c;

    while(cin>>a)
    {
        int sum=0;
        memset(p,'+',sizeof(p));
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=a;j++)
            {
                cin>>p[i][j];
            }
        }
        cin>>b>>c;
        f(b+1,c+1);
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=a;j++)
            {
                cout<<p[i][j];
            }
        cout<<endl;
        }
    }
}
void f(int x,int y)
{

    if(p[x][y]=='+')return;
    if(p[x][y]=='-')
    {
        p[x][y]='+';
        f(x+1,y);
        f(x-1,y);
        f(x,y+1);
        f(x,y-1);
    }
}
/*
7
-------
-+++---
-+--+--
-+---+-
--+++--
---++--
-------
3 4
*/
