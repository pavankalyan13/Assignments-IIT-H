.data 
	message: .asciiz "The numbers are equal."
	message2: .asciiz "Nothing happened"

.text 
	main:
		addi $t0, $zero, 20
		addi $t1, $zero, 20
		
		beq $t0, $t1, numbersEqual
		
		# syscall to end procedure 
		li $v0, 10
		syscall 
		
	numbersEqual:
		li $v0, 4
		la $a0, message
		syscall 
		
		