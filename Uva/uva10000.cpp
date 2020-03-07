#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int findLongestPath( bool map[105][105], vector<int> &distance, int s, int n ){
  distance[s] = 0;
  queue<int> next;
  vector<bool> inQueue(n+1, false);
  next.push(s);

  while( !next.empty() ){
    int current = next.front();
    next.pop();
    inQueue[current] = false;

    for( int i = 1 ; i <= n ; ++i ){
      if( map[current][i] && distance[current]+1 > distance[i] ){
        distance[i] = distance[current] + 1;
        if( !inQueue[i] ){
          next.push(i);
          inQueue[i] = true;
        }
      }
    }
  }

  int maxIndex = 1;
  for( int i = 2 ; i <= n ; ++i ){
    if( distance[i] > distance[maxIndex] ){
      maxIndex = i;
    }
  }

  return maxIndex;
}

int main(){
  int n;
  int caseNumber = 0;
  while( scanf("%d", &n) != EOF && n != 0 ){
    int s;
    scanf("%d", &s);

    bool map[105][105] = {false};
    int p, q;
    while( scanf("%d%d", &p, &q) != EOF && p != 0 && q != 0 ){
      map[p][q] = true;
    }

    vector<int> distance(n+1, 0);
    int final = findLongestPath(map, distance, s, n);
    printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++caseNumber, s, distance[final], final);
  }

  return 0;
}
