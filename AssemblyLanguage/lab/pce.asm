include irvine32.inc
.code

main proc
	mov eax,1000h
	add eax,40000h
	sub eax,2000h
	call Dumpregs
	exit
main Endp
end main
c
c

		c
		c
c

