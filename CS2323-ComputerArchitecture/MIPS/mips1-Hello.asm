.data 
	myMessage: .asciiz "Hello World\n"

.text
	li $v0, 4  # for printing always use 4 
	la $a0, myMessage  # load the address of message into a0 register
	syscall  # do it 
	
