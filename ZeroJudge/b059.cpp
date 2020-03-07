#include <iostream>
#include <cstdlib>
#include <string.h>
#include <deque>
#define NUM 101
using namespace std;
int chess[NUM][NUM]; //1表示障礙物，2表示走過，999表示目標
int minstep,targetx,targety,rstep[NUM][NUM];
int gox[8]={1,-1,-3,-3,-1,1,3,3}; //八個方向
int goy[8]={3,3,1,-1,-3,-3,-1,1}; //八個方向
int stopx[8]={0,0,-1,-1,0,0,1,1}; //八個方向  障礙物位置
int stopy[8]={1,1,0,0,-1,-1,0,0}; //八個方向  障礙物位置
typedef struct _point{
  int x;
  int y;
  int step;
}Point;
deque<Point> myq;
// 記錄每個數出現的深度, -1 為沒有出現過
int bound(int x,int y){
  if (((x>=0)&&(x<=99))&&((y>=0)&&(y<=99))) return 1;
  else return 0;
}
int main()
{
    //ifstream fin("pc.in");
    //ofstream fout("pc.out");
    int n,x,y,startx,starty;
    Point myp,nextp;
    while (cin >> n){
        minstep=9999999; //表示未到達目標
        memset(chess,0,sizeof(chess));
        for(int i=0;i<n;i++){
          cin >> x >> y;
          chess[x][y]=1;
        }
        cin >> startx>>starty;
        // 開始尋找
        cin >> targetx >> targety;
        chess[targetx][targety]=999;
        chess[startx][starty]=2;
        myp.x=startx;
        myp.y=starty;
        myp.step=0;
        myq.push_back(myp);   //加入queue中
        while (myq.size()>0){
          nextp=myq.front();  //取出queue的第一個
          myq.pop_front();    //將queue的第一個刪除
          if (((nextp.x>=0)&&(nextp.x<=99))&&((nextp.y>=0)&&(nextp.y<=99))&&(nextp.step < minstep)){
            for(int i=0;i<8;i++){  //八個方向加入queue
              if ((bound(nextp.x+stopx[i],nextp.y+stopy[i]))&&(chess[nextp.x+stopx[i]][nextp.y+stopy[i]] != 1)) { //檢查障礙物
                if (bound(nextp.x+gox[i],nextp.y+goy[i])&& (chess[nextp.x+gox[i]][nextp.y+goy[i]] == 0)) { //沒走過才走
     chess[nextp.x+gox[i]][nextp.y+goy[i]]=2; //設為走過
                    myp.x=nextp.x+gox[i];
                    myp.y=nextp.y+goy[i];
                    myp.step=nextp.step+1;
                    myq.push_back(myp);  //加入queue
                }
     if (bound(nextp.x+gox[i],nextp.y+goy[i])&&(chess[nextp.x+gox[i]][nextp.y+goy[i]]==999)) { //判斷是否到達目標
                  if (minstep > (nextp.step+1)) {
   minstep=nextp.step+1;
   break;
   }
                }
              }
            }
          }
        }
        if (minstep == 9999999) cout << "impossible" <<endl;
        else cout << minstep << endl;
    }
    //system("PAUSE");
    return 0;
}
