.data 
	prompt1: .asciiz "Enter n value "
	prompt2: .asciiz "Enter a value "
	prompt3: .asciiz "Enter r value "
	
	msg1: .asciiz "Comparision count for ascending sequence: "
	msg2: .asciiz "Comparision count for descending sequence: "
	msg3: .asciiz "Comparision count for random sequence: "
	
	msg4: .asciiz "Ascending order: "
	msg5: .asciiz "Descending order: "
	msg6: .asciiz "Random order: "
	
	seq1: .space 40
	seq2: .space 40
	
	newLine: .asciiz "\n"
	space: .asciiz " "
	
.text 

	main:
		li $v0,4 
		la $a0, prompt1
		syscall 
		
		li $v0, 5
		syscall 
		add $a1, $v0, $zero 		# a1 = n
		
		li $v0,4 
		la $a0, prompt2
		syscall 
		
		li $v0, 5
		syscall 
		add $a2, $v0, $zero		# a2 = a
		
		li $v0,4 
		la $a0, prompt3
		syscall 
		
		li $v0, 5
		syscall 
		add $a3, $v0, $zero		# a3 = r
		
		add $s7, $zero, $a1  # n value 
		
		jal generateGP
		
		li $v0, 4
		la $a0, newLine
		syscall 
			
		li $v0,4 
		la $a0, msg4	# ascending order print 
		syscall
	
		jal printSeq1	# prints the ascending order of GP
	
		li $v0,4 
		la $a0, msg1
		syscall
		
		jal insertionSort
		
		li $v0, 4
		la $a0, newLine
		syscall 
		
		jal reverseArray
		
		li $v0, 4
		la $a0, newLine
		syscall 
		
		li $v0,4 
		la $a0, msg5	# descending order 
		syscall
		
		jal printSeq2   # prints the descending order of GP
		
		li $v0,4 
		la $a0, msg2
		syscall
		jal insertionSort2
		
		li $v0, 4
		la $a0, newLine
		syscall 
								
		jal randomize
		
		li $v0, 4
		la $a0, newLine
		syscall 
		
		li $v0,4 
		la $a0, msg6	# Randomize order 
		syscall
		
		jal printSeq1

	
		li $v0,4 
		la $a0, msg3
		syscall
		jal insertionSort3
		
	# End of main 
	li $v0, 10
	syscall 
	
	generateGP:
		
		addi $t0, $zero, 0   # i = 0
		sw $a2, seq1($t0)    # first array element is value of a 
		
		move $t3, $a1 
		
		addi $t3, $t3, -1 
		mul $t3, $t3, 4	      # n = (n-1)*4 
		while:
		
			beq $t0, $t3, exit1 
			
			lw $t1, seq1($t0)
			mul $t1, $t1, $a3
			addi $t2, $t0, 4
			sw $t1, seq1($t2)
			
			addi $t0, $t0, 4         
			
			j while
		exit1:
			
	jr $ra 
	
	reverseArray:
		
		addi $t0, $zero, 0	# i = 0 
		move $t2, $a1 
		mul $t2, $t2, 4		# n*4 
		
		loop2:
			beq $t0, $t2, exit2   # i == n break  
			
			# for n-(i+1) 
			# address will 4*n - (4*i + 4 ) 
			# 4i + 4 is stored in t3 
			
			addi $t3, $t0, 4 	# 4i + 4 
			sub $t3, $t2, $t3	# 4n - (4i+4) 
			lw $t1, seq1($t3)	# t1 = arr[n-(i+1)]
			sw $t1, seq2($t0)
			
			addi $t0 $t0, 4
			
			j loop2
		exit2:	

		jr $ra 
			
	randomize:
		
		# generating a random number which uses a1, so save a1 somewhere 
		add $t5, $a1, $zero
		
		addi $t7, $a1, 0  # store the parameter in register $t7
		
		addi $t0, $t7, -1   # i = n - 1 
		sll $t0, $t0, 2     # i * 4 
		addi $t1, $t7, 0    # k = n  used when finding remainder i+1 
		
		loop3:
		  	ble $t0, $zero, exit3	# i <= 0 branch less than or equal pseudo instruction
		  	
			li $a1,100 
			li $v0, 42
			syscall 
			# $a0 has the random number 
			add $t2, $zero, $a0 
			
			div $t2, $t1 
			mfhi $t6
			sll $t6, $t6, 2 
				
			# swap is done here lw and then sw 		
			lw $t3, seq1($t0)
			lw $t4, seq1($t6)
		
			sw $t4, seq1($t0)
			sw $t3, seq1($t6)
		
			addi $t0, $t0, -4 
			addi $t1, $t1, -1 
			
			j loop3
			
		exit3:	
		add $a1, $t5, $zero

		jr $ra 
			
	insertionSort:

		addi $t0, $zero, 4   # i = 1 
		addi $t9, $zero, 1   # Compcount = 1 
		
		add $t8, $a1, $zero   # temp to store n 
		sll $t8, $t8, 2 
		
		loopISt1:
			beq  $t0, $t8, exitISt1   # if i == n then end loop 
			
			lw $t6, seq1($t0)
			
			addi $t1, $t0, -4     # j = i - 1 
			
			loopISt2:
				
				blt $t1, $zero, exitISt2
				
				lw $t2, seq1($t1)    #  a[j] 
				
				blt $t2, $t6, exitISt2 
				
				addi $t7, $t1, 4 
				sw $t2, seq1($t7)  # a[j+1] = a[j] 
				
				addi $t1, $t1, -4
				addi $t9, $t9, 1 
				
				j loopISt2
			exitISt2:
			
			slt $t3, $zero, $t1   # 0 < j 
			slt $t4, $t1, $t8     # j < n 
			
			and $t5, $t3, $t4
			
			bne $t5, $zero, dothis
			
			addi $t7, $t1, 4
			sw $t6 seq1($t7)
			
			addi $t0, $t0, 4 
			j loopISt1
			
			dothis: 
				addi $t9, $t9, 1 
				addi $t7, $t1, 4
				sw $t6 seq1($t7)
				
				addi $t0, $t0, 4 
				j loopISt1		
		exitISt1:
		
		li $v0, 1
		addi $a0, $t9, 0
		syscall 
			
		jr $ra 
		
	insertionSort2:

		addi $t0, $zero, 4   # i = 1 
		addi $t9, $zero, 1   # Compcount = 1 
		
		add $t8, $a1, $zero   # temp to store n 
		sll $t8, $t8, 2 
		
		loop1ISt2:
			beq  $t0, $t8, exit1ISt2   # if i == n then end loop 
			
			lw $t6, seq2($t0)
			
			addi $t1, $t0, -4     # j = i - 1 
			
			loop2ISt2:
				
				blt $t1, $zero, exit2ISt2
				
				lw $t2, seq2($t1)    #  a[j] 
				
				blt $t2, $t6, exit2ISt2 
				
				addi $t7, $t1, 4 
				sw $t2, seq2($t7)  # a[j+1] = a[j] 
				
				addi $t1, $t1, -4
				addi $t9, $t9, 1 
				
				j loop2ISt2
			exit2ISt2:
			
			slt $t3, $zero, $t1   # 0 < j 
			slt $t4, $t1, $t8     # j < n 
			
			and $t5, $t3, $t4
			
			bne $t5, $zero, dothisISt2
			
			addi $t7, $t1, 4
			sw $t6 seq2($t7)
			
			addi $t0, $t0, 4 
			j loop1ISt2
			
			dothisISt2: 
				addi $t9, $t9, 1 
				addi $t7, $t1, 4
				sw $t6 seq2($t7)
				
				addi $t0, $t0, 4 
				j loop1ISt2		
		exit1ISt2:
		
		li $v0, 1
		addi $a0, $t9, 0
		syscall 
			
		jr $ra 

	insertionSort3:

		addi $t0, $zero, 4   # i = 1 
		addi $t9, $zero, 1   # Compcount = 1 
		
		add $t8, $a1, $zero   # temp to store n 
		sll $t8, $t8, 2 
		
		loop1ISt3:
			beq  $t0, $t8, exit1ISt3   # if i == n then end loop 
			
			lw $t6, seq1($t0)
			
			addi $t1, $t0, -4     # j = i - 1 
			
			loop2ISt3:
				
				blt $t1, $zero, exit2ISt3
				
				lw $t2, seq2($t1)    #  a[j] 
				
				blt $t2, $t6, exit2ISt3
				
				addi $t7, $t1, 4 
				sw $t2, seq2($t7)  # a[j+1] = a[j] 
				
				addi $t1, $t1, -4
				addi $t9, $t9, 1 
				
				j loop2ISt3
			exit2ISt3:
			
			slt $t3, $zero, $t1   # 0 < j 
			slt $t4, $t1, $t8     # j < n 
			
			and $t5, $t3, $t4
			
			bne $t5, $zero, dothisISt3
			
			addi $t7, $t1, 4
			sw $t6 seq2($t7)
			
			addi $t0, $t0, 4 
			j loop1ISt3
			
			dothisISt3: 
				addi $t9, $t9, 1 
				addi $t7, $t1, 4
				sw $t6 seq2($t7)
				
				addi $t0, $t0, 4 
				j loop1ISt3		
		exit1ISt3:
		
		li $v0, 1
		addi $a0, $t9, 0
		syscall 
			
		jr $ra 
				
	printSeq1:
		addi $t0, $zero, 0	# i = 0 	
		mul $t1, $a1, 4		# n*4 
		loop:
			beq $t0, $t1, exit	# i == n break
		
			lw $t2, seq1($t0)	# t2 = arr[i]
		
			# print current number 
			li $v0, 1
			move $a0, $t2
			syscall 
		
			# prits the new line 
			li $v0, 4
			la $a0, space
			syscall 
		
			addi $t0, $t0, 4
			j loop
		exit:
		
		li $v0, 4
		la $a0, newLine
		syscall 
	
		jr $ra 
		
	printSeq2:
		addi $t0, $zero, 0	# i = 0 	
		mul $t1, $a1, 4		# n*4 
		loopPrint2:
			beq $t0, $t1, exitPrint2	# i == n break
		
			lw $t2, seq2($t0)	# t2 = arr[i]
		
			# print current number 
			li $v0, 1
			move $a0, $t2
			syscall 
		
			# prits the new line 
			li $v0, 4
			la $a0, space
			syscall 
		
			addi $t0, $t0, 4
			j loopPrint2
		exitPrint2:
		
		li $v0, 4
		la $a0, newLine
		syscall 
	
		jr $ra 