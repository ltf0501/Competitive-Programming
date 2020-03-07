#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 205
struct node
{
    int v,id;
    bool operator < (const node& b)const
    {
        return v<b.v;
    }
}a[maxn];
main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i].v);
        a[i].id=i;
    }
    sort(a,a+n);
    int cnt=0;
    node tmp;
    bool flag=1;
    while(flag)
    {
        flag=0;
        node tmp;
        for(int i=0;i<n;i++)
        {
            if(a[i].v>=0 && (!flag || a[i].id>tmp.id && a[i].v>tmp.v))
            {
                tmp=a[i];
                a[i].v=-1;
                flag=1;
            }
        }
        if(flag)cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
