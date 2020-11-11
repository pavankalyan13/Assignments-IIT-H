.data 
	myArray: .space 12 # 12 bytes for 3 integers 
	newLine: .asciiz "\n"
.text 
	main:
	addi $s0, $zero, 4
	addi $s1, $zero, 10
	addi $s2, $zero, 12 
	
	# index as $t0 
	addi $t0, $zero, 0
	
	# storing values into the array 
	sw $s0, myArray($t0)
	addi $t0, $t0, 4
	sw $s1, myArray($t0)
	addi $t0, $t0, 4 
	sw $s2, myArray($t0)
	
	# clear $t0 to 0
	addi $t0, $zero, 0
	
	while:
		beq $t0, 12, exit 
		
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