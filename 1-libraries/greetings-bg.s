	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 3
	.intel_syntax noprefix
	.globl	_getGreetingMessage             ## -- Begin function getGreetingMessage
	.p2align	4, 0x90
_getGreetingMessage:                    ## @getGreetingMessage
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	mov	rax, qword ptr [rip + _helloWorld]
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	_getExitMessage                 ## -- Begin function getExitMessage
	.p2align	4, 0x90
_getExitMessage:                        ## @getExitMessage
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	lea	rax, [rip + L_.str]
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.section	__DATA,__data
	.p2align	3                               ## @helloWorld
_helloWorld:
	.quad	L_.str.1

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.space	1

	.section	__DATA,__data
	.globl	_buffer                         ## @buffer
	.p2align	4
_buffer:
	.asciz	"A\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"

	.section	__TEXT,__cstring,cstring_literals
L_.str.1:                               ## @.str.1
	.asciz	"\320\227\320\264\321\200\320\260\320\262\320\265\320\271 \321\201\320\262\321\217\321\202!"

.subsections_via_symbols
