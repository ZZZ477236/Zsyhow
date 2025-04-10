include irvine32.inc
.data
prompt db "Input Your Number: ",0
.code
main proc
     xor  ebx,ebx
     mov  bl,'A'
     push ebx
     xor  ebx,ebx
     mov  bl,'B'
     push ebx
     call Move

start:
     lea edx,prompt
     call writestring
     xor  eax,eax
     mov  al,'C'
     push eax
     mov  al,'B'
     push eax
     mov  al,'A'
     push eax
     ;;push 3
     call readint
     push eax
     call Hanoi
     call crlf
     jmp  start
     exit
main endp
;;void Hanoi(int n, char one,char two,char three){=>
;;void Hanoi(int n, int one,int two,int three){=>	if(n==1) move(one,three)
Hanoi proc
      push ebp
      mov  ebp,esp
      pushad
      
      cmp  dword ptr[ebp+8],1
      jnz  next
      push dword ptr[ebp+20];if(n==1) move(one,three)
      push dword ptr[ebp+12]
      call Move
      jmp  final
next:;;	else{
       push dword ptr[ebp+16]
       push dword ptr[ebp+20]
       push dword ptr[ebp+12]
       mov  eax,[ebp+8]
       dec  eax
       push eax
       call Hanoi	;;Hanoi(n-1,one,three,two);
       push dword ptr[ebp+20];
       push dword ptr[ebp+12]
       call Move	;;Move(one,three);
		
       push dword ptr[ebp+20]
       push dword ptr[ebp+12]
       push dword ptr[ebp+16]
       mov  eax,[ebp+8]
       dec  eax
       push eax
       call Hanoi ;;Hanoi(n-1,two,one,three);
	;;}
final:
       popad
       leave
       ret 16
       ;;}
Hanoi endp

;;void Move(char x,char y){=>
;;void Move(int x,int y){
Move proc
	push ebp
	mov  ebp,esp
	pushad

	mov  eax,[ebp+8]
	call writechar
	lea  edx, arrow
	call writestring
	mov  eax,[ebp+12]
	call writechar;;'x-->y'
	call crlf ;;print("%c-->%c",x,y);
	
	popad
	leave
	ret 8
arrow db '-->',0
;;}
Move endp
end main


void Move(char x,char y){
	print("%c-->%c",x,y);
}

int main(){
	int n;
	printf("Input Your Number");
	scanf("%d",&n);
	Hanoi(n,'A','B','C')
}