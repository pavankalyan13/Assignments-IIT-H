.data 
	myDouble: .double 7.202
	zeroDouble: .double 0.0 
	
	# double is 64 bits means 2 registers to hold 
.text 
	# load double from RAM to co processor 1 
	# as it takes 2 registers always use even registers 0, 2, 4..
	ldc1 $f2, myDouble
	ldc1 $f0, zeroDouble
	
	li $v0, 3  # 3 for printing double 
	add.d $f12, $f2, $f0
	syscall 
	