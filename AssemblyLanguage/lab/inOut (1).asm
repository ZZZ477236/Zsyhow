;;void buildArray(int *arr,int len)
buildArray proc
    push ebp
    mov  ebp,esp
    pushad
    mov  edx,[ebp+8];;edx=&arr
    mov  ebx,0
again:
    cmp  ebx, [ebp+12];;len
    jge  final
    mov  eax,1000
    call randomRange
    mov [edx+4*ebx],eax
    inc ebx
    jmp again
final:
    popad
    leave
    ret 8
buildArray endp

;;void outputArray(int *arr,int len)
outputArray proc
    push ebp
    mov  ebp,esp
    pushad
    mov edx,[ebp+8]
    mov ebx,0
again:
    cmp  ebx, [ebp+12]
    jge  final
    mov  eax,[edx+4*ebx]
    call writedec
    mov  al,' '
    call writechar
    inc  ebx
    jmp  again
final:
    popad
    leave
    ret 8
outputArray endp