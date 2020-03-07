#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

struct Card{
  char suit;
  char value;
};

int main(){
  stack<Card> pile[60];
  Card input;
  int left1, left3, count1, count3, pilenum;

  while( ( input.value = getchar() ) != EOF && input.value != '#' ){
    for( int i = 0 ; i < 55 ; i++ )
      while( !pile[i].empty() )pile[i].pop();

    input.suit = getchar();
    getchar();
    pile[3].push(input);

    for( int i = 1 ; i < 52 ; i++ ){
      scanf( "%c%c", &input.value, &input.suit );
      getchar();
      pile[i+3].push(input);
    }

    for( int i = 3 ; i < 55 ; i++ ){
      if( pile[i].empty() ) continue;

      left1 = i, left3 = i;
      count1 = 1, count3 = 3;
      while( count3 ){
        if( count1 ) left1--;
        left3--;
        if( left3 < 3 ) break;
        if( !pile[left3].empty() ){
          if( count1 ) count1--;
          count3--;
        }
      }

      if( !pile[left3].empty() &&
          (pile[left3].top().suit == pile[i].top().suit ||
           pile[left3].top().value == pile[i].top().value) ){
        pile[left3].push(pile[i].top());
        pile[i].pop();
        i = left3-1;
        continue;
      }
      else if( !pile[left1].empty() &&
               (pile[left1].top().suit == pile[i].top().suit ||
                pile[left1].top().value == pile[i].top().value) ){
        pile[left1].push(pile[i].top());
        pile[i].pop();
        i = left1-1;
      }

    }

    pilenum = 0;
    for( int i = 3 ; i < 55 ; i++ )
      if( !pile[i].empty() ) pilenum++;

    printf( "%d pile", pilenum );
    if( pilenum > 1 ) printf( "s" );
    printf( " remaining:" );
    for( int i = 3 ; i < 55 ; i++ )
      if( !pile[i].empty() ) printf( " %d", pile[i].size() );
    printf( "\n" );
  }
  return 0;
}
