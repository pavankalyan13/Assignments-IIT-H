.data 
	prompt: .asciiz "Enter the value of e: "
.text 
	# display message to the user 
	li $v0, 4
	la $a0, prompt
	syscall 
	
	# get the double from the user 
	li $v0, 7
	syscall 
	
	# display the user's input 
	li $v0, 3
	# double registers have default value 0 so use any register say f10
	add.d $f12, $f0, $f10
	syscall 
	