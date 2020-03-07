#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
void f(int a, int b, int c, int d, int k) {
	if(a <= b) {
		if(k == -1) ans.push_back(1);
		for(int i = 0; i < a; i++) ans.push_back(0), ans.push_back(1);
		for(int i = 0; i < b - a; i++) ans.push_back(2), ans.push_back(1);
		for(int i = 0; i < d; i++) ans.push_back(2), ans.push_back(3);
		if(k == 1) ans.push_back(2);
	}
	else if(c >= d) {
		swap(a, d), swap(b, c);
		if(k == 1) ans.push_back(1);
		for(int i = 0; i < a; i++) ans.push_back(0), ans.push_back(1);
		for(int i = 0; i < b - a; i++) ans.push_back(2), ans.push_back(1);
		for(int i = 0; i < d; i++) ans.push_back(2), ans.push_back(3); 
		if(k == -1) ans.push_back(2);
		for(int i = 0; i < int(ans.size()); i++) ans[i] = 3 - ans[i];
	}
	else ans.push_back(-1);
}
int main() {
	int a[4];
	for(int i = 0; i < 4; i++) scanf("%d", &a[i]);
	int x = a[0] + a[2];
	int y = a[1] + a[3];
	if(abs(x - y) > 1) return puts("NO"), 0;
	if(a[2] == 0 && a[3] == 0) {
		puts("YES");
		if(a[0] > a[1]) {
			for(int i = 0; i < a[1]; i++) printf("0 1 "); puts("0");
		}
		else if(a[1] > a[0]) {
			for(int i = 0; i < a[0]; i++) printf("1 0 "); puts("1");
		}
		else {for(int i = 0; i < a[0]; i++) printf("0 1 "); puts(""); }
		return 0;
	}
	if(a[0] == 0 && a[1] == 0) {
		puts("YES");
		if(a[2] > a[3]) {
			for(int i = 0; i < a[3]; i++) printf("2 3 "); puts("2");
		}
		else if(a[3] > a[2]) {
			for(int i = 0; i < a[2]; i++) printf("3 2 "); puts("3");
		}
		else {for(int i = 0; i < a[2]; i++) printf("2 3 "); puts(""); }
		return 0;

	}
	if(x == y) {
		f(a[0], a[1], a[2], a[3], 0);
	}
	else if(x == y + 1) {
		f(a[0], a[1], a[2] - 1, a[3], 1);
	}
	else {
		f(a[0], a[1] - 1, a[2], a[3], -1);
	}
	if(ans[0] == -1) return puts("NO"), 0;
	puts("YES");
	for(int i : ans) printf("%d ", i); puts("");
	return 0;
}
