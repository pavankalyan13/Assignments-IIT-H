.data 
	message: .asciiz "Hello, "
	
	# string to save user input which is allocated 20 characters
	userInput: .space 20 

.text 
	main: 
		# get ready to read user's string data 
		li $v0, 8
		la $a0, userInput
		li $a1, 20  # sys to tell 20 characters 
		syscall 
		
		# display hello 
		li $v0, 4
		la $a0, message 
		syscall 
	
		li $v0, 4
		la $a0, userInput 
		syscall	
		
	# end of main 	
	li $v0, 10
	syscall 
	