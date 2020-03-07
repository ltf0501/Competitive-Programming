#include <string.h>
#include <cstdio>

int d, lefts[90], rights[90], cases = 1;
bool first;
char ch;

void show(int x){
    if(!x) return;
    if(!first) printf(" ");
    else first = false;
    printf("%d", x);
}

bool solve(int x){
    scanf("%d%c", &d, &ch);
    if(d == -1) return false;
    if(x < 0) lefts[-x] += d;
    else rights[x] += d;
    solve(x-1);
    solve(x+1);
    return true;
}

int main(){
    while(true){
        memset(lefts,0,sizeof(lefts));
        memset(rights,0,sizeof(rights));
        first = true;
        if(!solve(0)) break;
        printf("Case %d:\n", cases++);
        for(int i = 80; i > 0; i--) show(lefts[i]);
        for(int i = 0; i <= 80; i++) show(rights[i]);
        printf("\n\n");
    }
	return 0;
}
