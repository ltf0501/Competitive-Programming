#include <stdio.h>



double a0,an1,c[3010];
int Case, N;

double sum_c()
{
    double sum = 0;
    for (int i = 1, j = N; i <= N; i++, j--)
        sum += (c[i] * j);
    return sum;
}
int main()
{
    scanf("%d", &Case);
    while (Case--){
        scanf("%d", &N);
        scanf("%lf %lf", &a0, &an1);
        for (int i = 1; i <= N; i++)
            scanf("%lf",&c[i]);
        printf("%.2f\n", (N * a0 + an1 - 2 * sum_c()) / (N+1));
        if (Case) printf("\n");
    }
    return 0;
}
