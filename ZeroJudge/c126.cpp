#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char pre[30],in[30];
void print_ans(int pre1,int pre2,int in1,int in2)
{
    if(pre1==pre2)return ;
    int r=in1;
    while(in[r]!=pre[pre1])r++;
    print_ans(pre1+1,pre1+(r-in1)+1,in1,r);
    print_ans(pre1+(r-in1)+1,pre2,r+1,in2);
    printf("%c",pre[pre1]);
}
main()
{
    while(~scanf("%s%s",pre,in))
    {
        print_ans(0,strlen(pre),0,strlen(pre));
        puts("");
    }
    return 0;
}
