#include <cstdio>

#include <queue>

#define N 201



using namespace std;



struct state{

    int a, b, c, total;

};

struct state s;

int a_vol, b_vol, c_vol, d, ans;

int jugs[N][N], record[N];/*紀錄哪個數字出現的時候，那時的總水量*/



void init(){

    for (int i=0; i<=a_vol; i++) {

        for (int j=0; j<=b_vol; j++)

                jugs[i][j] = -1;

    }

    for (int i=0; i< N; i++) record[i] = -1;

}



struct state build_s(int a, int b, int c, int total){

    struct state tmp;

    tmp.a = a, tmp.b = b, tmp.c = c, tmp.total = total;

    return tmp;

}



void bfs(){

    queue< struct state> q;

    s.a = 0, s.b = 0, s.c = c_vol, s.total = 0;

    q.push(s);

    while (!q.empty()) {

        struct state tmp = q.front();

        q.pop();

        int a = tmp.a, b = tmp.b, c = tmp.c, total = tmp.total;

        if (total >= record[d] && record[d]!=-1) continue;

        if (total >= jugs[a][b] && jugs[a][b]!=-1) continue;

        jugs[a][b] = total;

        record[a] = (record[a]==-1)?total:(record[a]< total)?record[a]:total;

        record[b] = (record[b]==-1)?total:(record[b]< total)?record[b]:total;

        record[c] = (record[c]==-1)?total:(record[c]< total)?record[c]:total;

        /*A->B*/

        if (a < b_vol-b) tmp = build_s(0, b+a, c, total+a);

        else tmp = build_s(a-(b_vol-b), b_vol, c, total+b_vol-b);

        q.push(tmp);

        /*A->C*/

        if (a < c_vol-c) tmp = build_s(0, b, c+a, total+a);

        else tmp = build_s(a-(c_vol-c), b, c_vol, total+(c_vol-c));

        q.push(tmp);

        /*B->A*/

        if (b < a_vol-a) tmp = build_s(a+b, 0, c, total+b);

        else tmp = build_s(a_vol, b-(a_vol-a), c, total+(a_vol-a));

        q.push(tmp);

        /*B->C*/

        if (b < c_vol-c) tmp = build_s(a, 0, c+b, total+b);

        else tmp = build_s(a, b-(c_vol-c), c_vol, total+(c_vol-c));

        q.push(tmp);

        /*C->A*/

        if (c < a_vol-a) tmp = build_s(a+c, b, 0, total+c);

        else tmp = build_s(a_vol, b, c-(a_vol-a), total+(a_vol-a));

        q.push(tmp);

        /*C->B*/

        if (c < b_vol-b) tmp = build_s(a, c+b, 0, total+c);

        else tmp = build_s(a, b_vol, c-(b_vol-b), total+(b_vol-b));

        q.push(tmp);

    }

}



int main() {

    int n;

    scanf("%d", &n);

    while (n--) {

        scanf("%d %d %d %d", &a_vol, &b_vol, &c_vol, &d);

        init();

        bfs();

        int ans=d;

        while (record[ans]==-1) ans--;

        printf("%d %d\n", record[ans], ans);

    }

    return 0;

}
