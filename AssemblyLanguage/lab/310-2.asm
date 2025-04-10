include irvine32.inc
.data
  szInsertSort db "Insert Sort",0
  szBubbleSort db "Bubble Sort",0
  szQuickSort db  "Quick Sort",0
  szHeapSort  db  "Heap Sort",0
  
  strs dword offset szInsertSort 
	   dword offset szBubbleSort 
	   dword offset szQuickSort 
	   dword offset szHeapSort  
.code
main proc
again:
	call readint
	cmp eax,1
	jl  final
	cmp eax,4
	jg  final
		
	mov edx,strs[4*eax-4]
	call writestring
final:
	call crlf
	jmp again
	 exit
main endp
end main
