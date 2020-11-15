.data 

.text 
	addi $t0, $zero, 2000
	addi $t1, $zero, 10
	
	mult $t0, $t1 # product will be stored in hi / lo registers because product is larger ( 64 bits)
	
	mflo $s0
	
	# diaply the product to the screen
	li $v0, 1
	add $a0, $zero, $s0
	syscall 
	
	
	
	