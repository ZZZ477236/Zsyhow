include irvine32.inc
.data
	d dword 20 dup(?)

.code
main proc
   	call readint ;;n
	mov ecx,0		;;ecx=i=0
	mov ebx,10
again:				;;while(n>0){
	cmp eax,0
	jz final
	mov edx,0			;r=n%10;
	div ebx				;n=n/10; 
	mov d[4*ecx],edx	;d[i]=r;
	inc ecx				;;i++;
	jmp again		;;}
final:
	mov eax,0		;int sum=0;
	mov ebx,10;
	mov esi,0		;;esi=j=0
again_1:			;;while(j<i){
	cmp esi,ecx
	jge fina_1
	mul ebx			;;sum=sum*10;
	add eax,d[4*esi];;sum =sum+d[j];
	inc esi			;;j++;
	jmp again_1		;;}
fina_1: call writedec
     exit
main endp
end  main

课堂练习 
1.试编写汇编程序求无符号整数逆序，比如输入12345输出54321
步骤1·分无符号整数各位数成数组： 如12345分成 1,2,3,4,5
	   可以 通过除以10方法实现 
步骤2·将步骤1所得数组组成逆序数：如54321
int d[20]
int n
步骤1·算法 
int i=0
while(n>0){
	r=n%10;
	n=n/10; div
    d[i]=r;
	i++;
}
步骤2·算法
;;s2 (((5*10+4)*10+3)*10+2)*10+1
int sum=0;
int j=0; 
while(j<i){
	sum=sum*10;
	sum =sum+d[j];
	j++;
}

1. div m
m: byte  被除数 AX,    商：al,余数：ah
m: word  被除数 DX,AX, 商：aX,余数：DX 
m: dword 被除数 EDX,EAX,商：eaX,余数：EDX 
2. mul m
m: byte  被乘数 al,    积：ax
m: word  被乘数 AX, 积：dx aX,DX*2^16+ax 
m: dword被乘数 eAX, 积：edx eaX,eDX*2^32+eax 
 
 
