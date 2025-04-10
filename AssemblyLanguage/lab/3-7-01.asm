include irvine32.inc
.data
	arr dword  50 dup(?)	
.code
main proc
	 mov  edx,offset arr
	 mov  ecx,50 
	 call CreateRandomArray
	 
	 mov  edx,offset arr 
	 mov  ecx,50 
	 call OutputArray
	 
	 mov  edx,offset arr 
	 mov  ecx,50 
	 call maxofArray
	 
	 call crlf
	 call writedec
	 exit
main endp

CreateRandomArray proc
	 mov  ebx,0
again:
	 cmp  ebx,ecx
	 jae  final
	 mov  eax,1000
	 call randomRange
	 mov  [edx+4*ebx],eax
	 add  ebx,1
	 jmp  again
final:
	ret
CreateRandomArray endp

OutputArray proc
	 mov  ebx,0
again:
	 cmp  ebx,ecx
	 jae  final
	 mov  eax,[edx+4*ebx]
	 call writedec
	 call crlf	 	
	 add  ebx,1
	 jmp  again
final:
	ret
OutputArray endp

maxofArray proc
	mov eax,  [edx]	;  eax=max
	mov  ebx, 0		;      ebx=i
again: 
	cmp ebx,ecx
    jae  final
    cmp eax, [edx+4*ebx]
    jge next
    mov eax, [edx+4*ebx]
next:    
	add ebx,1
 	jmp again
final:
	ret
maxofArray endp
end main 

mov     dword ptr [ebx*4+404000], eax
00404000 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00404000 C2 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ?..............
00404000 C2 00 00 00 BE 02 00 00 00 00 00 00 00 00 00 00  ?..?..........




