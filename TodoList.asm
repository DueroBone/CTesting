
TodoList:	file format mach-o 64-bit x86-64

Disassembly of section __TEXT,__text:

0000000100000560 <_getLastTask>:
100000560: 55                          	pushq	%rbp
100000561: 48 89 e5                    	movq	%rsp, %rbp
100000564: 48 8b 05 95 1a 00 00        	movq	0x1a95(%rip), %rax      ## 0x100002000 <_firstTask>
10000056b: 48 89 45 f8                 	movq	%rax, -0x8(%rbp)
10000056f: 31 c0                       	xorl	%eax, %eax
100000571: 48 83 7d f8 00              	cmpq	$0x0, -0x8(%rbp)
100000576: 88 45 f7                    	movb	%al, -0x9(%rbp)
100000579: 74 0e                       	je	0x100000589 <_getLastTask+0x29>
10000057b: 48 8b 45 f8                 	movq	-0x8(%rbp), %rax
10000057f: 48 83 38 00                 	cmpq	$0x0, (%rax)
100000583: 0f 95 c0                    	setne	%al
100000586: 88 45 f7                    	movb	%al, -0x9(%rbp)
100000589: 8a 45 f7                    	movb	-0x9(%rbp), %al
10000058c: a8 01                       	testb	$0x1, %al
10000058e: 75 02                       	jne	0x100000592 <_getLastTask+0x32>
100000590: eb 0d                       	jmp	0x10000059f <_getLastTask+0x3f>
100000592: 48 8b 45 f8                 	movq	-0x8(%rbp), %rax
100000596: 48 8b 00                    	movq	(%rax), %rax
100000599: 48 89 45 f8                 	movq	%rax, -0x8(%rbp)
10000059d: eb d0                       	jmp	0x10000056f <_getLastTask+0xf>
10000059f: 48 8b 45 f8                 	movq	-0x8(%rbp), %rax
1000005a3: 5d                          	popq	%rbp
1000005a4: c3                          	retq
1000005a5: 66 66 2e 0f 1f 84 00 00 00 00 00    	nopw	%cs:(%rax,%rax)

00000001000005b0 <_addTask>:
1000005b0: 55                          	pushq	%rbp
1000005b1: 48 89 e5                    	movq	%rsp, %rbp
1000005b4: 48 83 ec 20                 	subq	$0x20, %rsp
1000005b8: 48 89 7d f8                 	movq	%rdi, -0x8(%rbp)
1000005bc: e8 9f ff ff ff              	callq	0x100000560 <_getLastTask>
1000005c1: 48 89 45 f0                 	movq	%rax, -0x10(%rbp)
1000005c5: 48 8b 7d f8                 	movq	-0x8(%rbp), %rdi
1000005c9: e8 6c 01 00 00              	callq	0x10000073a <_strlen+0x10000073a>
1000005ce: 48 89 c7                    	movq	%rax, %rdi
1000005d1: 48 83 c7 10                 	addq	$0x10, %rdi
1000005d5: 48 83 c7 01                 	addq	$0x1, %rdi
1000005d9: e8 50 01 00 00              	callq	0x10000072e <_strlen+0x10000072e>
1000005de: 48 89 45 e8                 	movq	%rax, -0x18(%rbp)
1000005e2: 48 8b 45 e8                 	movq	-0x18(%rbp), %rax
1000005e6: 48 c7 00 00 00 00 00        	movq	$0x0, (%rax)
1000005ed: 48 8b 7d f8                 	movq	-0x8(%rbp), %rdi
1000005f1: e8 44 01 00 00              	callq	0x10000073a <_strlen+0x10000073a>
1000005f6: 89 c1                       	movl	%eax, %ecx
1000005f8: 48 8b 45 e8                 	movq	-0x18(%rbp), %rax
1000005fc: 89 48 08                    	movl	%ecx, 0x8(%rax)
1000005ff: 48 8b 7d e8                 	movq	-0x18(%rbp), %rdi
100000603: 48 83 c7 10                 	addq	$0x10, %rdi
100000607: 48 8b 75 f8                 	movq	-0x8(%rbp), %rsi
10000060b: 48 8b 45 e8                 	movq	-0x18(%rbp), %rax
10000060f: 8b 40 08                    	movl	0x8(%rax), %eax
100000612: 83 c0 01                    	addl	$0x1, %eax
100000615: 48 63 d0                    	movslq	%eax, %rdx
100000618: 48 c7 c1 ff ff ff ff        	movq	$-0x1, %rcx
10000061f: e8 fe 00 00 00              	callq	0x100000722 <_strlen+0x100000722>
100000624: 48 83 7d f0 00              	cmpq	$0x0, -0x10(%rbp)
100000629: 75 0d                       	jne	0x100000638 <_addTask+0x88>
10000062b: 48 8b 45 e8                 	movq	-0x18(%rbp), %rax
10000062f: 48 89 05 ca 19 00 00        	movq	%rax, 0x19ca(%rip)      ## 0x100002000 <_firstTask>
100000636: eb 0b                       	jmp	0x100000643 <_addTask+0x93>
100000638: 48 8b 4d e8                 	movq	-0x18(%rbp), %rcx
10000063c: 48 8b 45 f0                 	movq	-0x10(%rbp), %rax
100000640: 48 89 08                    	movq	%rcx, (%rax)
100000643: 48 83 c4 20                 	addq	$0x20, %rsp
100000647: 5d                          	popq	%rbp
100000648: c3                          	retq
100000649: 0f 1f 80 00 00 00 00        	nopl	(%rax)

0000000100000650 <_printTasks>:
100000650: 55                          	pushq	%rbp
100000651: 48 89 e5                    	movq	%rsp, %rbp
100000654: 48 83 ec 10                 	subq	$0x10, %rsp
100000658: 48 8b 05 a1 19 00 00        	movq	0x19a1(%rip), %rax      ## 0x100002000 <_firstTask>
10000065f: 48 89 45 f8                 	movq	%rax, -0x8(%rbp)
100000663: 48 83 7d f8 00              	cmpq	$0x0, -0x8(%rbp)
100000668: 74 23                       	je	0x10000068d <_printTasks+0x3d>
10000066a: 48 8b 75 f8                 	movq	-0x8(%rbp), %rsi
10000066e: 48 83 c6 10                 	addq	$0x10, %rsi
100000672: 48 8d 3d c7 00 00 00        	leaq	0xc7(%rip), %rdi        ## 0x100000740 <_strlen+0x100000740>
100000679: b0 00                       	movb	$0x0, %al
10000067b: e8 b4 00 00 00              	callq	0x100000734 <_strlen+0x100000734>
100000680: 48 8b 45 f8                 	movq	-0x8(%rbp), %rax
100000684: 48 8b 00                    	movq	(%rax), %rax
100000687: 48 89 45 f8                 	movq	%rax, -0x8(%rbp)
10000068b: eb d6                       	jmp	0x100000663 <_printTasks+0x13>
10000068d: 48 83 c4 10                 	addq	$0x10, %rsp
100000691: 5d                          	popq	%rbp
100000692: c3                          	retq
100000693: 66 66 66 66 2e 0f 1f 84 00 00 00 00 00      	nopw	%cs:(%rax,%rax)

00000001000006a0 <_main>:
1000006a0: 55                          	pushq	%rbp
1000006a1: 48 89 e5                    	movq	%rsp, %rbp
1000006a4: 48 83 ec 30                 	subq	$0x30, %rsp
1000006a8: 48 8b 05 61 09 00 00        	movq	0x961(%rip), %rax       ## 0x100001010 <_strlen+0x100001010>
1000006af: 48 8b 00                    	movq	(%rax), %rax
1000006b2: 48 89 45 f8                 	movq	%rax, -0x8(%rbp)
1000006b6: c7 45 dc 00 00 00 00        	movl	$0x0, -0x24(%rbp)
1000006bd: 48 8b 05 ac 00 00 00        	movq	0xac(%rip), %rax        ## 0x100000770 <_strlen+0x100000770>
1000006c4: 48 89 45 e0                 	movq	%rax, -0x20(%rbp)
1000006c8: 48 8b 05 a9 00 00 00        	movq	0xa9(%rip), %rax        ## 0x100000778 <_strlen+0x100000778>
1000006cf: 48 89 45 e8                 	movq	%rax, -0x18(%rbp)
1000006d3: 8b 05 a7 00 00 00           	movl	0xa7(%rip), %eax        ## 0x100000780 <_strlen+0x100000780>
1000006d9: 89 45 f0                    	movl	%eax, -0x10(%rbp)
1000006dc: 48 8d 3d 61 00 00 00        	leaq	0x61(%rip), %rdi        ## 0x100000744 <_strlen+0x100000744>
1000006e3: e8 c8 fe ff ff              	callq	0x1000005b0 <_addTask>
1000006e8: 48 8d 3d 63 00 00 00        	leaq	0x63(%rip), %rdi        ## 0x100000752 <_strlen+0x100000752>
1000006ef: e8 bc fe ff ff              	callq	0x1000005b0 <_addTask>
1000006f4: 48 8d 7d e0                 	leaq	-0x20(%rbp), %rdi
1000006f8: e8 b3 fe ff ff              	callq	0x1000005b0 <_addTask>
1000006fd: e8 4e ff ff ff              	callq	0x100000650 <_printTasks>
100000702: 48 8b 05 07 09 00 00        	movq	0x907(%rip), %rax       ## 0x100001010 <_strlen+0x100001010>
100000709: 48 8b 00                    	movq	(%rax), %rax
10000070c: 48 8b 4d f8                 	movq	-0x8(%rbp), %rcx
100000710: 48 39 c8                    	cmpq	%rcx, %rax
100000713: 75 08                       	jne	0x10000071d <_main+0x7d>
100000715: 31 c0                       	xorl	%eax, %eax
100000717: 48 83 c4 30                 	addq	$0x30, %rsp
10000071b: 5d                          	popq	%rbp
10000071c: c3                          	retq
10000071d: e8 06 00 00 00              	callq	0x100000728 <_strlen+0x100000728>

Disassembly of section __TEXT,__stubs:

0000000100000722 <__stubs>:
100000722: ff 25 d8 08 00 00           	jmpq	*0x8d8(%rip)            ## 0x100001000 <_strlen+0x100001000>
100000728: ff 25 da 08 00 00           	jmpq	*0x8da(%rip)            ## 0x100001008 <_strlen+0x100001008>
10000072e: ff 25 e4 08 00 00           	jmpq	*0x8e4(%rip)            ## 0x100001018 <_strlen+0x100001018>
100000734: ff 25 e6 08 00 00           	jmpq	*0x8e6(%rip)            ## 0x100001020 <_strlen+0x100001020>
10000073a: ff 25 e8 08 00 00           	jmpq	*0x8e8(%rip)            ## 0x100001028 <_strlen+0x100001028>
