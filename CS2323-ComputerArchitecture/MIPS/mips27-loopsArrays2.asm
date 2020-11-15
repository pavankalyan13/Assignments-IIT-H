.data 
	myArray: .word 5:10  # 3 elements will be initialized with 100 
	newLine: .asciiz "\n"
.text 
	main:
	
	# clear $t0 to 0
	addi $t0, $zero, 0
	
	while:
		beq $t0, 40, exit   # 10 * 4 
		
		lw $t6, myArray($t0)
		
		addi $t0, $t0, 4
		
		# print current number 
		li $v0, 1
		addi $a0, $t6, 0
		syscall 
		
		# prits the new line 
		li $v0, 4
		la $a0, newLine
		syscall 
		
		j while
	
	exit:
		# tell system this is end of program
	li $v0, 10
	syscall 