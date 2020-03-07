#include<bits/stdc++.h>
using namespace std;
int c[25];
void rot(vector<int> v)
{
    for(int t=0;t<2;t++)
    {
        int tmp=c[v[0]];
        for(int i=1;i<v.size();i++)c[v[i-1]]=c[v[i]];
        c[v.back()]=tmp;
    }
}
bool ok(vector<int> v)
{
    int col=c[v[0]];
    for(int i=1;i<v.size();i++)if(c[v[i]]!=col)return 0;
    return 1;
}
bool check()
{
    return ok({1,2,3,4}) && ok({5,6,7,8}) && ok({9,10,11,12})
        && ok({13,14,15,16}) && ok({17,18,19,20}) && ok({21,22,23,24});
}
void gao(int i)
{
    if(i==0)rot({1,3,5,7,9,11,24,22});
    if(i==1)rot({5,6,17,18,21,22,13,14});
    if(i==2)rot({3,4,17,19,10,9,16,14});
}
main()
{
    for(int i=1;i<=24;i++)scanf("%d",&c[i]);
    for(int i=0;i<3;i++)
    {
        gao(i);
        //for(int i=1;i<=24;i++)printf("%d ",c[i]);puts("");
        if(check())return 0*puts("YES");
        gao(i),gao(i);
        //for(int i=1;i<=24;i++)printf("%d ",c[i]);puts("");
        if(check())return 0*puts("YES");
        gao(i);
        //for(int i=1;i<=24;i++)printf("%d ",c[i]);puts("");
    }
    puts("NO");
    return 0;
}
