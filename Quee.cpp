#include <iostream>
#include <stdlib.h>
#define Maxsize 10 

typedef struct 
{
    char datachar;
    int dataint;
}Node;



typedef struct 
 {
    Node* data;
    int front;
    int rare;
}quee;

void initquee(quee& q){
    q.data = (Node*)malloc (Maxsize * sizeof(Node));
    q.front = 0;
    q.rare = 0;

};

void add(quee& q , Node n ){
    if((q.rare+1)%Maxsize==q.front){
        printf("队列已满");//判满
        exit(-1);
    }
    q.data[q.rare] = n;
    q.rare = (q.rare+1)%Maxsize;
}

Node out(quee &q){
    Node  n;
    if(q.rare == q.front)//判空
    {
        printf("空队列");
        exit(-1);
    }
    n = q.data[q.front ];
    q.front = (q.front+1)%Maxsize;

}



int main(){
quee q;
initquee(q);
printf("Done");
return 0;
}