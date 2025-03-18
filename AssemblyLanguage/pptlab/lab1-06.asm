include irvine32.inc
.data
.code
main proc
again:
	call readint ;;read b
	push eax
	call readint ;;read a
	push eax
	call gcd
	call writedec
	call crlf
	jmp again
	exit
main endp

;;int gcd(int a,int b)
gcd proc
	push ebp
	mov  ebp,esp
	sub  esp,4  ;;用于暂存返回值  
	pushad
	mov eax,[ebp+8];;a
	mov ebx,[ebp+12];;b 
	mov edx,0    
	div ebx		;;edx=r=a%b
 again:			;;while(r>0){
	cmp edx,0
	jz  final
	mov eax,ebx	;;a=b;
	mov ebx,edx	;;b=r;
	mov edx,0	;;;!!!
	div ebx		;;r=a%b;
	jmp again;;; }
 final: 
	mov [ebp-4],ebx ;;返回值暂存于栈 
	popad
	mov eax,[ebp-4];;取返回值于栈且存于eax 
	leave
	ret 8
gcd endp
end main

