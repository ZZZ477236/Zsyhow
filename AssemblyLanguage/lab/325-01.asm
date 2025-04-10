include irvine32.inc
include inout.asm
.data
 arr dd 20 dup(?)
.code

main proc
start:
     call readint
     ;;push 124
     push eax
     push offset arr
     call factorNumber
     
     push eax
     push offset arr
     call showExpr;;2^3*3^2 2^3*3^3
     
     call crlf
     jmp start
     exit
main endp
;;void showExr(int *arr,int n)
showExpr proc;;
	push ebp
	mov  ebp,esp
	pushad
	mov ebx,[ebp+8]
	mov ecx,[ebp+12]
	mov eax,[ebx]
	call writedec
	mov  al,'^'
	call writechar
	mov  eax,[ebx+4]
	call writedec
	mov  esi,1
again:  cmp  esi,ecx
	jge  final
	mov  al,'*'
	call writechar
	mov  eax,[ebx+8*esi]
	call writedec
	mov  al,'^'
	call writechar
	mov eax,[ebx+8*esi+4]
	call writedec
	inc esi
	jmp again
final:	popad
	leave
	ret 8
showExpr endp
;;À„∑® int maxExp(int n, int p)£∫
maxExp proc
      push ebp
      mov  ebp,esp
      sub  esp,4
      pushad
      mov ebx,0;ebx=k=0;
      mov eax,[ebp+8];eax=n
      mov ecx,[ebp+12];ecx=p
start_while:	;;	while(n%p==0) {
      mov edx,0
      div ecx ;;eax=n/p
      cmp edx,0
      jnz end_while
      inc ebx		;;    k=k+1
			;;    n=n/p;
      jmp start_while	;;;}
end_while:
		;;return k ;
       mov [ebp-4],ebx;;!!
       popad
       mov eax,[ebp-4]
       leave
       ret 8
maxExp endp

;;À„∑® int factorNumber(int *array,int n)£∫
factorNumber proc
     push ebp
     mov  ebp,esp
     sub  esp,4
     pushad
     
     push dword ptr[ebp+12]
     call isPrime
     cmp  eax,0
     jz   next;	if isPrime(n) then {
     mov  ebx,[ebp+8];;ebx=&array;save(n,1) to array;
     mov  ecx,[ebp+12]
     mov  [ebx], ecx;;
     mov  dword ptr[ebx+4],1
     mov  eax,1;;return 1;
     jmp  final;;}
next:
      mov ebx,0;;ebx=len=0
      mov ecx,2;;ecx=p=2;
      mov esi,[ebp+12];esi=n
      shr esi,1;;esi=n/2
start_while:	
      cmp ecx,esi;;	while (p<=n/2) {
      jg end_while
      push ecx
      call isPrime 
      cmp  eax,1
      jnz  end_IF  ;If  isPrime(p) then {
      push ecx;;push p
      push dword ptr[ebp+12]
      call maxExp
      cmp eax,0
      jle end_IF	;;  if k=maxExp(n, p) > 0 then {
      mov edx,[ebp+8]
      mov [edx+8*ebx],ecx;
      mov [edx+8*ebx+4],eax;;save(p,k) to array;
      inc ebx	;;		len++;
			;;    }
;;end_IF2:
end_IF:
      inc ecx		;;;p=p+1;
      jmp start_while;;;}
end_while:
       mov eax,ebx;;return len;
final: mov [ebp-4],eax;;!!
       popad
       mov eax,[ebp-4]
       leave
       ret 8
factorNumber endp

;;;À„∑® int isPrime(int  n)£∫
isPrime proc
	push ebp
	mov  ebp,esp
	sub  esp,4
	pushad
        mov eax,[ebp+8];eax=n
	cmp eax,1
	je  L0		;;if n==1 then return 0;
	mov ebx,2;ebx=i
start_for:		;;for(i=2; i*i<=n; i++){
	mov eax,ebx
	mul eax ;eax=i*i
	cmp eax,[ebp+8];
	jg  end_for
	mov eax,[ebp+8]
	mov edx,0
	div ebx
	cmp edx,0	;;if n%i ==0 then return 0;
	jz  L0
	inc ebx;;
	jmp start_for	;;}
end_for:mov eax,1
    	jmp final	;;return 1;
L0:     mov eax,0
	;;jmp final
final:	mov [ebp-4],eax;;;!!!
	popad
	mov eax,[ebp-4]
	leave
	ret  4
isPrime endp

end main

72=2^3*3^2  m n=p1 k1 p2 k2 ... pm km
return 2  2 3 3 2




