#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue<double> pq;
int main()
{
    int n;scanf("%d",&n);
    while(n--)
    {
        char a[5];double b;
        scanf("%s %lf",a,&b);
        pq.push(-b);
    }
    double ans=0;
    while(pq.size()>=2)
    {
        double a,b;
        a=pq.top();pq.pop();
        b=pq.top();pq.pop();
        ans+=a+b;
        pq.push(a+b);
    }
    printf("%.2f",-ans);
    return 0;
}
