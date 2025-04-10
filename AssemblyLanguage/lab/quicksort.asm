include irvine32.inc

n    equ 50;;;equ == #define
Arg1 equ [ebp+8]
Arg2 equ [ebp+12]
Arg3 equ [ebp+16]

include inout.asm

.data
arr dd n dup(?)
.code
main proc
     push n
     push offset arr
     call buildArray

     push n-1
     push 0
     push offset arr
     call quickSort
     
     call crlf
     push n
     push offset arr
     call outputArray
     exit
main endp
;;void quickSort(int a[], int low, int high){
quickSort proc
     push ebp
     mov  ebp,esp
     pushad
     mov  ebx,Arg1;;[ebp+8];;ebx=&a
     mov  ecx,Arg2;;[ebp+12];;ecx=low
     mov  edx,Arg3;;[ebp+16];;edx=high

     cmp ecx,edx;;if(low < high){
     jge final
     push edx
     push ecx
     push ebx
     call partition;;eax=loc,int Loc = partition(a, low, high); //将表一分为二
     push eax;;store loc to stack
     dec  eax;;loc-1
     push eax
     push ecx
     push ebx
     call quickSort;;quickSort(a, low, Loc -1); //递归对低子表递归排序
     pop  eax;;eax=loc
     inc  eax;;eax=loc+1
     push edx
     push eax
     push ebx
     call quickSort;;quickSort(a, Loc + 1, high); //递归对高子表递归排序
     ;;;}
final:   
   popad
   leave
   ret 12
   ;;;}
quickSort endp

;;int partition(int a[], int low, int high){
partition proc
      push ebp
      mov  ebp,esp
      sub  esp,4
      pushad
      mov eax,Arg2;;[ebp+12];;eax=low
      mov ebx,Arg3;;[ebp+16];;ebx=high
      mov ecx,Arg1;;[ebp+8];;ecx=&a
      mov edx,[ecx+4*eax];;edx=key,int Key = a[low]; //基准元素

start_while_1:	;; while(low < high){ //从表的两端交替地向中间扫描
      cmp eax,ebx
      jge end_while_1

start_while_2:		;;while(low < high && a[high] >= Key) --high;
       cmp eax,ebx
       jge end_while_2
       cmp [ecx+4*ebx],edx
       jl  end_while_2
       dec ebx
       jmp start_while_2
end_while_2:
        lea  esi,[ecx+4*ebx]
	push esi
	lea  esi,[ecx+4*eax]
	push esi
	call swap	;;swap(&a[low], &a[high]);
start_while_3:
			;;while(low < high && a[low] <= Key ) ++low;
       cmp eax,ebx
       jge end_while_3
       cmp [ecx+4*eax],edx
       jg  end_while_3
       inc eax
       jmp start_while_3
end_while_3:
       lea  esi,[ecx+4*ebx]
       push esi
       lea  esi,[ecx+4*eax]
       push esi
       call swap		;;swap(&a[low], &a[high]);	
       jmp start_while_1;;}
end_while_1:
	mov [ebp-4],eax;;!!!
	popad
	mov eax,[ebp-4]
	leave
	ret 12		;return low;
			;;}
partition endp

;;void swap(int *a, int *b){
swap proc
	push ebp
	mov  ebp,esp
	pushad
	mov eax,Arg1;;[ebp+8] ;eax=&a
	mov ebx,Arg2;;[ebp+12];ebx=&b
	mov ecx,[eax];ecx=temp;	int tmp = *a;
	mov edx,[ebx];;edx=*b
	mov [eax],edx;;*a = *b;
	mov [ebx],ecx;;*b = tmp;
	popad
	leave
	ret 8  ;}
swap endp
end main

算法代码：

void print(int a[], int n){
	for(int j= 0; j<n; j++){
	    cout<<a[j] <<" ";
	}
	cout<<endl;
}




int main(){
	int a[10] = {3,1,5,7,2,4,9,6,10,8};
	cout<<"初始值：";
	print(a,10);
	quickSort(a,0,9);
	cout<<"结果：";
	print(a,10);
}

72=2^3*3^2
2  3 3 2