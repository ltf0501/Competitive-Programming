#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
#define MAX 200000+10
int num[MAX];
int L[MAX];//L[i]為num[i]左邊相同元素的索引值
int R[MAX];//R[i]為num[i]右邊相同元素的索引值
map<int,int> m;

bool finds(int le,int ri)
{
    if(le>=ri)return true;
    for(int i=0;i<=(ri-le)/2;i++)
    {
        if(L[le+i]<le && R[le+i]>ri)return finds(le,le+i-1) && finds(le+i+1,ri);
        if(L[ri-i]<le && R[ri-i]>ri)return finds(le,ri-i-1) && finds(ri-i+1,ri);
    }
    return false;
}
main()
{
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&num[i]);
        m.clear();

        for(int i=0;i<n;i++)
        {
            if(m.find(num[i])==m.end())L[i]=-1;
            else L[i]=m[num[i]];
            m[num[i]]=i;
        }
        m.clear();
        for(int i=n-1;i>=0;i--)
        {
            if(m.find(num[i])==m.end())R[i]=n;
            else R[i]=m[num[i]];
            m[num[i]]=i;
        }

        if(finds(0,n-1))printf("non-boring\n");
		else printf("boring\n");
    }
    return 0;
}
