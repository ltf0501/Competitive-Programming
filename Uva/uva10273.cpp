#include <stdio.h>
// For the values: 10, 9, 8, 7, 6, 5, 4, 3, 2
// The LCM is: 2520
int main() {
    int testcase;
    int n, i, j, k;
    int T[1005][15], Tn[1005];
    scanf("%d", &testcase);
    while(testcase--) {
        scanf("%d", &n);
        for(i = 0; i < n; i++) {
            scanf("%d", &Tn[i]);
            for(j = 0; j < Tn[i]; j++)
                scanf("%d", &T[i][j]);
        }
        int killed[1005] = {};
        int LCM = 2520, days = 0, lastDay = 0;
        int hasKilled = 1, sum;
        while(hasKilled) {
            hasKilled = 0;
            for(i = 0; i < LCM; i++) {
                days++;
                int mn = 0xfffffff, mncnt = 0, mnidx;
                for(j = 0; j < n; j++) {
                    if(killed[j])    continue;
                    int v = T[j][i%Tn[j]];
                    if(v < mn)
                        mn = v, mncnt = 0, mnidx = j;
                    if(v == mn)
                        mncnt++;
                }
                if(mncnt == 1) {
                    killed[mnidx] = 1;
                    lastDay = days;
                    hasKilled = 1;
                }
            }
        }
        for(i = 0, sum = 0; i < n; i++)
            sum += killed[i] == 0;
        printf("%d %d\n", sum, lastDay);
    }
    return 0;
}
