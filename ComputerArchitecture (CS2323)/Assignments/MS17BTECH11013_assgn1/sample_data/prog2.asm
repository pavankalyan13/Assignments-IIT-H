# This program prints 1 is the number is a palindrome else prints 0 on to the screen 
# .text 
# main:
	addi $t0, $zero, 111
	add $t3, $zero, $t0
	li $t2, 0
loop:
	# mul $t2, $t2, 10
	addi $s3, $zero, 10
	mult $t2, $s3
	mflo $t2

	# rem $t1, $t0, 10
	div $t0, $s3
	mfhi $t1

	# div $t0, $t0, 10
	div $t0, $s3
	mflo $t0

	add $t2, $t2, $t1
	bne $t0, $zero, loop
	bne $t3, $t2, not

	# put $v0 as 1 if it is a palindrome
	addi $v0, $zero, 1
	# End of main 
not:
	# li $v0,1
	add $a0, $zero, $zero
	
	# put 0 in the return value 
	add $v0, $a0 
      
	# syscall 
	# End of program
	# li $v0,10
	# syscall 
