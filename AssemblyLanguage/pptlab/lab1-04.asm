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
	sub  esp,84  ;;��ջ������ռ�d 
	pushad
	
	push dword ptr[ebp+8];;n
	lea  edi,[ebp-84];;&d
	push edi
	call splitInt2arr
	
	push eax	;��������Ч���ָ��� 
	push edi    ;�����׵�ַ 
	call arr2Int 
	mov [ebp-4],eax ;;����ֵ�ݴ���ջ 
	
	popad
	mov eax,[ebp-4];;ȡ����ֵ��ջ�Ҵ���eax 
	leave
	ret 4
ReverseInt endp

;;int splitInt2arr(int *arr,int n)
splitInt2arr proc
	push ebp
	mov  ebp,esp
	sub  esp,4  ;;�����ݴ淵��ֵ 
	pushad
	
	mov eax,[ebp+12];;n
	mov edi,[ebp+8];;&d
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
final:
	mov [ebp-4],ecx ;;arr�����õ�Ԫ�ظ����ݴ���ջ 
	
	popad
	mov eax,[ebp-4];;ȡ����ֵ��ջ�Ҵ���eax 
	leave
	ret 8
splitInt2arr endp 

;;int arr2Int(int *arr,int len)
arr2Int proc
	push ebp
	mov  ebp,esp
	sub  esp,4  ;;�����ݴ淵��ֵ 
	pushad
	
	mov ecx,[ebp+8];;&d
	mov eax,0			;int sum=0;
	mov ebx,10;
	mov esi,0			;;esi=j,int j=0
again:					;;while(j<i){
	cmp esi,[ebp+12]
	jge final
	mul ebx				;;sum=sum*10;
	add eax,[ecx+4*esi];;sum =sum+d[j];
	inc esi				;;j++;
	jmp again			;;}
final: 
	mov [ebp-4],eax 	;;sum�ݴ���ջ 

	popad
	mov eax,[ebp-4]	;;ȡ����ֵ��ջ�Ҵ���eax 
	leave
	ret 8
arr2Int endp 
end  main


