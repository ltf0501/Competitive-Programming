#include<bits/stdc++.h>
using namespace std;
int C[131073];/*2^17=131072*/
int Lowbit(int N)
{
    return N&(-N);
}
int Modify(int N,int L)
{
    while(N<=L)
    {
        C[N]++;
        N+=Lowbit(N);
    }
}
int Operator(int N)
{
    int Sum=0;
    while(N)
    {
        Sum+=C[N];
        N-=Lowbit(N);
    }
    return Sum;
}
main()
{
    int N,M,a,B2[20]={1},L;
    for(a=1;a<20;a++)
        B2[a]=B2[a-1]*2;
    while(scanf("%d",&N)==1)
    {
            for(a=0;a<20;a++)
                if(B2[a]>=N)break;
            L=B2[a];
            for(a=1;a<=L;a++)C[a]=0;
            for(a=1;a<=N;a++)
            {
                scanf("%d",&M);
                Modify(M,L);
                printf("%d\n",a-Operator(M-1));
            }
    }
    return 0;
}
