	.file	"log.cpp"
	.text
	.globl	_Z10LogCommandPKc
	.def	_Z10LogCommandPKc;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z10LogCommandPKc
_Z10LogCommandPKc:
.LFB0:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev2, Built by MSYS2 project) 14.2.0"
