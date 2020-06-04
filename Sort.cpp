#include <iostream>
using namespace std;
#define MaxSize 100
typedef struct {//结构
    int r[MaxSize +1];
    int length;
}SqList;
void sort(SqList &l){//插入排序
    for(int i =2 ; i <= l.length; i++){
        if(l.r[i] <l.r[i-1]){

            l.r[0]=l.r[i];//r[0]位置放置的是等待排序的无序数字
            l.r[i] = l.r[i-1];
            for(int j=i-2; l.r[0]<l.r[j];j--)//将原来有序的数字依次移动
            l.r[j+1] = l.r[j];
            l.r[i-1] = l.r[0];
        }
    }
} 


void BIsort(SqList&l){//折半插入排序

    int low , high ;
    for (int i =2 ; i <= l.length ; i++ ){
        l.r[0] = l.r[i];
        low =1 ;
        high = i-1;
        while(low <= high){
            int m = (low + high)/2; 
            if(l.r[low]<l.r[high]){
                high = m-1;
            }
            else
            {
                low = m+1;
            }
        }
        for(int j=i-1 ; j >=high +1 ; j-- )
        l.r[j+1]=l.r[j];
        l.r[high+1]=l.r[0];


    }

}


class CShellSort{// 希尔插入排序

//public SqList l;
void ShellInsert(SqList&l,int dk){
    int j;
    for(int i=dk+1 ; i <l.length ; i++){
        if(l.r[i]<l.r[i-dk]){
            l.r[0] =l.r[i];
            for(j = i-dk;j>0&&l.r[i]<l.r[j];j-=dk)
            l.r[j+dk] =l.r[j];
            l.r[j+dk] = l.r[0];


        }

    }


}
void ShellSort (SqList &l,int dlta[],int t){
        for(int k =0;k<t;k++)
        ShellInsert(l,dlta[k]);

}

};



void Bubblesort(SqList &l)//冒泡排序
{
    int t;
    for(int i=0;i<l.length-1;i++){//共扫描n-1次 因为第n-1次会比对n项；

        for(int j =0;j<l.length-i-1;j++){//每一趟扫描到a[n-i-2]与a[n-i-1]比较为止结束

            if(l.r[j]>l.r[j+1])//后一位数比前一位数小的话，就交换两个数的位置（升序）
            {
               t=l.r[j+1];
               l.r[j+1]=l.r[j];
               l.r[j]=t;
            }
        }
    }
} 

int Partition(SqList &l, int low,int high){ //快排找寻分界点；
    
    l.r[0] = l.r[low];
    while ( low < high ){
        while(low < high && l.r[0]<=l.r[high]) high--;
        if(low<high)l.r[low++] = l.r[high];
        while(low <high && l.r[0]>=l.r[low]) low++;
        if(low<high)l.r[high--] = l.r[low];
    }
    l. r[low] =l.r[0];  
    return low ;  
}
void QSort(SqList &l, int low,int high){//快速排序
    int piovtloc;
    if(low <high)
    {
    piovtloc = Partition(l,low,high);

    QSort(l,low,piovtloc-1);
    QSort(l,piovtloc+1,high);
    }

   for (int i = 0; i < l.length; i++) {
    printf("%d",l.r[i]);
    }
}


void SelectSort(SqList &l){//简单选择排序
    for(int i=1 ; i<l.length;i++){
        int k=i;
        for(int j= i+1 ; j<l.length;j++)
        if(l.r[j]<l.r[k])
            k =j;
        if (k!=i)
            return;
            //l.r[i]<-->l.r[k];

    }

}



void HeapAdjust(SqList&l,int s, int m ){//调整堆
l.r[0] = l.r[s];
for(int j = 2*s ; j<= m; j*=2){
    if(j<m &&l.r[j]<l.r[j+1]) j++;
    if(l.r[0]>l.r[j])break;
    l.r[s] =l.r[j];
    s=j;
}
l.r[s] = l.r[0];
//HeapAdjust(l,)
}

void HeapSort(SqList &l)//构造堆
{
    for(int i=l.length /2;i>0;i--) //构造堆
        HeapAdjust(l,i,l.length);
    for(int i=l.length;i>1;i--)
    {
        //l.r[1]<-->l.r[i];      输出堆顶端
        HeapAdjust(l,1,i-1);    //调整堆
    }

}

void Merge(int arr[],int low,int mid,int high){
    //low为第1有序区的第1个元素，i指向第1个元素, mid为第1有序区的最后1个元素
    int i=low,j=mid+1,k=0; //mid+1为第2有序区第1个元素，j指向第1个元素
    int *temp=new(nothrow) int[high-low+1]; //temp数组暂存合并的有序序列
    if(!temp){ //内存分配失败
        cout<<"error";
        return;
    }
    while(i<=mid&&j<=high){
        if(arr[i]<=arr[j]) //较小的先存入temp中
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }
    while(i<=mid)//若比较完之后，第一个有序区仍有剩余，则直接复制到t数组中
        temp[k++]=arr[i++];
    while(j<=high)//同上
        temp[k++]=arr[j++];
    for(i=low,k=0;i<=high;i++,k++)//将排好序的存回arr中low到high这区间
		arr[i]=temp[k];
    delete []temp;//删除指针，由于指向的是数组，必须用delete []
}
 
//用递归应用二路归并函数实现排序——分治法
void MergeSort(int arr[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,mid,high);
    }
}
int main(){
    int a[10]={5,1,9,3,7,4,8,6,2,0};
    MergeSort(a,0,9);
    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
    return 0;
}
