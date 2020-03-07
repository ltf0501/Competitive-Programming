#include <cstdio>
#include <algorithm>
using namespace std;
main()
{
    int Case,N,P[1001],i;
    scanf("%d",&Case);
    while (Case--)
    {
        scanf("%d",&N);
        for (i=0; i<N; i++) scanf("%d",&P[i]);
        sort (P,P+N);

        int sum=0;

        for (i=N-1; i>=3; i-=2){               //三個人以上
            int A = P[1]+P[0]+P[i]+P[1];
            int B = P[i]+P[0]+P[i-1]+P[0];
            if (A<B) sum += A;
            else sum += B;
        }
        if (i == 2) sum += (P[1]+P[0]+P[2]);   //三個人
        else if (i == 1) sum += P[1];          //兩個人
        else if (i == 0) sum += P[0];          //一個人

        printf("%d\n",sum);

        for (i=N-1; i>=3; i-=2){
            int A = P[1]+P[0]+P[i]+P[1];
            int B = P[i]+P[0]+P[i-1]+P[0];
            if (A<B) printf("%d %d\n%d\n%d %d\n%d\n",P[0],P[1],P[0],P[i-1],P[i],P[1]);
            else printf("%d %d\n%d\n%d %d\n%d\n",P[0],P[i-1],P[0],P[0],P[i],P[0]);
        }
        if (i == 2) printf("%d %d\n%d\n%d %d\n",P[0],P[1],P[0],P[0],P[2]);
        else if (i == 1) printf("%d %d\n",P[0],P[1]);
        else if (i == 0) printf("%d\n",P[0]);

        if (Case) printf("\n");
    }
    return 0;
}
