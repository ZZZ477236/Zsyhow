include irvine32.inc
.data
day dword 9

hint db "the total is: ",0
.code
main proc
	mov eax,1
again:						;;    while(day>0)    {
	cmp  day,0
	jle  final
	add  eax,1
	mov  ebx,2
	mul  ebx  ;eax=2*(x2+1)
    sub  day,1			;;    	day--;    /*因为从后向前推所以天数递减*/
 	jmp  again	;;}
final:
    mov edx,offset hint	;;printf("the total is %d\n",x1);   /* 输出桃子的总数*/
    call writestring
    ;;;mov eax,x1
    call writedec
	exit
main endp
end main 

