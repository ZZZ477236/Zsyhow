include irvine32.inc
.data
  szInsertSort db "Insert Sort",0
  szBubbleSort db "Bubble Sort",0
  szQuickSort db  "Quick Sort",0
  szHeapSort db "Heap Sort",0
.code
main proc	
again:
	call readint
	cmp eax,1
	jl  final
	cmp eax,4;;<==
	jg  final
	jmp locs[4*eax-4]
next_1:	
	mov edx,offset szInsertSort
	call writestring
	jmp final	
next_2:
	mov edx,offset szBubbleSort
	call writestring
	jmp final
next_3:
	mov edx,offset szQuickSort
	call writestring
	jmp final
next_4:
	mov edx,offset szHeapSort
	call writestring
	jmp final
final:	
	call crlf
	jmp again
	exit
locs dword offset next_1 
	 dword offset next_2 
	 dword offset next_3 
	 dword offset next_4  
main endp
end main
