#include<bits/stdc++.h>
using namespace std;
int m,n,sum;
int cnt;
bool column[20];
int v1[20],v2[20];
void backtrack(int x,int y,int cur)
{
    if(cur==sum)
    {
        cnt++;
        return ;
    }
    for(int i=0;i<sum;i++)
    {
        if(x)
        {
            if(!column[i] && !v1[cur+i] && !v2[cur-i+sum])
            {
                column[i]=1,v1[cur+i]=1,v2[cur-i+sum]=1;
                backtrack(x-1,y,cur+1);
                column[i]=0,v1[cur+i]=0,v2[cur-i+sum]=0;
            }
        }
        if(y)
        {
            if(!column[i] && v1[cur+i]!=1 && v2[cur-i+sum]!=1)
            {
                int a=v1[cur+i],b=v2[cur-i+sum];
                column[i]=1,v1[cur+i]=2,v2[cur-i+sum]=2;
                backtrack(x,y-1,cur+1);
                column[i]=0,v1[cur+i]=a,v2[cur-i+sum]=b;
            }
        }
    }
}
main()
{
    while(~scanf("%d%d",&m,&n))
    {
        memset(column,false,sizeof(column));
        memset(v1,false,sizeof(v1));memset(v2,false,sizeof(v2));
        sum=m+n;
        cnt=0;
        backtrack(m,n,0);
        printf("%d\n",cnt);
    }
    return 0;
}
