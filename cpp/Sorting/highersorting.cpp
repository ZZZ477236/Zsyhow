#include<bits/stdc++.h>
using namespace std;
#define MAXNUM 100
#define MAXSIZE 1000
int flag=0;
class listsorting
{
    public:
    listsorting();
    ~listsorting();
    void create();
    void copy(listsorting initlist);
    void display();
    int binaryfind(int* data,int from,int to,int find); //折半查找
    void halfinsert() ;              //折半插入排序函数
    int totalnumbers(listsorting initlist);
    void shell(int step) ;  //希尔排序函数
    void quick();    //快速排序入口
    int quicksort(int *Data,int n); //快速排序函数递归实现
    void heap();   //堆排序入口
    void heapadjust(int begin,int end);  //堆排序函数重组堆
    void merge() ;  //归并函数入口
    int mergesort(int Data[],int n);  //归并排序函数具体实现
    private:
    int heapdata[MAXNUM];           //静态数组作为大根堆线性表的存储结构
    int data[MAXNUM];           //静态数组存储结构
    int total;                  //数据量

};

int listsorting:: totalnumbers(listsorting initlist)
{
    return initlist.total;
}

void listsorting ::create()
{cin>>total;
   for(int i=0;i<total;i++)
   {
    cin>>data[i];
   }
   display();
}

//copy

void listsorting::display()
{
    int i;for(i=0;i<total;i++)
    cout<<setw(5)<<setiosflags(ios::left)<<data[i];
    cout<<endl;
}

//折半查找
int listsorting:: binaryfind(int *data,int from,int to,int find)
{
    if(from>to) return from;
    if(find==data[(from+to)/2])
    return (from+to)/2;
    else if(find<data[(from+to)/2])
    return binaryfind(data,from,(from+to)/2-1,find);
    return binaryfind(data,(from+to)/2+1,to,find);
}

//折半插入排序 最坏情况任然是O(N方)
void listsorting::halfinsert()
{
    for(int i=1;i<total;i++)
    {
        int position =binaryfind(data,0,i-1,data[i]);
        int temp=data[i];
        int j;
        for(j=i-1;j>=position;j--)
        {
            data[j+1]=data[j];
        }
        if(j!=i-1)
        {
            data[position]=temp;
        }
    }
    display();
    

}

//希尔排序
void listsorting::shell(int step)
{
    int temp;
    int w;
    whle()
}

int main()
{
    system("chcp 65001");
}