addi $t0, $zero, 10
addi $t1, $zero, 15
addi $t2, $zero, 14
addi $t3, $zero, 21

main:
	# x = A + B
	add $a0, $t0, $t1  
	add $a1, $t2, $t3
	jal sub
	# v0 contains the result from sub routine 
	add $s1, $zero $v0    
sub:
	sub $v0, $a0, $a1
# ra contains the return address l
	jr $ra 
	
		