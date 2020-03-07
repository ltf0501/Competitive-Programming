//最小生成樹的題目(Runtime error)
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct point{
    double x;
    double y;
}P[105];
struct edge {
    int i_a;
    int i_b;
    double L;
}E[105*105];

int Set[105];
double Ans;

bool cmp (edge A, edge B);
void Set_Initial(int N);
int Find_Root(int x);
bool Union(edge A);

int main()
{
    int Case, N;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i)
            scanf("%lf%lf", &P[i].x, &P[i].y);

        int nOfE = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                double Len = sqrt(pow(P[i].x - P[j].x, 2) + pow(P[i].y - P[j].y, 2));
                E[nOfE++] = {i,j,Len};
            }
        }

        sort (E, E + nOfE, cmp);
        Set_Initial(N);

        for (int i = 0, sum = 0; sum != N - 1; ++i) {
            if (Union(E[i])) sum++;
        }

        printf("%.2f\n", Ans);
        if (Case) putchar('\n');
    }
}
bool cmp (edge A, edge B)
{
    return A.L < B.L;
}
void Set_Initial(int N)
{
    Ans = 0;
    for (int i = 0; i < N; ++i){
        Set[i] = i;
    }
}
int Find_Root(int x)
{
    if (x == Set[x])
        return x;
    return Set[x] = Find_Root(Set[x]);
}
bool Union(edge A)
{
    int x = Find_Root(A.i_a);
    int y = Find_Root(A.i_b);
    if (x != y) {
        Set[x] = y;
        Ans += A.L;
        return true;
    }
    return false;
}
