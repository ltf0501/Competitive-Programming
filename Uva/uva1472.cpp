#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;

#define MAXN 200000+10
#define INF 1<<30
int a[MAXN], l[MAXN], r[MAXN], minv[MAXN];

int main (){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        memset(a, 0, sizeof(a));
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        scanf("%d", &n);
        for(int i = 0; i <= n; i++)
            minv[i] = INF;
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++){
            if(a[i] > a[i-1])
                l[i] = l[i-1] + 1;
            else
                l[i] = 1;
        }
        for(int i = n; i >= 1; i--){
            if(a[i] < a[i+1])
                r[i] = r[i+1] + 1;
            else
                r[i] = 1;
        }
        int maxv = 1;
        int cnt = 1;
        for(int i = 1; i <= n; i++){
            int len = lower_bound(minv+1, minv+1+cnt, a[i]) - minv - 1;
            maxv = max(maxv, len + r[i]);
            cnt = max(cnt, l[i]);
            minv[l[i]] = min(minv[l[i]], a[i]);
        }
        printf("%d\n", maxv);
    }
    return 0;
}
