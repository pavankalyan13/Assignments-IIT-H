.data 
	message: .asciiz "Enter the value of PI: "
	zeroAsFloat: .float 0.0 
.text 
	lwc1 $f4, zeroAsFloat
	
	#display the message 
	li $v0, 4
	la $a0, message
	syscall
	
	# read user's input 
	li $v0, 6   # 6 is for float input 
	syscall 
	
	#display value 
	li $v0, 2
	add.s $f12, $f0, $f4
	syscall 
	
	
	
	