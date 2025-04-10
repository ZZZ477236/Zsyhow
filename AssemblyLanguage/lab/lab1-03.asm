include irvine32.inc
.data
.code
main proc
again:
    call readint
	push eax
	call reverseInt
	call writedec
	call crlf
	jmp  again
	exit
main endp

;;int ReverseInt(int n)
ReverseInt proc
	push ebp
	mov  ebp,esp
	sub  esp,84  ;;在栈中申请空间d 
	pushad
	mov eax,[ebp+8];;n
	lea edi,[ebp-84];;&d
	mov ecx,0	;;ecx=i
	mov ebx,10
again:					;;while(n>0){
	cmp eax,0
	jz final
	mov edx,0        	;;r=n%10
	div ebx				 ;;n=n/10
	mov [edi+4*ecx],edx; d[i]=r;
	inc ecx			 	;;i++;
	jmp again			;;}
final:	mov eax,0		;int sum=0;
	mov ebx,10;
	mov esi,0			;;esi=j,int j=0
again_1:				;;while(j<i){
	cmp esi,ecx
	jge fina_1
	mul ebx				;;sum=sum*10;
	add eax,[edi+4*esi];;sum =sum+d[j];
	inc esi				;;j++;
	jmp again_1		;;}
fina_1: 
	mov [ebp-4],eax ;;返回值暂存于栈 
	popad
	mov eax,[ebp-4];;取返回值于栈且存于eax 
	leave
	ret 4
ReverseInt endp

end  main


