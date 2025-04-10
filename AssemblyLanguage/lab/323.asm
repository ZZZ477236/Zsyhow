include irvine32.inc
.data
	Y  db "YES",0
	N  db "No",0
.code
main proc
start:
	 call readint ;;x
	 push eax;;push x
	 call readint
	 push eax;;push k
	 call pd
	 cmp  eax,1
	 je   L1
	 lea  edx,N
	 jmp  next
L1:  lea  edx,Y
next:call writestring
	 call crlf
	 jmp start
	 exit
main endp
 
;;int pd(int k,int x){
pd proc	
	push ebp
	mov  ebp,esp
	sub  esp,4
	pushad
	mov ebx,[ebp+8];ebx=k
	mov ecx,[ebp+12];ecx=x
	
    cmp ebx,ecx		;;if(k>x) return 0;
    jg  L0
    cmp ebx,ecx
    jz  L1			;;;else if(k==x) return 1;
    mov edx,ebx;edx=k
    push ecx
    mov  edx,ebx;edx=k
    shl  edx,1
    inc  edx
    push edx
    call pd   ;; pd(2*k+1,x)
    cmp  eax,1
    jz   final 
	push ecx
	mov edx,ebx
	shl edx,1
	add edx,ebx;edx=3*k
	inc edx
	push edx
	call pd ;;;pd(3*k+1,x)
	jmp  final  	;;return (pd(2*k+1,x)||pd(3*k+1,x));
L0: mov eax,0
 	jmp final
 L1: mov eax,1
final:
    mov [ebp-4],eax;;;!!!
    popad
    mov eax,[ebp-4]
    leave
    ret 8
pd endp		;;;}
end  main

3
0
YES
2
0
No
5
0
No
4
0
YES
