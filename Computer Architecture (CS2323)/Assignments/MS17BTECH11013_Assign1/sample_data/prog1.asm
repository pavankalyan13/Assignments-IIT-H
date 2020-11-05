#  This program will ouput 1 if the given number is amrstrong number else it will output 0
#.text 
#    main:
        addi $t0, $zero, 371
        add $t1, $zero, $t0
        addi $s0, $zero, 10
        add $t6, $zero, $zero
        while:
            beq $t1, $zero, exit
            # rem $t2, $t1, $s0
            div $t1, $s0
            mfhi $t2
           # mul $t3, $t2, $t2
           mult $t2, $t2
           mflo $t3
           # mul $t3, $t3, $t2
           mult $t2 $t3
           mflo $t3
           add $t6, $t6, $t3
            
            div $t1, $t1, $s0
            j while
        exit:
        beq $t6, $t0, yes 
	# if it is not equal then it is not amrstrong nuber put 0 in  $v0
        addi $v0, $zero, 0
        #End of program
#         li $v0, 10
#        syscall 
    yes:
       # put 1 in the return value which is $v0
       addi $v0, $zero, 1 
       
     
