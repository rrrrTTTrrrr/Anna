	.file	"RFLAGSgetAndSetTest.cpp"
	.intel_syntax noprefix
	.text
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.globl	_Z3yoov
	.type	_Z3yoov, @function
_Z3yoov:
.LFB1818:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
#APP
# 11 "RFLAGSgetAndSetTest.cpp" 1
	mov R13, 8888888
	
# 0 "" 2
#NO_APP
	nop
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1818:
	.size	_Z3yoov, .-_Z3yoov
	.globl	main
	.type	main, @function
main:
.LFB1819:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	call	_Z3yoov
	mov	QWORD PTR -16[rbp], 0
#APP
# 31 "RFLAGSgetAndSetTest.cpp" 1
	JO dada
	movq rax, 111
	JMP end
	dada:
	movq rax, 222
	end:
	
# 0 "" 2
#NO_APP
	mov	QWORD PTR -16[rbp], rax
	mov	rax, QWORD PTR -16[rbp]
	mov	rsi, rax
	lea	rdi, _ZSt4cout[rip]
	call	_ZNSolsEl@PLT
	mov	rdx, rax
	mov	rax, QWORD PTR _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL[rip]
	mov	rsi, rax
	mov	rdi, rdx
	call	_ZNSolsEPFRSoS_E@PLT
	mov	QWORD PTR -8[rbp], 0
#APP
# 48 "RFLAGSgetAndSetTest.cpp" 1
	LAHF
	pop ax
	bt ax, 1
	JC dadaa
	movq rax, 333
	JMP endr
	dadaa:
	movq rax, 444
	endr:
	
# 0 "" 2
#NO_APP
	mov	QWORD PTR -8[rbp], rax
	mov	rax, QWORD PTR -8[rbp]
	mov	rsi, rax
	lea	rdi, _ZSt4cout[rip]
	call	_ZNSolsEl@PLT
	mov	rdx, rax
	mov	rax, QWORD PTR _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL[rip]
	mov	rsi, rax
	mov	rdi, rdx
	call	_ZNSolsEPFRSoS_E@PLT
	mov	eax, 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1819:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB2326:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	DWORD PTR -4[rbp], edi
	mov	DWORD PTR -8[rbp], esi
	cmp	DWORD PTR -4[rbp], 1
	jne	.L6
	cmp	DWORD PTR -8[rbp], 65535
	jne	.L6
	lea	rdi, _ZStL8__ioinit[rip]
	call	_ZNSt8ios_base4InitC1Ev@PLT
	lea	rdx, __dso_handle[rip]
	lea	rsi, _ZStL8__ioinit[rip]
	mov	rax, QWORD PTR _ZNSt8ios_base4InitD1Ev@GOTPCREL[rip]
	mov	rdi, rax
	call	__cxa_atexit@PLT
.L6:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2326:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__Z3yoov, @function
_GLOBAL__sub_I__Z3yoov:
.LFB2327:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	esi, 65535
	mov	edi, 1
	call	_Z41__static_initialization_and_destruction_0ii
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2327:
	.size	_GLOBAL__sub_I__Z3yoov, .-_GLOBAL__sub_I__Z3yoov
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z3yoov
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 8.2.0-1ubuntu2~18.04) 8.2.0"
	.section	.note.GNU-stack,"",@progbits
