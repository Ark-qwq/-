#include<iostream>
using namespace std;
#define Elemtype int


typedef struct { // 待查表

    Elemtype *elem;
    int length; 

}SSTable;

int SeqSearch(SSTable ST ,Elemtype key)
{
    /*for(int i=1; i< ST.length;i++)//顺序查找
    {
        if(ST.elem[i]==key){//与key值比对
            return  i;

        }
        else  return 0;
    }
    /*

    /*
    for (int i = ST.lengh , i>0&&ST.elem[i] = = key ; i--);
    if(i>0) return i;
    else return 0;
    */
   int i;
   ST.elem[0] = key;
   for( i = ST.length; ST.elem[i]!= key ; --i);
   return i;

}

int BinSearch(SSTable ST ,int low ,int high,Elemtype key)// 折半查找
{
    if(low > high ) return 0;
    else {
        int mid = (low +high )/2;
        if( ST.elem[mid] == key ) return mid;
        else if ( ST.elem[mid] > key )
        {
            high  =mid-1;
            BinSearch(ST,low,mid -1,key); //当mid 值大于key 证明 key值在mid左侧 降低high值
        }
        else{
            BinSearch(ST,mid+1,high,key); //当mid 值小于key 证明 key值在mid右侧 提高low值
        }
        


    }
}

typedef struct BiNode
{
    Elemtype data;
    BiNode *lchild,*rchild;
}BiNode , *BiTree;

BiTree BSTSearch(BiTree T, Elemtype key ){//二叉树查找
    if(!T||T->data == key ) return T;
    else if   (T->data < key ) return  BSTSearch(T->lchild,key);//小向左
    else  return BSTSearch (T->rchild,key);//大向右
}
int BSTSearch(BiTree T, Elemtype key, BiTree f, BiTree &p)// 折半查找
{   
    if(!T){p =f ; return 0;}
    if(!T||T->data == key ){ p = T;return 1;}
    else if (T->data < key ) return  BSTSearch(T->lchild,key,f,p);//小向左
    else  return BSTSearch (T->rchild,key,f,p);//大向右
}



    


void BSTInsert(BiTree &T, Elemtype key){
    BiTree p,s;
    if(!BSTSearch(T,key,NULL,p)){
        s = (BiTree)malloc(sizeof(BiNode));
        s->data =key;
        s->lchild = s->rchild=NULL;
        if(!p)T=s;
        else if(p->data >key )p->lchild=s;
        else p->rchild=s;    

    }

}