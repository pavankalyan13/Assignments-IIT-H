# .text 
#    main:
        addi $a0, $zero, 9
        jal findFactorial

# $v0 contains the value of factorial 
        add $t2, $zero, $v0

#        li $v0, 1
#        add $a0, $zero, $t2
#        syscall 

        #Tell the operating that this is the end of program
#        li $v0, 10
#        syscall  
 
   findFactorial:
	   addi $t7, $zero, 8
        subu $sp, $sp, $t4
        sw $ra, 0($sp)
        sw $s0, 4($sp) 
    
        # Base case 
        li $v0, 1
        beq $a0, $zero, done      
        move $s0, $a0
	   addi $t6, $zero, 1
        sub $a0 ,$a0, $t6
        jal findFactorial 
        mul $v0, $s0, $v0        
        done:
            lw $ra,0($sp)
            lw $s0,4($sp)
            add $sp, $sp, $t7
            jr $ra 
            
        
        
