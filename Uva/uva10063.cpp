#include <bits/stdc++.h>
using namespace std;
char str[20], ans[20], len;
void dfs(int idx) {
    if(idx == len) {
        ans[idx] = '\0';
        puts(ans);
        return;
    }
    for(int i = idx; i >= 1; i--)
        ans[i] = ans[i-1];
    for(int i = 0; i <= idx; i++) {
        ans[i] = str[idx];
        dfs(idx+1);
        ans[i] = ans[i+1];
    }
}
int main() {
    int flag = 1;
    while(fgets(str)) {
        if(!flag)
            puts("");
        flag = 0;
        len = strlen(str);
        dfs(0);
    }
    return 0;
}

