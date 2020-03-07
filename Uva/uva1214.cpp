#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;

const int MAXN=110;
const int MAXM=20010;
const LL MOD=1e9+7;
const int INF=0x3f3f3f3f;

int N,M;
int power[15];
int dp[2][60000];
int a[12][12];

int bit(int s,int n){
    return s%power[M-n+1]/power[M-n];
}


int main(){
    //freopen("in.txt","r",stdin);
    power[0]=1;
    for(int i=1;i<12;i++) power[i]=power[i-1]*3;
    while(scanf("%d%d",&N,&M)!=EOF&&(N||M)){
        for(int i=1;i<=N;i++)
            for(int j=1;j<=M;j++) scanf("%d",&a[i][j]);
        memset(dp,INF,sizeof(dp));
        int cur=0;
        dp[cur][0]=0;
        for(int i=1;i<=N;i++){
            cur=!cur;
            memset(dp[cur],INF,sizeof(dp[cur]));
            for(int s=0;s<power[M];s++) dp[cur][s]=dp[1-cur][s*3];
            for(int j=1;j<=M;j++){
                cur=!cur;
                memset(dp[cur],INF,sizeof(dp[cur]));
                for(int s=0;s<power[M+1];s++){
                    int p=bit(s,j),q=bit(s,j-1);
                    if(a[i][j]==0){
                        if(p==0&&q==0){
                            dp[cur][s]=min(dp[cur][s],dp[1-cur][s]);
                            dp[cur][s]=min(dp[cur][s],dp[1-cur][s+power[M-j]+power[M-j+1]]);
                            dp[cur][s]=min(dp[cur][s],dp[1-cur][s+2*power[M-j]+2*power[M-j+1]]);
                        }
                        else if(p==1&&q==0){
                            dp[cur][s]=min(dp[cur][s],dp[1-cur][s]+1);
                            dp[cur][s]=min(dp[cur][s],dp[1-cur][s-power[M-j]+power[M-j+1]]+1);
                        }
                        else if(p==0&&q==1){
                            dp[cur][s]=min(dp[cur][s],dp[1-cur][s]+1);
                            dp[cur][s]=min(dp[cur][s],dp[1-cur][s-power[M-j+1]+power[M-j]]+1);
                        }
                        else if(p==2&&q==0){

                            dp[cur][s]=min(dp[cur][s],dp[1-cur][s]+1);
                            dp[cur][s]=min(dp[cur][s],dp[1-cur][s-2*power[M-j]+2*power[M-j+1]]+1);
                        }
                        else if(p==0&&q==2){
                            dp[cur][s]=min(dp[cur][s],dp[1-cur][s]+1);
                            dp[cur][s]=min(dp[cur][s],dp[1-cur][s-2*power[M-j+1]+2*power[M-j]]+1);
                        }
                        else if(p==1&&q==1){
                            dp[cur][s]=min(dp[cur][s],dp[1-cur][s-power[M-j]-power[M-j+1]]+2);
                        }
                        else if(p==2&&q==2){
                            dp[cur][s]=min(dp[cur][s],dp[1-cur][s-2*power[M-j]-2*power[M-j+1]]+2);
                        }
                    }
                    else if(a[i][j]==1){
                        if(p==0&&q==0) dp[cur][s]=min(dp[cur][s],dp[1-cur][s]);
                    }
                    else if(a[i][j]==2){
                        if(p==0&&q==0){
                            dp[cur][s]=min(dp[cur][s],dp[1-cur][s+power[M-j+1]]);
                            dp[cur][s]=min(dp[cur][s],dp[1-cur][s+power[M-j]]);
                        }
                        else if(p==1&&q==0){
                            dp[cur][s]=min(dp[cur][s],dp[1-cur][s-power[M-j]]+1);
                        }
                        else if(p==0&&q==1){
                            dp[cur][s]=min(dp[cur][s],dp[1-cur][s-power[M-j+1]]+1);
                        }

                    }
                    else if(a[i][j]==3){
                        if(p==0&&q==0){
                            dp[cur][s]=min(dp[cur][s],dp[1-cur][s+2*power[M-j+1]]);
                            dp[cur][s]=min(dp[cur][s],dp[1-cur][s+2*power[M-j]]);
                        }
                        else if(p==2&&q==0){
                            dp[cur][s]=min(dp[cur][s],dp[1-cur][s-2*power[M-j]]+1);
                        }
                        else if(p==0&&q==2){
                            dp[cur][s]=min(dp[cur][s],dp[1-cur][s-2*power[M-j+1]]+1);
                        }
                    }
                }
            }
        }
        if(dp[cur][0]!=INF) printf("%d\n",dp[cur][0]);
        else printf("0\n");
    }
    return 0;
}
