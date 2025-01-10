/*本函数的功能是从有N个元素的线性表A中查找第K小的元素。函数的初始调用为Qselect(A, K, 0, N-1)。请完成下列填空。

ElementType Qselect( ElementType A[], int K, int Left, int Right )
{
    ElementType Pivot = A[Left];
    int L = Left, R = Right+1;
      
    while (1) {
        while ( A[++L] < Pivot ) ;
        
while(A[--R] > Pivot)
;
        if ( L < R ) Swap( &A[L], &A[R] );
        else break;
    }
    Swap( &A[Left], &A[R] );
    if ( K < (L-Left) )
        return Qselect(A, K, Left, R-1);
    else if ( K > (L-Left) )
        
return Qselect(A, K-L+Left, R+1, Right);
;
    else
        return Pivot;
}*/