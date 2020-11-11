.data  
    message: .asciiz "Armstrong Number"
    elsemsg: .asciiz "Not a arm strong"
    newline: .asciiz "\n"
    
.text 
    main:
        addi $t0, $zero, 371
        add $t1, $zero, $t0
        addi $s0, $zero, 10
        add $t6, $zero, $zero
        
        while:
            beq $t1, $zero, exit
            
            # rem $t2, $t1, $s0
            div $t1, $s0
            mfhi $t2
           
            mul $t3, $t2, $t2
            mul $t3, $t3, $t2
            add $t6, $t6, $t3
            
           
            
            div $t1, $t1, $s0
            
            j while
            
        exit:
            
        beq $t6, $t0, printmsg 
        li $v0,4
        la $a0, elsemsg 
        syscall 
        #End of program
        li $v0, 10
        syscall 
        
    printmsg:
       li $v0,4
       la $a0, message 
       syscall 
     