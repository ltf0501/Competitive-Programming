#include <iostream>
#include <cstdlib>
#include <string.h>
#include <deque>
#define NUM 101
using namespace std;
int chess[NUM][NUM]; //1��ܻ�ê���A2��ܨ��L�A999��ܥؼ�
int minstep,targetx,targety,rstep[NUM][NUM];
int gox[8]={1,-1,-3,-3,-1,1,3,3}; //�K�Ӥ�V
int goy[8]={3,3,1,-1,-3,-3,-1,1}; //�K�Ӥ�V
int stopx[8]={0,0,-1,-1,0,0,1,1}; //�K�Ӥ�V  ��ê����m
int stopy[8]={1,1,0,0,-1,-1,0,0}; //�K�Ӥ�V  ��ê����m
typedef struct _point{
  int x;
  int y;
  int step;
}Point;
deque<Point> myq;
// �O���C�ӼƥX�{���`��, -1 ���S���X�{�L
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
        minstep=9999999; //��ܥ���F�ؼ�
        memset(chess,0,sizeof(chess));
        for(int i=0;i<n;i++){
          cin >> x >> y;
          chess[x][y]=1;
        }
        cin >> startx>>starty;
        // �}�l�M��
        cin >> targetx >> targety;
        chess[targetx][targety]=999;
        chess[startx][starty]=2;
        myp.x=startx;
        myp.y=starty;
        myp.step=0;
        myq.push_back(myp);   //�[�Jqueue��
        while (myq.size()>0){
          nextp=myq.front();  //���Xqueue���Ĥ@��
          myq.pop_front();    //�Nqueue���Ĥ@�ӧR��
          if (((nextp.x>=0)&&(nextp.x<=99))&&((nextp.y>=0)&&(nextp.y<=99))&&(nextp.step < minstep)){
            for(int i=0;i<8;i++){  //�K�Ӥ�V�[�Jqueue
              if ((bound(nextp.x+stopx[i],nextp.y+stopy[i]))&&(chess[nextp.x+stopx[i]][nextp.y+stopy[i]] != 1)) { //�ˬd��ê��
                if (bound(nextp.x+gox[i],nextp.y+goy[i])&& (chess[nextp.x+gox[i]][nextp.y+goy[i]] == 0)) { //�S���L�~��
     chess[nextp.x+gox[i]][nextp.y+goy[i]]=2; //�]�����L
                    myp.x=nextp.x+gox[i];
                    myp.y=nextp.y+goy[i];
                    myp.step=nextp.step+1;
                    myq.push_back(myp);  //�[�Jqueue
                }
     if (bound(nextp.x+gox[i],nextp.y+goy[i])&&(chess[nextp.x+gox[i]][nextp.y+goy[i]]==999)) { //�P�_�O�_��F�ؼ�
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
