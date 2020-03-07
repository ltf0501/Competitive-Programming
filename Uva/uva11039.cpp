#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)  {return abs(a) < abs(b);}
int num[500000];
int main()
{
    int t, n;
    while(scanf("%d", &t) == 1){
        while(t--){
            scanf("%d", &n);
            for(int i = 0; i < n; i++)
                scanf("%d", &num[i]);
            sort(num, num+n, cmp);
            int judge = 0, Ans = 0, last = 0;
            for(int i = 0; i < n; i++){
                if(judge == 0)
                    last = abs(num[i]), Ans++, judge = num[i]>0?2:1;
                else if(judge == 1 && abs(num[i]) > last && num[i] > 0)
                    last = abs(num[i]), Ans++, judge = 2;
                else if(judge == 2 && abs(num[i]) > last && num[i] < 0)
                    last = abs(num[i]), Ans++, judge = 1;
            }
            printf("%d\n", Ans);
        }
    }
    return 0;
}
