#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
map<int,int> m;
main()
{
    int n;
    int Max=0,Min;
    while(~scanf("%d",&n) && n)
    {
        m.insert(pair<int,int>(n,0));
        m[n]++;
        if(m[n]>Max)Max=m[n],Min=n;
        else if(m[n]==Max)Min=min(Min,n);
        printf("%d %d\n",Max,Min);
    }
    return 0;
}
