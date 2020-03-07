#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define maxn 20000+5
char c[maxn];
int Finds(int l,int r)
{
    priority_queue<int, vector<int>, greater<int> > pri;
    for(int i=l+1,now=i,cnt=0;i<r-1;i++)
    {
        if(c[i]=='[')cnt++;
        if(c[i]==']')
        {
            cnt--;
            if(!cnt)pri.push(Finds(now,i+1)),now=i+1;
        }
    }

    if(pri.empty())
    {
        int now=0;
        for(int i=l+1;i<r-1;i++)now*=10,now+=(c[i]-'0');
        pri.push((now+1)/2);
    }
    int sn=(pri.size()+1)/2,ret=0;
    for(int i=0;i<sn;i++)
    {
        ret+=pri.top();pri.pop();
    }
    return ret;
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%s",c);
        printf("%d\n",Finds(0,strlen(c)));
    }
    return 0;
}
