#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char pre[55],in[55];
void print(int pre1,int pre2,int in1,int in2)
{
    if(pre1==pre2)return ;
    int root=in1;
    while(in[root]!=pre[pre1])root++;

    print(pre1+1,pre1+(root-in1)+1,in1,root);
    print(pre1+(root-in1)+1,pre2,root+1,in2);
    printf("%c",pre[pre1]);
}
main()
{
    while(~scanf("%s%s",pre,in))
    {
        print(0,strlen(pre),0,strlen(in));
        puts("");
    }
    return 0;
}
