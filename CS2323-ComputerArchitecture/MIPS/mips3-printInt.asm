.data 
	age: .word 23  # word is a 32 bit, it's a basic unit of block 

.text 
	li $v0, 1    # 1 for printing integers 
	lw $a0, age  # use lw for integers as it's a word 
	syscall 
	
# integer is 4 byte = 32 bits (word)