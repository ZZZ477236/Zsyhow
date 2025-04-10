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
	jnz next_2
	mov edx,offset szInsertSort
	call writestring
	jmp final	
next_2:
	cmp eax,2
	jnz next_3
	mov edx,offset szBubbleSort
	call writestring
	jmp final
next_3:
	cmp eax,3
	jnz next_4
	mov edx,offset szQuickSort
	call writestring
	jmp final
next_4:
	cmp eax,4
	jnz final
	mov edx,offset szHeapSort
	call writestring
	;;jmp final
final:	
	call crlf
	jmp again
	 exit
main endp
end main
¼üÅÌÊäÈë1£¬ÆÁÄ»Êä³ö¡°¡±
¼üÅÌÊäÈë2£¬ÆÁÄ»Êä³ö¡°Bubble Sort¡±
¼üÅÌÊäÈë3£¬ÆÁÄ»Êä³ö¡°Quick Sort¡±
¼üÅÌÊäÈë4£¬ÆÁÄ»Êä³ö¡°Heap Sort¡±
 
