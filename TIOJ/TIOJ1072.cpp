#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 10000+5
struct str{int c,e;};
str stu[maxn];
int cmp(str a,str b)
{
    return max(a.c+a.e,a.c+b.c+b.e)<max(b.c+b.e,b.c+a.c+a.e);
}
main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<n;i++)scanf("%d%d",&stu[i].c,&stu[i].e);
        sort(stu,stu+n,cmp);
        int ans=0,sum=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,sum+stu[i].c+stu[i].e);
            sum+=stu[i].c;
        }
        printf("%d\n",ans);
    }
    return 0;
}
