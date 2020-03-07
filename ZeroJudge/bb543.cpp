#include<cstdio>
#include<algorithm>
using namespace std;

struct Emp
{
    int a,b,c;
    bool operator < (const Emp x)const
    {
        return a<x.a&&c<x.b;
    }
};


int main()
{
    int t,n;
    while(scanf("%d",&t)==1)
    {
        while(t--)
        {
            scanf("%d",&n);
            Emp emp[n];
            for(int i=0;i<n;i++)
                scanf("%d%d%d",&emp[i].a,&emp[i].b,&emp[i].c);
            int s;
            scanf("%d",&s);
            swap(emp[0],emp[s-1]);
            int k=1;
            for(int i=0;i<k;i++)
            {
                for(int j=k;j<n;j++)
                {
                    if(emp[j]<emp[i])swap(emp[k++],emp[j]);
                }
            }
            printf("%d\n",k);
        }
    }
    return 0;
}
