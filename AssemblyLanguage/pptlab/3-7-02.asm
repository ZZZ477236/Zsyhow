include irvine32.inc
.data
day dword 9
;;x1  dword ?
;;x2  dword 1
hint db "the total is: ",0
.code
main proc
	mov eax,1;;x2;;eax=x2
again:						;;    while(day>0)    {
	cmp day,0
	jle  final
	;;add  x2,1
	add eax,1
	;;mov  eax,x2
	mov  ebx,2
	mul  ebx  ;eax=2*(x2+1)
	;;;mov  x1,eax; 		;;   	x1=(x2+1)*2; /*ǰһ����������ǵ�����������1���2��*/
    ;;;mov  x2,eax;		;;    	x2=x1;
    sub day,1			;;    	day--;    /*��Ϊ�Ӻ���ǰ�����������ݼ�*/
 	jmp again	;;}
final:
	
    mov edx,offset hint	;;printf("the total is %d\n",x1);   /* ������ӵ�����*/
    call writestring
    ;;;mov eax,x1
    call writedec

	 exit
main endp
end main 

int main( ) {
    int day, x1, x2;      /*����3 ������day��x1��x2 */
    day=9;
    x2=1;
day dword 9
x1  dword ?
x2  dword 1
hint db "the total is: ",0

again:						;;    while(day>0)    {
	cmp day,0
	jle  final
	add  x2,1
	mov  eax,x2
	mov  ebx,2
	mul  ebx  ;eax=2*(x2+1)
	mov  x1,eax; 		;;   	x1=(x2+1)*2; /*ǰһ����������ǵ�����������1���2��*/
    mov  x2,eax;		;;    	x2=x1;
    sub day,1			;;    	day--;    /*��Ϊ�Ӻ���ǰ�����������ݼ�*/
 	jmp again	;;}
final:
	
    mov edx,offset hint	;;printf("the total is %d\n",x1);   /* ������ӵ�����*/
    call writestring
    mov eax,x1
    call writedec
    				;;return 0;
;;}

