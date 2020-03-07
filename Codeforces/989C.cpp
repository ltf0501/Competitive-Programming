#include<bits/stdc++.h>
using namespace std;
int num[4],cur1,cur2,c1[2],c2[2];
char s[55][55];
main()
{
    for(int i=0;i<4;i++)scanf("%d",&num[i]);
    int n=24,m=0;
    for(int i=0;;i++)
    {
        printf("%d %d %d %d\n",num[0],num[1],num[2],num[3]);
        if(!num[0] && !num[1] && !num[2] && !num[3]){m=i;break;}
        for(int k=0;k<2;k++)
        {
            if(num[0]!=0 && num[2]!=0)
            {
                if(c1[k]&1)
                {
                    for(int j=12*k;j<12*k+3;j++)s[i][j]='A';
                    for(int j=12*k+6;j<12*k+9;j++)s[i][j]='C';
                }
                else
                {
                    for(int j=12*k;j<12*k+3;j++)s[i][j]='C';
                    for(int j=12*k+6;j<12*k+9;j++)s[i][j]='A';
                }
                num[0]--,num[2]--;
                c1[k]=i+1;
            }
            else if(!num[0] && !num[2])
            {
                if(c1[k]&1)
                {
                    for(int j=12*k;j<12*k+3;j++)s[i][j]='C';
                    for(int j=12*k+6;j<12*k+9;j++)s[i][j]='A';
                }
                else
                {
                    for(int j=12*k;j<12*k+3;j++)s[i][j]='A';
                    for(int j=12*k+6;j<12*k+9;j++)s[i][j]='C';
                }
            }
            else
            {
                if(!(c1[k]&1))
                {
                    for(int j=12*k;j<12*k+3;j++)s[i][j]='A';
                    for(int j=12*k+6;j<12*k+9;j++)s[i][j]='C';
                }
                else
                {
                    for(int j=12*k;j<12*k+3;j++)s[i][j]='C';
                    for(int j=12*k+6;j<12*k+9;j++)s[i][j]='A';
                }
                if(num[2])
                {
                    if(!(c1[k]&1))
                    {
                        s[i][12*k+cur1]='C';

                    }
                    else s[i][12*k+6+cur1]='C';

                    cur1=(cur1+1)%3;
                    num[2]--;
                }
                else
                {
                    if(!(c1[k]&1))s[i][12*k+6+cur1]='A';
                    else s[i][12*k+cur1]='A';
                    cur1=(cur1+1)%3;
                    num[0]--;
                }
            }
            if(num[1]!=0 && num[3]!=0)
            {
                if(c2[k]&1)
                {
                    for(int j=12*k+3;j<12*k+6;j++)s[i][j]='B';
                    for(int j=12*k+9;j<12*k+12;j++)s[i][j]='D';
                }
                else
                {
                    for(int j=12*k+3;j<12*k+6;j++)s[i][j]='D';
                    for(int j=12*k+9;j<12*k+12;j++)s[i][j]='B';
                }
                num[1]--,num[3]--;
                c2[k]=i+1;
            }
            else if(!num[1] && !num[3])
            {
                if(c2[k]&1)
                {
                    for(int j=12*k+3;j<12*k+6;j++)s[i][j]='B';
                    for(int j=12*k+9;j<12*k+12;j++)s[i][j]='D';
                }
                else
                {
                    for(int j=12*k+3;j<12*k+6;j++)s[i][j]='D';
                    for(int j=12*k+9;j<12*k+12;j++)s[i][j]='B';
                }
            }
            else
            {
                if(!(c2[k]&1))
                {
                    for(int j=12*k+3;j<12*k+6;j++)s[i][j]='B';
                    for(int j=12*k+9;j<12*k+12;j++)s[i][j]='D';
                }
                else
                {
                    for(int j=12*k+3;j<12*k+6;j++)s[i][j]='D';
                    for(int j=12*k+9;j<12*k+12;j++)s[i][j]='B';
                }
                if(num[3])
                {
                    if(!(c1[k]&1))s[i][12*k+3+cur1]='B';
                    else s[i][12*k+9+cur1]='B';
                    cur2=(cur2+1)%3;
                    num[3]--;
                }
                else
                {
                    if(!(c1[k]&1))s[i][12*k+9+cur1]='B';
                    else s[i][12*k+3+cur1]='B';
                    cur2=(cur2+1)%3;
                    num[1]--;
                }
            }
        }
    }
    printf("%d %d\n",m,n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)printf("%c",s[i][j]);puts("");
    }
    return 0;
}
