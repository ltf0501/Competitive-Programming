#include<cstdio>
#include<queue>
using namespace std;

struct Item
{
    int QNum,Period,Time;
    bool operator < (const Item& a)const
    {
        return Time>a.Time || (Time==a.Time && QNum>a.QNum);
    }
};
main()
{
    priority_queue<Item> pq;
    char s[20];
    while(scanf("%s",s)==1 && s[0]!='#')
    {
        Item item;
        scanf("%d%d",&item.QNum,&item.Period);
        item.Time=item.Period;
        pq.push(item);
    }
    int k;scanf("%d",&k);
    while(k--)
    {
        Item r=pq.top();
        pq.pop();
        printf("%d\n",r.QNum);
        r.Time+=r.Period;
        pq.push(r);
    }
    return 0;
}
