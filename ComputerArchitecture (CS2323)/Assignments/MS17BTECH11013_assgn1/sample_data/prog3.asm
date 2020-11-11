swap:
	addi $s1, $zero, 4
	mult $t0, $s0, $s1
	add $t0, $s1, $t0
	lw $t1, 0($t1)
	lw $t2, 4($t0)
	sw $t2, 0($t0)
	sw $t1, 4($t0)
	jr $ra 
	
	