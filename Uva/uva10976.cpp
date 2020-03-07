#include<cstdio>
#include<vector>

using namespace std;

int k;
vector<pair<int, int> > pairs;

int main() {
    while(scanf("%d", &k) == 1) {
        int total = 0;
        pairs.clear();
        for(int i = k + 1; i <= 2 * k; i++) {
            if((i * k) % (i - k) == 0) {
                total++;
                pairs.push_back(make_pair((i * k) / (i - k), i));
            }
        }
        printf("%d\n", total);
        for(int i = 0; i < pairs.size(); i++)
            printf("1/%d = 1/%d + 1/%d\n", k, pairs[i].first, pairs[i].second);
    }
}
