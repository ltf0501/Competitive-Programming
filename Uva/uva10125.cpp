#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int num[1005];
int answer, a, b, c, d, n, i;

bool find()
{
    for(a=n-1;a>=0;--a)
    {
        for(b=n-1;b>1;--b)
        {
            if(a == b)continue;
            answer=num[a]-num[b];
            for(c=0,d=b-1;c<d;)
            {
                if(num[c]+num[d]==answer)return true;
                else if(num[c]+num[d]<answer)++c;
                else --d;
            }
        }
    }
    return false;
}

int main()
{
    while(scanf("%d",&n),n)
    {
        for(i=0;i<n;++i)scanf("%d",&num[i]);
        sort(num,num+n);
        if(find())printf("%d\n",num[a]);
        else puts("no solution");
    }
    return 0;
}
