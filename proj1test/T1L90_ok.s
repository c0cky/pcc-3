 #    2
 #    3
 #    4
 #    5
				# b_global_decl (a, alignment = 4, size = 4)
.globl a
	.data
	.align	4
	.type	a, @object
	.size	a, 4
a:
	.zero	4
 #    6
				# b_global_decl (b, alignment = 4, size = 4)
.globl b
	.align	4
	.type	b, @object
	.size	b, 4
b:
	.zero	4
 #    7
				# b_global_decl (c, alignment = 8, size = 8)
.globl c
	.align	8
	.type	c, @object
	.size	c, 8
c:
	.zero	8
 #    8
				# b_global_decl (d, alignment = 2, size = 2)
.globl d
	.align	2
	.type	d, @object
	.size	d, 2
d:
	.zero	2
 #    9
 #   10
 #   11
 #   12
 #   13
 #   14
 #   15
 #   16
 #   17
 #   18
				# b_global_decl (k, alignment = 4, size = 4)
.globl k
	.align	4
	.type	k, @object
	.size	k, 4
k:
	.zero	4
 #   19
				# b_global_decl (l, alignment = 4, size = 40)
.globl l
	.align	4
	.type	l, @object
	.size	l, 40
l:
	.zero	40
 #   20
 #   21
