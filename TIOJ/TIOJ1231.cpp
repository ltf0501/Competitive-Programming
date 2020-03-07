
#include<stdio.h>
#include<algorithm>
#define MAX 100010
int n,ed,weight,cnt;
struct heap{
    int ar[MAX];
    int rear;
    void ch(int a,int b){
        int t=ar[a];
        ar[a]=ar[b];
        ar[b]=t;
    }
    void upset(int n){
        if(n<2||n>=rear)return;
        int t=n>>1;
        if(t>0&&ar[t]<ar[n]){
            ch(t,n);
            upset(t);
        }
    }
    void downset(int n){
        if(n<1||n>=rear)return;
        int t=n<<1,opt;
        if(t<rear&&ar[n]<ar[t]){
            opt=t+1<rear&&ar[t]<ar[t+1];
            ch(t+opt,n);
            downset(t+opt);
        }
        else if(t+1<rear&&ar[n]<ar[t+1]){
            ch(t+1,n);
            downset(t+1);
        }
    }
    void push(int n){
        ar[rear++]=n;
        upset(rear-1);
    }
    int pop(){
        int t=ar[1];
        ch(1,--rear);
        downset(1);

        return t;
    }
}h;
struct seg{
    int cal,t;
    void get(){
        scanf("%d%d",&cal,&t);
    }
    bool operator<(const seg &b)const{
        return t>b.t;
    }
}s[MAX];
int main(){
    scanf("%d",&n);
    cnt=0;h.rear=1;
    for(int i=0;i<n;i++)
        s[i].get();
    scanf("%d",&ed);
    std::sort(s,s+n);
    for(int i=ed;i>0;i--){
        for(;cnt<n&&s[cnt].t>=i;cnt++){
            h.push(s[cnt].cal);
        }
        if(h.rear>1)
            weight+=h.pop();
        else weight--;
    }
    printf("%d\n",weight);
}
