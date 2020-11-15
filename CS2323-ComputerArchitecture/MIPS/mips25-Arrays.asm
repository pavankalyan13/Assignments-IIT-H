.data 
	myArray: .space 12 # 12 bytes for 3 integers 

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
	sw $s0, myArray($t0)
	addi $t0, $t0, 4 
	sw $s2, myArray($t0)
	
	# retrieve values from the array 
	lw $t6, myArray($zero)
	
	li $v0, 1
	addi $a0, $t6, 0
	syscall 
	
	
	li $v0, 10
	syscall 