#include<bits/stdc++.h>
using namespace std;
int query(int x,int y)
{
    printf("? %d %d\n",x,y);fflush(stdout);
    char s[2];scanf("%s",s);
    if(s[0]=='x')return 1;
    else return 0;

}
main()
{
    char c[6];
    while(~scanf("%s",c) && c[0]=='s')
    {
        int mask=0;
        for(int i=5;i>=0;i--)
        {
            if(query(mask+(1<<i)-1,mask+(1<<i)))mask+=(1<<i);
        }
        printf("%d\n",mask);
    }
    return 0;
}
