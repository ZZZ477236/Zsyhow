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

������ϰ 
1.�Ա�д���������޷����������򣬱�������12345���54321
����1�����޷���������λ�������飺 ��12345�ֳ� 1,2,3,4,5
	   ���� ͨ������10����ʵ�� 
����2��������1���������������������54321
int d[20]
int n
����1���㷨 
int i=0
while(n>0){
	r=n%10;
	n=n/10; div
    d[i]=r;
	i++;
}
����2���㷨
;;s2 (((5*10+4)*10+3)*10+2)*10+1
int sum=0;
int j=0; 
while(j<i){
	sum=sum*10;
	sum =sum+d[j];
	j++;
}

1. div m
m: byte  ������ AX,    �̣�al,������ah
m: word  ������ DX,AX, �̣�aX,������DX 
m: dword ������ EDX,EAX,�̣�eaX,������EDX 
2. mul m
m: byte  ������ al,    ����ax
m: word  ������ AX, ����dx aX,DX*2^16+ax 
m: dword������ eAX, ����edx eaX,eDX*2^32+eax 
 
 
