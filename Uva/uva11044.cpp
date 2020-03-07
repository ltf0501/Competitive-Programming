#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  const int gridSize = 3;

  int t;
  while( scanf("%d", &t) != EOF ){
    for( int testcase = 1 ; testcase <= t ; ++testcase ){
      int n, m;
      scanf("%d%d", &n, &m);

      printf("%d\n", (n / gridSize) * (m / gridSize));
    }
  }
  return 0;
}
