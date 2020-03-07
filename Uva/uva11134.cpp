#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 5e3 + 3;

int n;

struct Rook{
    int id, l, r;
    bool operator < (const Rook &oth) const{
        return r > oth.r;
    } // pq pops least r
} rook[2][MAXN];

bool cmp_l(const Rook &a, const Rook &b){
    return a.l < b.l;
}

int ans[2][MAXN];

void solve(){
    bool fail = false;
    for(int k = 0; k < 2; ++k){
        sort( rook[ k ], rook[ k ] + n, cmp_l );
        priority_queue<Rook> pq;
        int cnt = 0;
        for(int i = 1; i <= n; ++i){
            while( cnt < n && rook[ k ][ cnt ].l <= i )
                pq.push( rook[ k ][ cnt++ ] );
            if( pq.empty() ) continue; // !!
            Rook c = pq.top(); pq.pop();
            if( c.r < i ){ fail = true; break; }
            ans[ k ][ c.id ] = i;
        }
        if( fail || cnt < n || !pq.empty() ){
            puts("IMPOSSIBLE");
            return;
        }
    }
    for(int i = 0; i < n; ++i)
        printf("%d %d\n", ans[0][i], ans[1][i]);
}

int main(){
    while( scanf("%d", &n) == 1 && n ){
        for(int i = 0; i < n; ++i){
            scanf("%d%d%d%d", &rook[0][i].l, &rook[1][i].l, &rook[0][i].r, &rook[1][i].r);
            rook[0][i].id = rook[1][i].id = i;
        }
        solve();
    }
    return 0;
}
