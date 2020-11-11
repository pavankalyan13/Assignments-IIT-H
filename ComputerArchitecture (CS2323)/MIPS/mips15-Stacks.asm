.data 
	newLine: .asciiz "\n"
.text
	main:
		addi $s0, $zero, 10
	
		jal increment
	
	# print a new line 
		li $v0, 4
		la $a0, newLine
		syscall 
		
		li $v0, 1
		move $a0, $s0
		syscall 
	
	# t registers are callee saved 
	# s registers need to be saved. caller saved so callee can't modify 
	
	# This line is the end of main program 
		li $v0, 10
		syscall 

	increment:
	# store 4 bytes in stack and we know stacks grows downward 
		addi $sp, $sp, -4 
		sw $s0, 0($sp)
		
		addi $s0, $s0, 30
		
		#print value in function 
		
		li $v0, 1
		move $a0, $s0
		syscall 
		
		lw $s0, 0($sp)
		addi $sp, $sp, 4
		jr $ra 
		