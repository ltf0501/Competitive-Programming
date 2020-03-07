#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>arr[1000001];
int main()
{
    int n, m, k, v, i, num;
    while(scanf("%d%d", &n, &m) == 2)
        {
        for(i = 0; i < n; i++){
            scanf("%d", &num);
            arr[num].push_back(i+1);
        }
        while(m--){
            scanf("%d%d", &k, &v);
            if(k > arr[v].size())
                puts("0");
            else
                printf("%d\n", arr[v][k-1]);
        }
        for(i = 0; i <= 1000000; i++)
            arr[i].clear();
    }
    return 0;
}
