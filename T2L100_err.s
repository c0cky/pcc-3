 #    2
 #    3
 #    4
 #    5
 #    6
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
 #    7
 #    8
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
 #    9
 #   10
				# b_global_decl (d, alignment = 8, size = 8)
.globl d
	.align	8
	.type	d, @object
	.size	d, 8
d:
	.zero	8
 #   11
 #   12
				# b_global_decl (c, alignment = 1, size = 1)
.globl c
	.align	1
	.type	c, @object
	.size	c, 1
c:
	.zero	1
 #   13
 #   14
 #   15
 #   16
 #   17
 #   18
 #   19
 #   20
				# b_func_prologue (main)
	.text
.global main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
 #   21
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
				# b_pop ()
	addl	$8, %esp
 #   22
				# b_push_ext_addr (k)
	subl	$8, %esp
	movl	$k, (%esp)
				# b_push_const_int (22)
	movl	$22, %eax
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
				# b_push_ext_addr (x)
	subl	$8, %esp
	movl	$x, (%esp)
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
				# b_arith_rel_op ( / , signed int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	%ecx
	movl	%eax, (%esp)
				# b_assign (float)
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
				# b_push_ext_addr (x)
	subl	$8, %esp
	movl	$x, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (2)
	movl	$2, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( * , double)
	fldl	8(%esp)
	fldl	(%esp)
	addl	$8, %esp
	fmulp	%st, %st(1)
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
				# b_push_ext_addr (c)
	subl	$8, %esp
	movl	$c, (%esp)
				# b_push_ext_addr (i)
	subl	$8, %esp
	movl	$i, (%esp)
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
 #   26
				# b_alloc_arglist (24 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$32, %esp
				# b_push_ext_addr (i)
	subl	$8, %esp
	movl	$i, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_ext_addr (x)
	subl	$8, %esp
	movl	$x, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (float)