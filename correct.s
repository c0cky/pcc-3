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
				# b_global_decl (pi, alignment = 4, size = 4)
.globl pi
	.align	4
	.type	pi, @object
	.size	pi, 4
pi:
	.zero	4
 #    2
 #    3
				# b_func_prologue (main)
	.text
.global main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
 #    4
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
 #    5
				# b_push_ext_addr (pi)
	subl	$8, %esp
	movl	$pi, (%esp)
				# b_push_ext_addr (i)
	subl	$8, %esp
	movl	$i, (%esp)
				# b_assign (pointer)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #    6
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
				# b_push_ext_addr (pi)
	subl	$8, %esp
	movl	$pi, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
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
 #    7
.LC0:
				# b_func_epilogue (main)
	leave
	ret
	.size	main, .-main
 #    8
