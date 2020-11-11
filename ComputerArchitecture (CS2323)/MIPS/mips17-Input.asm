.data 
	prompt: .asciiz "Enter your age: "
	message: .asciiz "\nYour age is "
	
.text 
	#prompt the user to enter age 
	li $v0, 4
	la $a0, prompt 
	syscall 
	
	# get the user's age 
	li $v0, 5  # entered number is going to be saved in v0
	syscall 
	
	# store the result in $t0
	move $t0, $v0
	
	# Display the result 
	
	li $v0, 4
	la $a0, message 
	syscall 
	
	# print or show the age 
	li $v0, 1
	move $a0, $t0
	syscall 
	
	