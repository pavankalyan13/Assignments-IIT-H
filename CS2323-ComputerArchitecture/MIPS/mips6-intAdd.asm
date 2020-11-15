.data 
	# declare two variables to sum 
	number1: .word 5
	number2: .word 10
.text
	lw $t0, number1($zero)
	lw $t1, number2($zero)
	
	
	add $t2, $t0, $t1  # t2 = t0 + t1
	 
	li $v0, 1  # 1 for integers 
	add $a0, $zero, $t2  # print value in t2 
	syscall 
	