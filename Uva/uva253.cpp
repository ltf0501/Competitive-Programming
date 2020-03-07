#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  string input;
  string cube[2];
  bool used[3];
  while( getline( cin, input ) ){
    cube[0] = input.substr( 0, 6 );
    cube[1] = input.substr( 6, 6 );

    fill( used, used+3, false );
    for( int i = 0 ; i < 3 ; i++ ){
      for( int j = 0 ; j < 3 ; j++ ){
        if( !used[j] &&
            ((cube[1][j] == cube[0][i] && cube[1][5-j] == cube[0][5-i]) ||
              cube[1][5-j] == cube[0][i] && cube[1][j] == cube[0][5-i]) ){
          used[j] = true;
          break;
        }
      }
    }

    if( used[0] && used[1] && used[2] ) printf( "TRUE\n" );
    else printf( "FALSE\n" );
  }
}
