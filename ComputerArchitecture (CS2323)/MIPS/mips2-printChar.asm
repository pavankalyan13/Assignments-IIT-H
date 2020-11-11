.data 
	myCharacter: .byte 'm'  # char takes one byte 
.text 
	li $v0, 4
	la $a0, myCharacter 
	syscall 