#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
int a[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  ll ans = 1ll * a[0] * (n - a[0] + 1);
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i - 1]) ans += 1ll * (a[i] - a[i - 1]) * (n - a[i] + 1);
    if (a[i] < a[i - 1]) ans += 1ll * a[i] * (a[i - 1] - a[i]);
  }
  printf("%lld\n", ans);
  return 0;
}
