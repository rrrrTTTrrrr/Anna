	.file	"LockAndMemoryFenceLocationTest.cpp"
	.intel_syntax noprefix
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR -4[rbp], 0
	mov	edx, DWORD PTR -4[rbp]
	mov	eax, DWORD PTR -4[rbp]
#APP
# 8 "LockAndMemoryFenceLocationTest.cpp" 1
	LOCK ADD $0, 8
# 0 "" 2
#NO_APP
	mov	DWORD PTR -4[rbp], eax
	add	DWORD PTR -4[rbp], 1
	mov	eax, 0
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 8.2.0-1ubuntu2~18.04) 8.2.0"
	.section	.note.GNU-stack,"",@progbits
