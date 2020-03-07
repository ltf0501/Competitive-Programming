#include<cstdio>
#include<algorithm>
#include<cmath>
#define maxn 100010
using namespace std;
double L, D;
int n;
struct villages{
    double l, r;
}vill[maxn];

bool cmp(const villages a, const villages b) {
    if(a.r == b.r)
        return a.l < b.l;
    else
        return a.r < b.r;
}

int main() {
    while(scanf("%lf%lf", &L, &D) == 2) {
        scanf("%d", &n);
        double x, y, len;
        for(int i = 0; i < n; i++) {
            scanf("%lf%lf", &x, &y);
            len = sqrt(D * D - y * y);
            vill[i].l = max(x - len,0.0);
            vill[i].r = min(L,x + len);
        }
        sort(vill, vill + n, cmp);
        int ans = 1;
        double r = vill[0].r;
        for(int i = 1; i < n; i++)
            if(r >= vill[i].l && r <= vill[i].r)
                continue;
            else{
                ans++;
                r = vill[i].r;
            }
        printf("%d\n", ans);
    }
    return 0;
}

