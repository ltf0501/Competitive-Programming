#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
int N,m = 0;
int a[200002],f[800002] = {0};

void renew(int x,int i){
    if(x>N) return;
    f[x]+=i;
    renew((x&(-x))+x,i) ;//往右上更新
}

void init(){
    memset(f,0,sizeof(f));
    if(m)   printf("\n");
    m++;
    printf("Case %d:\n",m);
}

int ask(int x,int t){
    if(x==0) return t;
    t+=f[x];
    ask(x-(x&(-x)),t) ;//往左下询问
}

int main(){
    char ch;
    int x,y;
    while(scanf("%d",&N)&&N){
        init();//初始化
        for(int i=1;i<=N;i++) scanf("%d",&a[i]);//读入数字
        for(int i=1;i<=N;i++) renew(i,a[i]);//建树

        while(cin>>ch&&ch!='E'){
            if(ch=='S')     {
                scanf("%d %d",&x,&y);
                renew(x,y-a[x]);//更新  往右上加上差值
                a[x] = y;
            }
            if(ch=='M') {
                scanf("%d %d",&x,&y);
                printf("%d\n",ask(y,0)-ask(x-1,0));//输出搜寻结果
            }
        }
        cin>>ch;//读掉N
        cin>>ch;//读掉D
    }
}
