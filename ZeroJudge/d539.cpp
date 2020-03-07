#include<stdlib.h>
#include<stdio.h>
int A[500001], tree[1100001];
int MAX (int x, int y) {
 if(x >= y) return x;
 else return y;
}
void set_tree(int l, int r, int k) {
 if(l == r)  tree[k]=A[l];
 else {
         int m = (l + r)/2;
         set_tree(l, m, 2*k);
         set_tree(m+1, r, 2*k+1);
         tree[k]=MAX(tree[2*k], tree[2*k+1]);
    }
}
int get(int l, int r, int k, int x, int y) {
 if(l == x && r == y)  return tree[k];
 else {
         int m = (l + r)/2;
         if(m >= y) return get(l, m, 2*k, x, y);
         else if(m < x) return get(m+1, r, 2*k+1, x, y);
         else return MAX(get(l, m, 2*k, x, m), get(m+1, r, 2*k+1, m+1, y));
 }
}
int Input() {
 char cha;
 int x=0;
 while( cha = getchar() )
     if(cha!=' ' && cha!='\n') break;
 x= cha-48;
 while(cha=getchar()) {
      if(cha==' ' || cha=='\n') break;
       x=x*10+cha-48;
    }
    return x;
}
main() {

 int N, a, x, y, M, t;

 while(scanf("%d",&N)==1) {
     for(a = 1; a <= N; a++)
         A[a]=Input();
        set_tree(1, N, 1);
        scanf("%d", &M);
        for(a = 1; a <= M; a++) {
            x=Input(), y=Input();
            if(x > y)  t=x, x=y, y=t;
            printf("%d\n",get(1, N, 1, x, y));
        }
    }
 return 0;
}
