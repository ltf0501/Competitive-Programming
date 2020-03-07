#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	if(argc != 2) {
		printf("usage: ./a.out [num]\n");
		exit(1);
	}
	random_device rd;
	mt19937 rng(rd());
	int k = atoi(argv[1]);
	int n = 100;
	printf("%d\n", n);
	double p = 1;
	for(int i = 1; i <= k + 3; i++) p *= 0.8;
	for(int i = 0; i < n * n; i++) {
		for(int j = 0; j < n; j++) {
			double v = uniform_real_distribution<double>(0.0, 1.0)(rng);
			if(v <= p) putchar('1');
			else putchar('0');
		}
		puts("");
	}
	return 0;
}
