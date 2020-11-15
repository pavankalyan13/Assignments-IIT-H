.data 
	message: .asciiz "hi, everybody, my Name is Pavan Kalyan.\n"


.text 
	main:		# caller procedure 
		jal displayMessage
		
		addi $s0, $zero, 5
		
		li $v0, 1
		add $a0, $zero, $s0
		syscall 
		
		# it's like return 0 in c language 
		# end of main program 
		li $v0, 10
		syscall 
		 
	displayMessage:       # callee procedure 
		li $v0, 4
		la $a0, message
		syscall 
		
		jr $ra 
	
	# function or procedure 
	
	