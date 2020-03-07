#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int BFS[1005], DFS[1005];
int n;
vector<int> g[1005];
vector<int> sub_dfs[1005];
int root[1005];
int dfs(int nd, int &bidx) {
    /*printf("%d %d:\n", nd, bidx);
    for(int i = 0; i < sub_dfs[nd].size(); i++)
        printf("%d ", sub_dfs[nd][i]);
    puts("");*/
    int i, x;
    for(i = 0; i < sub_dfs[nd].size(); i++) {
        if(sub_dfs[nd][i] == BFS[bidx] && bidx < n) {
            x = BFS[bidx];
            g[nd].push_back(x);
            root[x] = nd;
            bidx++, i++;
            while(bidx < n && i < sub_dfs[nd].size()) {
                if(sub_dfs[nd][i] == BFS[bidx])
                    break;
                sub_dfs[x].push_back(sub_dfs[nd][i]);
                root[sub_dfs[nd][i]] = x;
                i++;
            }
            i--;
        }
    }
    while(bidx < n)
        dfs(root[BFS[bidx]], bidx);
}
void print(int n) {
    int i, j;
    for(i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
        printf("%d:", i);
        for(j = 0; j < g[i].size(); j++)
            printf(" %d", g[i][j]);
        puts("");
    }
}
int main() {
    int i;
    while(scanf("%d", &n) == 1) {
        for(i = 0; i < n; i++)
            scanf("%d", &BFS[i]);
        for(i = 0; i < n; i++)
            scanf("%d", &DFS[i]);
        for(i = 0; i <= n; i++)
            g[i].clear(), sub_dfs[i].clear();
        for(i = 1; i < n; i++)
            sub_dfs[BFS[0]].push_back(DFS[i]);
        int bidx = 1;
        dfs(BFS[0], bidx);
        print(n);
    }
    return 0;
}
