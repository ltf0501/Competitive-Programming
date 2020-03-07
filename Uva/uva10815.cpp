#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;

struct dictionary_type
{
    char word[250];
}dic[100000];

bool cmp(dictionary_type a,dictionary_type b)
{
    return strcmp(a.word,b.word)<0;
}

int main()
{
    char temp[250];
    int i,j,dic_i=0;
    while(scanf("%s",temp)!=EOF){

        for(i=0,j=0;temp[i];i++){
            if(temp[i]>='A' && temp[i]<='Z')
               dic[dic_i].word[j++]=temp[i]-'A'+'a'; //換成小寫
            else if(temp[i]>='a' && temp[i]<='z')
                dic[dic_i].word[j++]=temp[i];
            else if(j) {dic_i++; j=0;}  // apple'is 要被分成兩個字apple跟is
        }
        if(j) dic_i++;  //if(j) 避免words'的情況
    }

    sort(dic,dic+dic_i,cmp);

    for(i=0;i<dic_i;){
        printf("%s",dic[i].word);
        for(j=i+1; j<dic_i ;j++)
            if(strcmp(dic[i].word,dic[j].word)) break;
        i=j;
        printf("\n");
    }

    return 0;
}
/*
Adventures in Disneyland
Two blondes were going to Disneyland when they came to a fork in the
road. The sign read: "Disneyland Left."
So they went home.

a
adventures
blondes
came
disneyland
fork
going
home
in
left
read
road
sign
so
the
they
to
two
went
were
when
*/
