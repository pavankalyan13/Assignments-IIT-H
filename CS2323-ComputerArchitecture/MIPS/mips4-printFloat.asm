.data 
	PI: .float 3.14 

.text 
	li $v0, 2  # 2 for printing floats 
# floats go to co processor 
	lwc1 $f12, PI   # always put it in f12 which is co processor 1
	syscall 
	
	