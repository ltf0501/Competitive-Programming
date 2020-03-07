#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 100000+5
struct node
{
    int nc,h;
    node(int _h=0){nc=0;h=_h;return;}
}stk[maxn];
int ptr;
char buf[maxn];
int main()
{
    while(~scanf("%s",buf))
    {
        ptr=1;
        stk[0]=node(1);
        int max_nc=0;
        int max_h=1;
        int leaf_cnt=0;
        for(int lx=0;lx<strlen(buf);lx++)
        {
            if(buf[lx] == '(')
            {
                stk[ptr-1].nc++;
                stk[ptr]=node(stk[ptr-1].h+1);
                ptr++;
            }
            else if(buf[lx]==')')
            {
                max_h=max(max_h,stk[ptr-1].h);
                max_nc=max(max_nc,stk[ptr-1].nc);
                ptr--;
            }
            else if(buf[lx]=='*')
            {
                stk[ptr-1].nc++;
                leaf_cnt++;
            }
        }
        printf("%d %d %d\n",leaf_cnt,max_h,max_nc);
    }
    return 0;
}
