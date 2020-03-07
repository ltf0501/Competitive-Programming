#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=10005;

struct node
{
    int   id, p, d;   //d表示朝向，-1表示左，0表示碰撞中，1表示右。
    bool operator < (const node& S)const
    {
        return p<S.p;
    }
} befor[maxn],after[maxn];

char dirname[][10]={"L","Turning","R"};
int  order[maxn];

int main()
{
    int  T, n, L, t, tcase=0;
    int  ss[10005];
    cin >> T;
    while(T--)
    {
        scanf("%d%d%d",&L, &t, &n);
        printf("Case #%d:\n",++tcase);
        for(int i=0; i<n; i++)
        {
            int  p, d;
            char c;
            scanf("%d %c",&p,&c);
            d=(c=='L'?-1:1);
            befor[i]=(node){i,p,d};
            after[i]=(node){0,p+t*d,d};  //所以的蚂蚁相撞后可以看做对穿而过
        }
        sort(befor,befor+n);
        for(int i=0; i<n; i++)  //最巧妙的地方在这里，第一次从左到右所有的蚂蚁的相对位置没有变化
            order[befor[i].id]=i;
        sort(after,after+n);
        for(int i=0; i<n-1; i++)
            if(after[i].p==after[i+1].p)  after[i].d=after[i+1].d=0;
        for(int i=0; i<n; i++)
        {
            int a=order[i];
            if(after[a].p>=0&&after[a].p<=L)
            {
                printf("%d %s\n",after[a].p,dirname[after[a].d+1]);
            }
            else
                printf("Fell off\n");
        }
        puts("");
    }
    return 0;
}
