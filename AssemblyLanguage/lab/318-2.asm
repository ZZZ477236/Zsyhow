include irvine32.inc
.data
	arr dd 100 dup(?)
.code
include inOut.asm
main proc
     push 10
     push offset arr
     call buildArray
     ;push 10
     ;push offset arr
     ;call outputArray
     ;call crlf
     push 10
     push offset arr
     call slectSort
     push 10
     push offset arr
     call outputArray
     exit
main endp

;;int maxIndex(int*arr, int n){
maxIndex proc
   push ebp
   mov  ebp,esp
   sub  esp,4
   pushad
   mov  edx,[ebp+8]
   mov  eax,0	;;eax=index  int index;
		;;;index=0;
   mov  ebx,0   ;;ebx=i
start_For:	;;for(int i=0; i<n; i++) {
    cmp ebx,[ebp+12]
    jge end_For
    mov ecx,[edx+4*eax]
    cmp ecx,[edx+4*ebx]
    jge next ;;if( arr[index] < arr[i]) {
    mov eax,ebx;;index=i
next:
    inc ebx
    jmp start_For;;; }
end_For:
    mov [ebp-4],eax;;<===!!
    popad
    mov eax,[ebp-4]
    leave
    ret 8
		;;return index;
maxIndex endp;;;}

;;void slectSort(int *arr,int n) {
slectSort proc
   push ebp
   mov  ebp,esp
   pushad
   mov edx,[ebp+8];;edx=&arr
   mov ebx,[ebp+12];ebx=i=n
start_For:;;	for(int i=n;i>1;i--) {
   cmp ebx,1
   jle end_For
   push ebx
   push edx
   call maxIndex;;j=maxIndex(arr, i);
   ;mov  ecx,[edx+4*eax];;int temp=arr[j]
   ;mov  esi,[edx+4*ebx-4]
   ;mov [edx+4*eax],esi;;arr[j]=arr[i-1];
   ;mov [edx+4*ebx-4],ecx;;arr[i-1]=temp;
   push dword ptr[edx+4*eax]
   push dword ptr[edx+4*ebx-4]
   pop  dword ptr[edx+4*eax]
   pop  dword ptr[edx+4*ebx-4]
   sub ebx,1
   jmp start_For;}
end_For:
    popad
    leave
    ret 8
slectSort endp ;}
end main



