#define less(A,B) (key(A)<key(B)) 
 #define eq(A,B) (!less(A,B) && !(less(B,A)) 
 #define swap(A,B) {Item t=A; A=B; B=t;} 
 #define compswap(A,B) if(less(B,A)) swap(A,B);




/*


//插⼊排序算法
void insertion(Item a[], int left, int right)  
{     int i; 
for (i=left+1; i<=right; i++) 
insert (a, left, i) 
} 
//元素a[i]插⼊数组a[left:i-1] 
void insert(Item a[], int left, int i) 
{    Item v=a[i]; 
while (i>left && less(v,a[i-1])) 
{    a[i]=a[i-1]; 
i--; 
      } 
a[i]=v; 
}



void insertion_sort( T * t, int n ) 
{   int key,  i, j,  low, high, mid; 
for( i=1; i<n; i++ ) 
{     
if( t[i] < t[i-1] ) 
{   low = 0; 
high = i-1; 
key = t[i]; 
while( low <= high ) 
{    mid = (low+high)/2;        
if( key < t[mid] )     high = mid - 1;
else     low = mid + 1;  
              }   
              for( j=i; j>high+1; j-- ) 
t[j] = t[j-1];
t[high+1] = key;
          } 
     } 
}

//简单选择排序 升序


int mini(Item a[], int i, int right) 
{    int j, min=i; 
     for (j=i+1; j<=right; j++) 
          if (less(a[j], a[min])) 
             min=j; 
     return min; 
} 
//选择排序算法 
void selection (Item a[], int left, int right) 
{    int i; 
      for (i=left; i<right; i++) 
      {    int j=mini(a,i,right); 
           swap (a[i], a[j]); 
       } 
}


//冒泡排序

for (i=left+1; i<=right; i++) 
for (j=right; j>i-1; j--) 
compswap(a[j-1], a[j]);



//shell排序


void shellsort(int v[], int n) 
{    int gap, i, j, temp; 
for(gap=n/2;gap>0;gap/=2) //设定步⻓ 
}
 for(i=gap;i<n;++i) //在元素间移动为⽌ 
for(j=i-gap; j>=0&&v[j]>v[j+gap]; j-=gap) 
             {  
                //⽐较相距gap的元素，逆序互换 
temp=v[j]; 
v[j]=v[j+gap];  
v[j+gap]=temp; 
            }


//快速排序
void quickSort (Item a[], int p, int r) 
{    
int q; 
if (r<=p) return; 
q=partition(a,p,r);//快速排序算法的核⼼ 
quickSort(a,p,q-1);//对左半段排序 
quickSort(a,q+1,r);//对右半段排序 
}

int partition (Item a[], int p, int r) 
{    int i=p-1, j=r; 
     Item v=a[r]; 
     //将<=x的元素交换到左边区域 
     //将>=x的元素交换到右边区域 
for (;;) { 
          while (less(a[++i],v)); 
          while (less(v,a[--j]))  ;
             if (j==p) break; 
          if (i>=j) break; 
          swap (a[i],a[j]); 
     } 
     swap(a[i],a[r]); 
     return i; 
}


//随机快速排序
int randompartition 
(Item a[], int p, int r) 
{    
int i=random(p,r); 
swap(a[i],a[r]); 
return partition(a,p,r); 
}
 void randomquicksort  
(Item a[], int p, int r) 
{     
int q; 
if (p<=l) return; 
q=randompartition(a,p,r); 
randomquicksort(a,p,q-1); //对左半段排序 
randomquicksort(a,q+1,r);//对右半段排序 
}


//三数取中排序算法
#define M 10 
void quicksort(Item a[]; int p, int r] 
{ int i; 
int (r-p<=M) insertion(a, p, r); 
swap(a[p+r]/2, a[r-1]); 
compswap(a[p], a[r-1]); 
compswap(a[p], a[r]); 
compswap(a[r-1], a[r]); 
//a[r-1]为基准元素，a[p]为三数中最⼩的元素，a[r]为三数中最⼤的元素 
i=partion(a, p+1, r-1); 
quicksort(a,p,i-1); 
quicksort(a, i+1, r); 
}



//三划分快速排序算法

void quicksort(Item a[], int p, int r) 
{    int i=p-1, j=r, k, m=p-1, n=r; Item v=a[r]; 
if (r<=p) return; 
for (;;){ 
while (less(a[++i],v));//右移 
while (less(v, a[--j])); if (j==p) break;//左移 
if (i>=j) break; 
swap(a[i], a[j]); 
if (eq(a[i],v)) {m++; swap(a[m],a[i]);}//相等的元素交换⾄左右两端 
if (eq(v,a[j])) {n--; swap(a[n],a[i]);} 
}
     } 
swap(a[i],a[r]); 
j=i-1; i=i+1;//以i为界将等于v的元素交换⾄中间 
for (k=p; k<m; k++, j--) swap(a[k],a[j]); 
for (k=r-1; k>n; k--, i++) swap(a[k], a[i]); 
quicksort(a, p, j); 
quicksort(a, i, r);
}


//非递归快速排序算法
#define push2(A,B,s) Push(B,s); Push(A,s); 
void quicksort(Item a[], int p, int r) 
{    int i; 
Stack s=StackInit(); 
push2(p,r,s); 
while (!StackEmpty(s)) 
{    p=Pop(s); 
r=Pop(s); 
if (r<=p) continue; 
i=partition(a,p,r); 
push2(p, i-1, s);  
push2(i+1, r, s); 
}


//合并排序算法


void mergesort(Item a[], int left, int right) 
{    if (left<right) {//⾄少有两个元素 
int m=(left+right)/2;//取中点 
mergesort(a, left, m); 
mergesort(a,m+1,right); 
//将a数组的[left:m]和[m+1,right] 
        //两个各⾃已经有序的部分合并到数组b 
mergeab(a,b,left,m,right );  
copy(a,b,left,right); 
      }  //复制回数组a 
}//备注说明：分解到n=1⼤⼩的⼦集时，⾃然有序

void mergeab(Item a[], Item b[], int left, int m, int right) 
{//合并a[left:m]和a[m+1:right]到b[left:right] 
int i=left, j=m+1, k=left; 
while ((i<=m) && (j<=right)) 
{
if (less(a[i],a[j]))  b[k++]=a[i++];      
else     b[k++]=a[j++];
}
if (i>m)//a[j]…a[right]接到合并数组后半段 
for (i=j; i<=right; i++)   b[k++]=a[i]; 
       else//a[i]…a[m]接到合并数组后半段 
for (; i<=m; i++)     
b[k++]=a[i]; 
}
 

 



//改进
void mergesortAB(Item a[], Item b[], int left, int right) 
{  if (left<right) { 
int m=(left+right)/2; 
// if (right-left<=10){insertion(a,left,right;return;} 
mergesortAB(b,a,left,m);    
mergesortAB(b,a,m+1,right); 
mergeab(b,a,left,m,right); 
   } 
} 

void mergesort(Item a[], int left, int right); 
{ int i; 
for (i=left; i<=right; i++) b[i]=a[i]; 
mergesortAB(a,b,left,right);//数组a是排序结果存放数组 
                                                 //数组b是排序输⼊数组 
} 


自底向上

void mergeSortBottomUp(Item arr[], int n) {
    Item* aux = new Item[n];  // 辅助数组

    // 从小规模的子数组开始，逐渐增大
    for (int size = 1; size < n; size = size * 2) {
        // 逐个合并相邻的子数组
        for (int left = 0; left < n - size; left += size * 2) {
            int mid = std::min(left + size - 1, n - 1);  // 中间点
            int right = std::min(left + size * 2 - 1, n - 1);  // 右边界

            // 合并 arr[left...mid] 和 arr[mid+1...right]
            merge(arr, aux, left, mid, right);
        }
    }
    delete[] aux;  // 释放辅助数组
}

void merge(Item arr[], Item aux[], int left, int mid, int right) {
    // 将数组 arr[left...right] 的内容拷贝到辅助数组 aux 中
    for (int i = left; i <= right; i++) {
        aux[i] = arr[i];
    }

    // 合并过程
    int i = left, j = mid + 1;
    for (int k = left; k <= right; k++) {
        if (i > mid) arr[k] = aux[j++];  // 左半部分已经合并完
        else if (j > right) arr[k] = aux[i++];  // 右半部分已经合并完
        else if (aux[i] <= aux[j]) arr[k] = aux[i++];  // 左部分元素更小
        else arr[k] = aux[j++];  // 右部分元素更小
    }
}








//链表结构

typedef struct node *link; 
typedef struct node  
{Item element; link next;} Node;


link mergesort(link c) 
{ link a,b; 
if (!c->next) return c; 
a=c; 
b=c->next; 
while (b && b->next)  
{a=a->next; b=b->next->next;} 
b=a->next; 
a->next=0; 
return merge(mergesort(c), mergesort(b)); 
}



link merge(link a, link b) 
{  Node head;//空的头结点 
link c=&head; 
while (a &&b) 
if (less(a->element, b->element)) 
{c->next=a; c=a; a=a->next;} 
else {c->next=b; c=b; b=b->next;} 
c->next=(!a)?b:a;//处理剩余链表 
return head->next; 
} 


自底向上
link mergesort(link t) 
{ link u; 
Queue q; 
for (q=QueueInit(); t; t=u) //拆成单个节点⼊队 
{u=t->next; t->next=0; EnterQueue(t,q);} 
t=DeleteQueue(q); 
while(!QueueEmpty(q))//队⾸两两合并后⼊队尾 
{ EnterQueue(t,q); 
t=merge(DeleteQueue(q),DeleteQueue(q)); 
   } 
return t; 
}


//桶排序



 for ( ;first; first=first->next) { 
b=first->item; 
if (bottom[b]) { //桶⾮空 
top[b]->next=first;  
top[b]=first; 
          }//top的作⽤⼀：⽅便元素的装⼊，表尾插⼊ 
else bottom[b]=top[b]=first;  //桶空}

p=0； 
for (b=0; b<=m; b++) 
          if (bottom[b]) {//桶非空 
             if (p) //不是第一个非空桶,p为上一个桶的top 
                p->next=bottom[b]; 
             else//第一个非空桶 
                first=bottom[b]; 
             p=top[b]; 
          } 
//bottom的作用：方便元素连接 
//top的作用二：方便元素连接 
if (p)          p->next=0; 
return first;
}


//计数排序


int c[m+1]; 
for (int i=0; i<=m; i++) 
c[i]=0; 
for (int i=0; i<=n; i++) 
c[a[i]]+=1; 
// c[i]中存放的是a中键值等于i 的元素个数
for (int i=1; i<=m; i++) 
c[i]+= c[i-1]; 
b[]作为输出数组
for (int i = n; i > 0; i--) {
    // 通过c[a[i-1]]确定a[i-1]的位置
    int k = a[i - 1];              // 获取当前元素
    int pos = c[k] - 1;            // 计算该元素的位置，注意位置是从0开始的，所以需要减1
    b[pos] = a[i - 1];             // 将元素放入b中
    c[k] -= 1;                     // 更新该元素的计数，表示该位置已经使用
}



// 基数排序算法

void radixSort(int arr[], int l, int r) 
{
    int maxv = 0, pow = 1;
    int *b = new int[r + 1];
    for (int i = l; i <= r; i++) {
        if (arr[i] > maxv) maxv = arr[i];
    }
    while (maxv / pow > 0) {
        int cnt[RADIX] = {0};
        for (int i = l; i <= r; i++) {
            cnt[arr[i] / pow % RADIX]++;
        }
        for (int i = 1; i < RADIX; i++) {
            cnt[i] += cnt[i - 1];
        }
        //前缀和，-1即为位置
        for (int i = r; i >= l; i--) {
            b[--cnt[arr[i] / pow % RADIX]] = arr[i];
        }
        for (int i = l; i <= r; i++) {
            arr[i] = b[i - l];
        }
        pow *= RADIX;
    }
    delete[] b;
}




//
*/