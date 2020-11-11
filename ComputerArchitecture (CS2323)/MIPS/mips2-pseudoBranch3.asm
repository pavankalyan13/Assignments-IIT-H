.data 
	message: .asciiz "hi, how are you ?"
	
.text 
	main:
		addi $s0, $zero, 14
		addi $s1, $zero, 10
		
		# bgt is a pseudo instruction 
		bgt $s0, $s1, displayHi
		
		# bgtz is for branch greater than zero 
		# bgtz $s0, displayHi
		
		
	# end of main 
	li $v0, 10
	syscall
	
	 displayHi:
	 	li $v0, 4
	 	la $a0, message
	 	syscall  