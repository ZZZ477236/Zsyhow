include irvine32.inc
.data
.code
start:
	call readint
	mov  ebx,eax	;;read a
	call readint ;;read b
	mov edx,0
	div ebx		;;edx=r
 again:			;;while(r>0){
	cmp edx,0
	jz  final
	mov eax,ebx	;;a=b;
	mov ebx,edx	;;b=r;
	mov edx,0	;;;!!!
	div ebx		;;r=a%b;
	jmp again;;; }
 final: 
 	mov  eax,ebx
	call writedec
	call crlf
	jmp start
	exit
end start

2.试求两个整数最大公约数
算法 
r=a%b
while(r>0){
	a=b;
	b=r;
	r=a%b;
}
;;b是最大公约数 
 
