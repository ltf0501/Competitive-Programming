#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

main()
{
    int n;
    queue<int> card;
    bool comma;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=1;i<=n;i++)card.push(i);
        printf("Discarded cards:");
        comma=false;
        while(card.size()!=1)
        {
            if(comma)printf(",");
            comma=true;
            printf(" %d",card.front());
            card.pop();
            card.push(card.front());
            card.pop();
        }
        printf( "\n" );
        printf( "Remaining card: %d\n", card.front() );
        card.pop();
    }
    return 0;
}
