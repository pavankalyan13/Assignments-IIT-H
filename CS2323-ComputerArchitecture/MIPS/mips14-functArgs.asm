.data 
	message: .asciiz "Hi, Pavan !.\n"
.text 
	main:
	# a1, a2 registers store the function arguments to pass 
		addi $a1, $zero, 50
		addi $a2, $zero, 100
		
		jal addNumbers 
	# v1 contains the return value from addNumbers
	
		li $v0, 1
		add $a0, $zero, $v1
		syscall 
	# return 0 
		li $v0, 10
		syscall 
	
	addNumbers:
		add $v1, $a1, $a2
		
		jr $ra