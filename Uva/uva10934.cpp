#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long int64;
const int INF = 0x3f3f3f3f;

int64 f[110][65];

inline void init() {
memset(f, 0, sizeof(f));
for (int i = 1; i < 64; ++i) {
for (int j = 1; j < 64; ++j) {
f[i][j] = f[i][j-1] + f[i-1][j-1] + 1;
}
}
}
int main(){

init();
int k;
int64 n;

while (~scanf("%d%lld", &k, &n) && k) {

k = min(63, k);
bool ok = false;
for (int i = 0; i <= 63; ++i) {
if (f[k][i] >= n) {
printf("%d\n", i);
ok = true;
break;
}
}
if (!ok) puts("More than 63 trials needed.");
}

return 0;
}
