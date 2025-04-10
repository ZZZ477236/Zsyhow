include irvine32.inc
.data
.code
main proc
   push 5
   call printPerfNumbers
   exit   
main endp

;;int isPerfNumber(int n) {
isPerfNumber proc
	push ebp
	mov  ebp,esp
	sub  esp,4
	pushad
	mov ebx,1;;ebx=sum,int sum=1;
	mov ecx,2;;ecx=factor,int factor=2;
	mov eax,[ebp+8];eax=n
	mov esi,2
	mov edx,0
	div esi;;eax=n/2
	mov esi,eax;esi=n/2
again:		;;while (factor < = n/2) {
	cmp ecx,esi;
	jg final
	mov eax,[ebp+8];;eax=n
	mov edx,0
	div ecx	;;edx=n%factor
	cmp edx,0	;	if ( n% factor ==0 ) {
	jnz next;
	add ebx,ecx;	sum = sum + factor;
	;;}
next:	inc ecx		;;;factor=factor+1;
	jmp again;;}
final:	cmp ebx,[ebp+8];if (sum==n) return 1;
	jnz noperf
	mov dword ptr[ebp-4],1
	jmp final2
noperf:	mov dword ptr[ebp-4],0;<==
final2: 
	popad
	mov eax,[ebp-4]
	leave
	ret 4
		;;return 0;
		;;}
isPerfNumber endp

;;void printPerfNumbers(int k) {
printPerfNumbers proc
   push ebp
   mov  ebp,esp
   pushad
   mov ecx,0;;ecx=count,int count=0;
   mov ebx,6;;ebx=n,int n=6;
again:		;;while (count < k) {
   cmp ecx,[ebp+8]
   jge final
   push ebx;;n
   call isPerfNumber
   cmp  eax,0
   jz   next	;;;if (isPerfNumber(n)) {
   mov  eax,ebx
   call writedec	;;print(n);
   call crlf
   inc  ecx		;;count++;
		;;}
next:
   inc ebx	;;;n++;
   jmp again	;;}
final:
;;;}
   popad
   leave
   ret 4
printPerfNumbers endp
end main



