 #    2
 #    3
 #    4
 #    5
				# b_global_decl (i, alignment = 4, size = 4)
.globl i
	.data
	.align	4
	.type	i, @object
	.size	i, 4
i:
	.zero	4
				# b_global_decl (j, alignment = 4, size = 4)
.globl j
	.align	4
	.type	j, @object
	.size	j, 4
j:
	.zero	4
				# b_global_decl (k, alignment = 4, size = 4)
.globl k
	.align	4
	.type	k, @object
	.size	k, 4
k:
	.zero	4
 #    6
 #    7
				# b_global_decl (x, alignment = 4, size = 4)
.globl x
	.align	4
	.type	x, @object
	.size	x, 4
x:
	.zero	4
				# b_global_decl (y, alignment = 4, size = 4)
.globl y
	.align	4
	.type	y, @object
	.size	y, 4
y:
	.zero	4
				# b_global_decl (z, alignment = 4, size = 4)
.globl z
	.align	4
	.type	z, @object
	.size	z, 4
z:
	.zero	4
 #    8
 #    9
				# b_global_decl (d, alignment = 8, size = 8)
.globl d
	.align	8
	.type	d, @object
	.size	d, 8
d:
	.zero	8
 #   10
 #   11
				# b_global_decl (c, alignment = 1, size = 1)
.globl c
	.align	1
	.type	c, @object
	.size	c, 1
c:
	.zero	1
 #   12
 #   13
 #   14
 #   15
 #   16
 #   17
 #   18
 #   19
				# b_func_prologue (main)
	.text
.global main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
 #   20
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (print_globals, void)
	call	print_globals
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #   21
 #   22
				# b_push_ext_addr (i)
	subl	$8, %esp
	movl	$i, (%esp)
				# b_push_const_int (5)
	movl	$5, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   23
				# b_push_ext_addr (j)
	subl	$8, %esp
	movl	$j, (%esp)
				# b_push_ext_addr (i)
	subl	$8, %esp
	movl	$i, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_assign (signed int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   24
				# b_push_ext_addr (d)
	subl	$8, %esp
	movl	$d, (%esp)
				# b_push_const_double (1.9199900000000000e+01)
	.section	.rodata
	.align	8
.LC0:
	.long	-1518700436
	.long	1077097260
	.text
	fldl	.LC0
	subl	$8, %esp
	fstpl	(%esp)
				# b_assign (double)
	fldl	(%esp)
	addl	$8, %esp
	movl	(%esp), %eax
	fstpl	(%eax)
	fstpl	(%esp)
				# b_pop ()
	addl	$8, %esp
 #   25
 #   26
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (print_globals, void)
	call	print_globals
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #   27
 #   28
				# b_push_ext_addr (k)
	subl	$8, %esp
	movl	$k, (%esp)
				# b_push_ext_addr (i)
	subl	$8, %esp
	movl	$i, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_ext_addr (j)
	subl	$8, %esp
	movl	$j, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_arith_rel_op ( + , signed int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	addl	%ecx, %eax
	movl	%eax, (%esp)
				# b_assign (signed int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   29
				# b_push_ext_addr (j)
	subl	$8, %esp
	movl	$j, (%esp)
				# b_push_ext_addr (i)
	subl	$8, %esp
	movl	$i, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_ext_addr (k)
	subl	$8, %esp
	movl	$k, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_ext_addr (k)
	subl	$8, %esp
	movl	$k, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_arith_rel_op ( * , signed int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	imull	%ecx, %eax
	movl	%eax, (%esp)
				# b_push_ext_addr (i)
	subl	$8, %esp
	movl	$i, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_ext_addr (k)
	subl	$8, %esp
	movl	$k, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_arith_rel_op ( + , signed int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	addl	%ecx, %eax
	movl	%eax, (%esp)
				# b_arith_rel_op ( / , signed int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	%ecx
	movl	%eax, (%esp)
				# b_arith_rel_op ( - , signed int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	subl	%ecx, %eax
	movl	%eax, (%esp)
				# b_assign (signed int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   30
				# b_push_ext_addr (i)
	subl	$8, %esp
	movl	$i, (%esp)
				# b_push_ext_addr (k)
	subl	$8, %esp
	movl	$k, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_ext_addr (j)
	subl	$8, %esp
	movl	$j, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_arith_rel_op ( > , signed int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setg	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_assign (signed int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   31
 #   32
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (print_globals, void)
	call	print_globals
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #   33
 #   34
				# b_push_ext_addr (x)
	subl	$8, %esp
	movl	$x, (%esp)
				# b_push_ext_addr (y)
	subl	$8, %esp
	movl	$y, (%esp)
				# b_push_ext_addr (k)
	subl	$8, %esp
	movl	$k, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (signed int -> float)
	fildl	(%esp)
	fstps	(%esp)
				# b_assign (float)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_assign (float)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   35
				# b_push_ext_addr (d)
	subl	$8, %esp
	movl	$d, (%esp)
				# b_push_ext_addr (k)
	subl	$8, %esp
	movl	$k, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (signed int -> double)
	fildl	(%esp)
	fstpl	(%esp)
				# b_assign (double)
	fldl	(%esp)
	addl	$8, %esp
	movl	(%esp), %eax
	fstpl	(%eax)
	fstpl	(%esp)
				# b_pop ()
	addl	$8, %esp
 #   36
				# b_push_ext_addr (c)
	subl	$8, %esp
	movl	$c, (%esp)
				# b_push_ext_addr (k)
	subl	$8, %esp
	movl	$k, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (signed int -> signed char)
				# b_assign (signed char)
	movzbl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movb	%dl, (%eax)
	movb	%dl, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   37
				# b_push_ext_addr (z)
	subl	$8, %esp
	movl	$z, (%esp)
				# b_push_ext_addr (c)
	subl	$8, %esp
	movl	$c, (%esp)
				# b_deref (signed char)
	movl	(%esp), %eax
	movsbl	(%eax), %edx
	movb	%dl, (%esp)
				# b_convert (signed char -> signed int)
	movzbl	(%esp), %eax
	movsbl	%al, %eax
	movl	%eax, (%esp)
				# b_convert (signed int -> double)
	fildl	(%esp)
	fstpl	(%esp)
				# b_push_ext_addr (i)
	subl	$8, %esp
	movl	$i, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (signed int -> double)
	fildl	(%esp)
	fstpl	(%esp)
				# b_arith_rel_op ( * , signed int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	imull	%ecx, %eax
	movl	%eax, (%esp)
				# b_convert (signed int -> double)
	fildl	(%esp)
	fstpl	(%esp)
				# b_push_ext_addr (d)
	subl	$8, %esp
	movl	$d, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_negate (double)
	fldl	(%esp)
	fchs
	fstpl	(%esp)
				# b_convert (signed int -> double)
	fildl	(%esp)
	fstpl	(%esp)
				# b_arith_rel_op ( + , double)
	fldl	8(%esp)
	fldl	(%esp)
	addl	$8, %esp
	faddp	%st, %st(1)
	fstpl	(%esp)
				# b_push_ext_addr (x)
	subl	$8, %esp
	movl	$x, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_arith_rel_op ( - , double)
	fldl	8(%esp)
	fldl	(%esp)
	addl	$8, %esp
	fsubrp	%st, %st(1)
	fstpl	(%esp)
				# b_convert (double -> float)
	fldl	(%esp)
	fstps	(%esp)
				# b_assign (float)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   38
				# b_push_ext_addr (c)
	subl	$8, %esp
	movl	$c, (%esp)
				# b_push_ext_addr (x)
	subl	$8, %esp
	movl	$x, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_push_ext_addr (i)
	subl	$8, %esp
	movl	$i, (%esp)
				# b_push_const_int (19)
	movl	$19, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_convert (signed int -> double)
	fildl	(%esp)
	fstpl	(%esp)
				# b_arith_rel_op ( < , double)
	fldl	8(%esp)
	fldl	(%esp)
	addl	$8, %esp
	fucompp
	fnstsw	%ax
	testb	$69, %ah
	sete	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_convert (signed int -> signed char)
				# b_assign (signed char)
	movzbl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movb	%dl, (%eax)
	movb	%dl, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   39
 #   40
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (print_globals, void)
	call	print_globals
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #   41
 #   42
				# b_push_ext_addr (i)
	subl	$8, %esp
	movl	$i, (%esp)
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (get_int, signed int)
	call	get_int
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   43
				# b_push_ext_addr (d)
	subl	$8, %esp
	movl	$d, (%esp)
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (get_doub, double)
	call	get_doub
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
	subl	$8, %esp
	fstpl	(%esp)
				# b_assign (double)
	fldl	(%esp)
	addl	$8, %esp
	movl	(%esp), %eax
	fstpl	(%eax)
	fstpl	(%esp)
				# b_pop ()
	addl	$8, %esp
 #   44
 #   45
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (print_globals, void)
	call	print_globals
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #   46
 #   47
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (xyz, signed int)
	call	xyz
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
	subl	$8, %esp
	movl	%eax, (%esp)
 #   48
 #   49
				# b_func_epilogue (main)
	leave
	ret
	.size	main, .-main
 #   50
 #   51
 #   52
				# b_func_prologue (w)
.global w
	.type	w, @function
w:
	pushl	%ebp
	movl	%esp, %ebp
 #   53
				# b_func_epilogue (w)
	leave
	ret
	.size	w, .-w
 #   54
 #   55
 #   56
				# b_func_prologue (xyz)
.global xyz
	.type	xyz, @function
xyz:
	pushl	%ebp
	movl	%esp, %ebp
 #   57
				# b_push_ext_addr (i)
	subl	$8, %esp
	movl	$i, (%esp)
				# b_push_const_int (1999)
	movl	$1999, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   58
 #   59
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (print_globals, void)
	call	print_globals
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #   60
				# b_func_epilogue (xyz)
	leave
	ret
	.size	xyz, .-xyz
 #   61
 #   62
 #   63
				# b_func_prologue (abc)
.global abc
	.type	abc, @function
abc:
	pushl	%ebp
	movl	%esp, %ebp
 #   64
				# b_func_epilogue (abc)
	leave
	ret
	.size	abc, .-abc
 #   65
 #   66
 #   67
				# b_func_prologue (fold)
.global fold
	.type	fold, @function
fold:
	pushl	%ebp
	movl	%esp, %ebp
 #   68
				# b_push_ext_addr (i)
	subl	$8, %esp
	movl	$i, (%esp)
				# b_push_const_int (116)
	movl	$116, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   69
				# b_push_ext_addr (d)
	subl	$8, %esp
	movl	$d, (%esp)
				# b_push_const_double (-1.9989999999999998e+01)
	.section	.rodata
	.align	8
.LC1:
	.long	-1546188227
	.long	-1070334608
	.text
	fldl	.LC1
	subl	$8, %esp
	fstpl	(%esp)
				# b_assign (double)
	fldl	(%esp)
	addl	$8, %esp
	movl	(%esp), %eax
	fstpl	(%eax)
	fstpl	(%esp)
				# b_pop ()
	addl	$8, %esp
 #   70
				# b_push_ext_addr (i)
	subl	$8, %esp
	movl	$i, (%esp)
				# b_push_const_double (1.7582400000000002e+03)
	.section	.rodata
	.align	8
.LC2:
	.long	-1030792150
	.long	1083930869
	.text
	fldl	.LC2
	subl	$8, %esp
	fstpl	(%esp)
				# b_convert (double -> signed int)
	fldl	(%esp)
	subl	$8, %esp
	fnstcw	6(%esp)
	movzwl	6(%esp), %eax
	movb	$12, %ah
	movw	%ax, 4(%esp)
	fldcw	4(%esp)
	fistpl	8(%esp)
	fldcw	6(%esp)
	addl	$8, %esp
				# b_assign (signed int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   71
				# b_func_epilogue (fold)
	leave
	ret
	.size	fold, .-fold
 #   72
 #   73
