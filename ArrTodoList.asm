
ArrTodoList:	file format mach-o 64-bit x86-64

Disassembly of section __TEXT,__text:

0000000100000470 <_getTask>:
100000470: 55                          	pushq	%rbp
100000471: 48 89 e5                    	movq	%rsp, %rbp
100000474: 48 89 7d f0                 	movq	%rdi, -0x10(%rbp)
100000478: 89 75 ec                    	movl	%esi, -0x14(%rbp)
10000047b: 83 7d ec 00                 	cmpl	$0x0, -0x14(%rbp)
10000047f: 7c 0c                       	jl	0x10000048d <_getTask+0x1d>
100000481: 8b 45 ec                    	movl	-0x14(%rbp), %eax
100000484: 48 8b 4d f0                 	movq	-0x10(%rbp), %rcx
100000488: 3b 41 08                    	cmpl	0x8(%rcx), %eax
10000048b: 7c 0a                       	jl	0x100000497 <_getTask+0x27>
10000048d: 48 c7 45 f8 00 00 00 00     	movq	$0x0, -0x8(%rbp)
100000495: eb 2c                       	jmp	0x1000004c3 <_getTask+0x53>
100000497: 48 8b 45 f0                 	movq	-0x10(%rbp), %rax
10000049b: 48 8b 00                    	movq	(%rax), %rax
10000049e: 48 63 4d ec                 	movslq	-0x14(%rbp), %rcx
1000004a2: 48 8b 04 c8                 	movq	(%rax,%rcx,8), %rax
1000004a6: 48 89 45 e0                 	movq	%rax, -0x20(%rbp)
1000004aa: 48 83 7d e0 00              	cmpq	$0x0, -0x20(%rbp)
1000004af: 75 0a                       	jne	0x1000004bb <_getTask+0x4b>
1000004b1: 48 c7 45 f8 00 00 00 00     	movq	$0x0, -0x8(%rbp)
1000004b9: eb 08                       	jmp	0x1000004c3 <_getTask+0x53>
1000004bb: 48 8b 45 e0                 	movq	-0x20(%rbp), %rax
1000004bf: 48 89 45 f8                 	movq	%rax, -0x8(%rbp)
1000004c3: 48 8b 45 f8                 	movq	-0x8(%rbp), %rax
1000004c7: 5d                          	popq	%rbp
1000004c8: c3                          	retq
1000004c9: 0f 1f 80 00 00 00 00        	nopl	(%rax)

00000001000004d0 <_getLastTask>:
1000004d0: 55                          	pushq	%rbp
1000004d1: 48 89 e5                    	movq	%rsp, %rbp
1000004d4: 48 83 ec 10                 	subq	$0x10, %rsp
1000004d8: 48 89 7d f8                 	movq	%rdi, -0x8(%rbp)
1000004dc: 48 8b 7d f8                 	movq	-0x8(%rbp), %rdi
1000004e0: 48 8b 45 f8                 	movq	-0x8(%rbp), %rax
1000004e4: 8b 70 08                    	movl	0x8(%rax), %esi
1000004e7: 83 ee 01                    	subl	$0x1, %esi
1000004ea: e8 81 ff ff ff              	callq	0x100000470 <_getTask>
1000004ef: 48 83 c4 10                 	addq	$0x10, %rsp
1000004f3: 5d                          	popq	%rbp
1000004f4: c3                          	retq
1000004f5: 66 66 2e 0f 1f 84 00 00 00 00 00    	nopw	%cs:(%rax,%rax)

0000000100000500 <_addTask>:
100000500: 55                          	pushq	%rbp
100000501: 48 89 e5                    	movq	%rsp, %rbp
100000504: 48 83 ec 30                 	subq	$0x30, %rsp
100000508: 48 89 7d f0                 	movq	%rdi, -0x10(%rbp)
10000050c: 48 89 75 e8                 	movq	%rsi, -0x18(%rbp)
100000510: 48 8b 45 f0                 	movq	-0x10(%rbp), %rax
100000514: 8b 40 08                    	movl	0x8(%rax), %eax
100000517: 48 8b 4d f0                 	movq	-0x10(%rbp), %rcx
10000051b: 3b 41 0c                    	cmpl	0xc(%rcx), %eax
10000051e: 7c 4a                       	jl	0x10000056a <_addTask+0x6a>
100000520: 48 8b 45 f0                 	movq	-0x10(%rbp), %rax
100000524: 48 8b 38                    	movq	(%rax), %rdi
100000527: 48 8b 45 f0                 	movq	-0x10(%rbp), %rax
10000052b: 8b 40 0c                    	movl	0xc(%rax), %eax
10000052e: d1 e0                       	shll	%eax
100000530: 48 63 f0                    	movslq	%eax, %rsi
100000533: 48 c1 e6 03                 	shlq	$0x3, %rsi
100000537: e8 2a 05 00 00              	callq	0x100000a66 <_strlen+0x100000a66>
10000053c: 48 89 45 e0                 	movq	%rax, -0x20(%rbp)
100000540: 48 83 7d e0 00              	cmpq	$0x0, -0x20(%rbp)
100000545: 75 0c                       	jne	0x100000553 <_addTask+0x53>
100000547: c7 45 fc 01 00 00 00        	movl	$0x1, -0x4(%rbp)
10000054e: e9 e6 00 00 00              	jmp	0x100000639 <_addTask+0x139>
100000553: 48 8b 45 f0                 	movq	-0x10(%rbp), %rax
100000557: 8b 48 0c                    	movl	0xc(%rax), %ecx
10000055a: d1 e1                       	shll	%ecx
10000055c: 89 48 0c                    	movl	%ecx, 0xc(%rax)
10000055f: 48 8b 4d e0                 	movq	-0x20(%rbp), %rcx
100000563: 48 8b 45 f0                 	movq	-0x10(%rbp), %rax
100000567: 48 89 08                    	movq	%rcx, (%rax)
10000056a: 48 8b 45 f0                 	movq	-0x10(%rbp), %rax
10000056e: 8b 48 08                    	movl	0x8(%rax), %ecx
100000571: 83 c1 01                    	addl	$0x1, %ecx
100000574: 89 48 08                    	movl	%ecx, 0x8(%rax)
100000577: bf 10 00 00 00              	movl	$0x10, %edi
10000057c: e8 d9 04 00 00              	callq	0x100000a5a <_strlen+0x100000a5a>
100000581: 48 89 c2                    	movq	%rax, %rdx
100000584: 48 8b 45 f0                 	movq	-0x10(%rbp), %rax
100000588: 48 8b 00                    	movq	(%rax), %rax
10000058b: 48 8b 4d f0                 	movq	-0x10(%rbp), %rcx
10000058f: 8b 49 08                    	movl	0x8(%rcx), %ecx
100000592: 83 e9 01                    	subl	$0x1, %ecx
100000595: 48 63 c9                    	movslq	%ecx, %rcx
100000598: 48 89 14 c8                 	movq	%rdx, (%rax,%rcx,8)
10000059c: bf 10 00 00 00              	movl	$0x10, %edi
1000005a1: e8 b4 04 00 00              	callq	0x100000a5a <_strlen+0x100000a5a>
1000005a6: 48 89 45 d8                 	movq	%rax, -0x28(%rbp)
1000005aa: 48 83 7d d8 00              	cmpq	$0x0, -0x28(%rbp)
1000005af: 75 09                       	jne	0x1000005ba <_addTask+0xba>
1000005b1: c7 45 fc 01 00 00 00        	movl	$0x1, -0x4(%rbp)
1000005b8: eb 7f                       	jmp	0x100000639 <_addTask+0x139>
1000005ba: 48 8b 7d e8                 	movq	-0x18(%rbp), %rdi
1000005be: e8 af 04 00 00              	callq	0x100000a72 <_strlen+0x100000a72>
1000005c3: 48 83 c0 01                 	addq	$0x1, %rax
1000005c7: 89 c1                       	movl	%eax, %ecx
1000005c9: 48 8b 45 d8                 	movq	-0x28(%rbp), %rax
1000005cd: 89 08                       	movl	%ecx, (%rax)
1000005cf: 48 8b 45 d8                 	movq	-0x28(%rbp), %rax
1000005d3: 48 63 38                    	movslq	(%rax), %rdi
1000005d6: 48 c1 e7 00                 	shlq	$0x0, %rdi
1000005da: e8 7b 04 00 00              	callq	0x100000a5a <_strlen+0x100000a5a>
1000005df: 48 89 c1                    	movq	%rax, %rcx
1000005e2: 48 8b 45 d8                 	movq	-0x28(%rbp), %rax
1000005e6: 48 89 48 08                 	movq	%rcx, 0x8(%rax)
1000005ea: 48 8b 45 d8                 	movq	-0x28(%rbp), %rax
1000005ee: 48 83 78 08 00              	cmpq	$0x0, 0x8(%rax)
1000005f3: 75 09                       	jne	0x1000005fe <_addTask+0xfe>
1000005f5: c7 45 fc 01 00 00 00        	movl	$0x1, -0x4(%rbp)
1000005fc: eb 3b                       	jmp	0x100000639 <_addTask+0x139>
1000005fe: 48 8b 45 d8                 	movq	-0x28(%rbp), %rax
100000602: 48 8b 78 08                 	movq	0x8(%rax), %rdi
100000606: 48 8b 75 e8                 	movq	-0x18(%rbp), %rsi
10000060a: 48 c7 c2 ff ff ff ff        	movq	$-0x1, %rdx
100000611: e8 32 04 00 00              	callq	0x100000a48 <_strlen+0x100000a48>
100000616: 48 8b 55 d8                 	movq	-0x28(%rbp), %rdx
10000061a: 48 8b 45 f0                 	movq	-0x10(%rbp), %rax
10000061e: 48 8b 00                    	movq	(%rax), %rax
100000621: 48 8b 4d f0                 	movq	-0x10(%rbp), %rcx
100000625: 8b 49 08                    	movl	0x8(%rcx), %ecx
100000628: 83 e9 01                    	subl	$0x1, %ecx
10000062b: 48 63 c9                    	movslq	%ecx, %rcx
10000062e: 48 89 14 c8                 	movq	%rdx, (%rax,%rcx,8)
100000632: c7 45 fc 00 00 00 00        	movl	$0x0, -0x4(%rbp)
100000639: 8b 45 fc                    	movl	-0x4(%rbp), %eax
10000063c: 48 83 c4 30                 	addq	$0x30, %rsp
100000640: 5d                          	popq	%rbp
100000641: c3                          	retq
100000642: 66 66 66 66 66 2e 0f 1f 84 00 00 00 00 00   	nopw	%cs:(%rax,%rax)

0000000100000650 <_printTasks>:
100000650: 55                          	pushq	%rbp
100000651: 48 89 e5                    	movq	%rsp, %rbp
100000654: 48 83 ec 30                 	subq	$0x30, %rsp
100000658: 48 89 7d f0                 	movq	%rdi, -0x10(%rbp)
10000065c: 48 8b 45 f0                 	movq	-0x10(%rbp), %rax
100000660: 48 8b 00                    	movq	(%rax), %rax
100000663: 48 8b 00                    	movq	(%rax), %rax
100000666: 48 89 45 e8                 	movq	%rax, -0x18(%rbp)
10000066a: 48 83 7d e8 00              	cmpq	$0x0, -0x18(%rbp)
10000066f: 75 17                       	jne	0x100000688 <_printTasks+0x38>
100000671: 48 8d 3d 00 04 00 00        	leaq	0x400(%rip), %rdi       ## 0x100000a78 <_strlen+0x100000a78>
100000678: b0 00                       	movb	$0x0, %al
10000067a: e8 e1 03 00 00              	callq	0x100000a60 <_strlen+0x100000a60>
10000067f: c7 45 fc 01 00 00 00        	movl	$0x1, -0x4(%rbp)
100000686: eb 6d                       	jmp	0x1000006f5 <_printTasks+0xa5>
100000688: c7 45 e4 00 00 00 00        	movl	$0x0, -0x1c(%rbp)
10000068f: 8b 45 e4                    	movl	-0x1c(%rbp), %eax
100000692: 48 8b 4d f0                 	movq	-0x10(%rbp), %rcx
100000696: 3b 41 08                    	cmpl	0x8(%rcx), %eax
100000699: 7d 53                       	jge	0x1000006ee <_printTasks+0x9e>
10000069b: 48 8b 45 f0                 	movq	-0x10(%rbp), %rax
10000069f: 48 8b 00                    	movq	(%rax), %rax
1000006a2: 48 63 4d e4                 	movslq	-0x1c(%rbp), %rcx
1000006a6: 48 8b 04 c8                 	movq	(%rax,%rcx,8), %rax
1000006aa: 48 89 45 d8                 	movq	%rax, -0x28(%rbp)
1000006ae: 48 83 7d d8 00              	cmpq	$0x0, -0x28(%rbp)
1000006b3: 74 1e                       	je	0x1000006d3 <_printTasks+0x83>
1000006b5: 8b 75 e4                    	movl	-0x1c(%rbp), %esi
1000006b8: 83 c6 01                    	addl	$0x1, %esi
1000006bb: 48 8b 45 d8                 	movq	-0x28(%rbp), %rax
1000006bf: 48 8b 50 08                 	movq	0x8(%rax), %rdx
1000006c3: 48 8d 3d c3 03 00 00        	leaq	0x3c3(%rip), %rdi       ## 0x100000a8d <_strlen+0x100000a8d>
1000006ca: b0 00                       	movb	$0x0, %al
1000006cc: e8 8f 03 00 00              	callq	0x100000a60 <_strlen+0x100000a60>
1000006d1: eb 0e                       	jmp	0x1000006e1 <_printTasks+0x91>
1000006d3: 48 8d 3d bb 03 00 00        	leaq	0x3bb(%rip), %rdi       ## 0x100000a95 <_strlen+0x100000a95>
1000006da: b0 00                       	movb	$0x0, %al
1000006dc: e8 7f 03 00 00              	callq	0x100000a60 <_strlen+0x100000a60>
1000006e1: eb 00                       	jmp	0x1000006e3 <_printTasks+0x93>
1000006e3: 8b 45 e4                    	movl	-0x1c(%rbp), %eax
1000006e6: 83 c0 01                    	addl	$0x1, %eax
1000006e9: 89 45 e4                    	movl	%eax, -0x1c(%rbp)
1000006ec: eb a1                       	jmp	0x10000068f <_printTasks+0x3f>
1000006ee: c7 45 fc 00 00 00 00        	movl	$0x0, -0x4(%rbp)
1000006f5: 8b 45 fc                    	movl	-0x4(%rbp), %eax
1000006f8: 48 83 c4 30                 	addq	$0x30, %rsp
1000006fc: 5d                          	popq	%rbp
1000006fd: c3                          	retq
1000006fe: 66 90                       	nop

0000000100000700 <_generateList>:
100000700: 55                          	pushq	%rbp
100000701: 48 89 e5                    	movq	%rsp, %rbp
100000704: 48 83 ec 10                 	subq	$0x10, %rsp
100000708: bf 10 00 00 00              	movl	$0x10, %edi
10000070d: e8 48 03 00 00              	callq	0x100000a5a <_strlen+0x100000a5a>
100000712: 48 89 45 f0                 	movq	%rax, -0x10(%rbp)
100000716: 48 83 7d f0 00              	cmpq	$0x0, -0x10(%rbp)
10000071b: 75 0a                       	jne	0x100000727 <_generateList+0x27>
10000071d: 48 c7 45 f8 00 00 00 00     	movq	$0x0, -0x8(%rbp)
100000725: eb 56                       	jmp	0x10000077d <_generateList+0x7d>
100000727: 48 8b 45 f0                 	movq	-0x10(%rbp), %rax
10000072b: 48 63 78 0c                 	movslq	0xc(%rax), %rdi
10000072f: 48 c1 e7 03                 	shlq	$0x3, %rdi
100000733: e8 22 03 00 00              	callq	0x100000a5a <_strlen+0x100000a5a>
100000738: 48 89 c1                    	movq	%rax, %rcx
10000073b: 48 8b 45 f0                 	movq	-0x10(%rbp), %rax
10000073f: 48 89 08                    	movq	%rcx, (%rax)
100000742: 48 8b 45 f0                 	movq	-0x10(%rbp), %rax
100000746: 48 83 38 00                 	cmpq	$0x0, (%rax)
10000074a: 75 13                       	jne	0x10000075f <_generateList+0x5f>
10000074c: 48 8b 7d f0                 	movq	-0x10(%rbp), %rdi
100000750: e8 ff 02 00 00              	callq	0x100000a54 <_strlen+0x100000a54>
100000755: 48 c7 45 f8 00 00 00 00     	movq	$0x0, -0x8(%rbp)
10000075d: eb 1e                       	jmp	0x10000077d <_generateList+0x7d>
10000075f: 48 8b 45 f0                 	movq	-0x10(%rbp), %rax
100000763: c7 40 08 00 00 00 00        	movl	$0x0, 0x8(%rax)
10000076a: 48 8b 45 f0                 	movq	-0x10(%rbp), %rax
10000076e: c7 40 0c 02 00 00 00        	movl	$0x2, 0xc(%rax)
100000775: 48 8b 45 f0                 	movq	-0x10(%rbp), %rax
100000779: 48 89 45 f8                 	movq	%rax, -0x8(%rbp)
10000077d: 48 8b 45 f8                 	movq	-0x8(%rbp), %rax
100000781: 48 83 c4 10                 	addq	$0x10, %rsp
100000785: 5d                          	popq	%rbp
100000786: c3                          	retq
100000787: 66 0f 1f 84 00 00 00 00 00  	nopw	(%rax,%rax)

0000000100000790 <_removeTask>:
100000790: 55                          	pushq	%rbp
100000791: 48 89 e5                    	movq	%rsp, %rbp
100000794: 48 83 ec 30                 	subq	$0x30, %rsp
100000798: 48 89 7d f0                 	movq	%rdi, -0x10(%rbp)
10000079c: 89 75 ec                    	movl	%esi, -0x14(%rbp)
10000079f: 8b 45 ec                    	movl	-0x14(%rbp), %eax
1000007a2: 83 c0 ff                    	addl	$-0x1, %eax
1000007a5: 89 45 ec                    	movl	%eax, -0x14(%rbp)
1000007a8: 83 7d ec 00                 	cmpl	$0x0, -0x14(%rbp)
1000007ac: 7c 0c                       	jl	0x1000007ba <_removeTask+0x2a>
1000007ae: 8b 45 ec                    	movl	-0x14(%rbp), %eax
1000007b1: 48 8b 4d f0                 	movq	-0x10(%rbp), %rcx
1000007b5: 3b 41 08                    	cmpl	0x8(%rcx), %eax
1000007b8: 7c 0c                       	jl	0x1000007c6 <_removeTask+0x36>
1000007ba: c7 45 fc 01 00 00 00        	movl	$0x1, -0x4(%rbp)
1000007c1: e9 92 00 00 00              	jmp	0x100000858 <_removeTask+0xc8>
1000007c6: 48 8b 45 f0                 	movq	-0x10(%rbp), %rax
1000007ca: 48 8b 00                    	movq	(%rax), %rax
1000007cd: 48 63 4d ec                 	movslq	-0x14(%rbp), %rcx
1000007d1: 48 8b 04 c8                 	movq	(%rax,%rcx,8), %rax
1000007d5: 48 89 45 e0                 	movq	%rax, -0x20(%rbp)
1000007d9: 48 83 7d e0 00              	cmpq	$0x0, -0x20(%rbp)
1000007de: 75 09                       	jne	0x1000007e9 <_removeTask+0x59>
1000007e0: c7 45 fc 01 00 00 00        	movl	$0x1, -0x4(%rbp)
1000007e7: eb 6f                       	jmp	0x100000858 <_removeTask+0xc8>
1000007e9: 48 8b 45 e0                 	movq	-0x20(%rbp), %rax
1000007ed: 48 8b 78 08                 	movq	0x8(%rax), %rdi
1000007f1: e8 5e 02 00 00              	callq	0x100000a54 <_strlen+0x100000a54>
1000007f6: 48 8b 7d e0                 	movq	-0x20(%rbp), %rdi
1000007fa: e8 55 02 00 00              	callq	0x100000a54 <_strlen+0x100000a54>
1000007ff: 8b 45 ec                    	movl	-0x14(%rbp), %eax
100000802: 89 45 dc                    	movl	%eax, -0x24(%rbp)
100000805: 8b 45 dc                    	movl	-0x24(%rbp), %eax
100000808: 48 8b 4d f0                 	movq	-0x10(%rbp), %rcx
10000080c: 8b 49 08                    	movl	0x8(%rcx), %ecx
10000080f: 83 e9 01                    	subl	$0x1, %ecx
100000812: 39 c8                       	cmpl	%ecx, %eax
100000814: 7d 2e                       	jge	0x100000844 <_removeTask+0xb4>
100000816: 48 8b 45 f0                 	movq	-0x10(%rbp), %rax
10000081a: 48 8b 00                    	movq	(%rax), %rax
10000081d: 8b 4d dc                    	movl	-0x24(%rbp), %ecx
100000820: 83 c1 01                    	addl	$0x1, %ecx
100000823: 48 63 c9                    	movslq	%ecx, %rcx
100000826: 48 8b 14 c8                 	movq	(%rax,%rcx,8), %rdx
10000082a: 48 8b 45 f0                 	movq	-0x10(%rbp), %rax
10000082e: 48 8b 00                    	movq	(%rax), %rax
100000831: 48 63 4d dc                 	movslq	-0x24(%rbp), %rcx
100000835: 48 89 14 c8                 	movq	%rdx, (%rax,%rcx,8)
100000839: 8b 45 dc                    	movl	-0x24(%rbp), %eax
10000083c: 83 c0 01                    	addl	$0x1, %eax
10000083f: 89 45 dc                    	movl	%eax, -0x24(%rbp)
100000842: eb c1                       	jmp	0x100000805 <_removeTask+0x75>
100000844: 48 8b 45 f0                 	movq	-0x10(%rbp), %rax
100000848: 8b 48 08                    	movl	0x8(%rax), %ecx
10000084b: 83 c1 ff                    	addl	$-0x1, %ecx
10000084e: 89 48 08                    	movl	%ecx, 0x8(%rax)
100000851: c7 45 fc 00 00 00 00        	movl	$0x0, -0x4(%rbp)
100000858: 8b 45 fc                    	movl	-0x4(%rbp), %eax
10000085b: 48 83 c4 30                 	addq	$0x30, %rsp
10000085f: 5d                          	popq	%rbp
100000860: c3                          	retq
100000861: 66 66 66 66 66 66 2e 0f 1f 84 00 00 00 00 00	nopw	%cs:(%rax,%rax)

0000000100000870 <_removeList>:
100000870: 55                          	pushq	%rbp
100000871: 48 89 e5                    	movq	%rsp, %rbp
100000874: 48 83 ec 20                 	subq	$0x20, %rsp
100000878: 48 89 7d f8                 	movq	%rdi, -0x8(%rbp)
10000087c: 48 8b 45 f8                 	movq	-0x8(%rbp), %rax
100000880: 8b 40 08                    	movl	0x8(%rax), %eax
100000883: 83 e8 01                    	subl	$0x1, %eax
100000886: 89 45 f4                    	movl	%eax, -0xc(%rbp)
100000889: 83 7d f4 00                 	cmpl	$0x0, -0xc(%rbp)
10000088d: 7c 3d                       	jl	0x1000008cc <_removeList+0x5c>
10000088f: 48 8b 45 f8                 	movq	-0x8(%rbp), %rax
100000893: 48 8b 00                    	movq	(%rax), %rax
100000896: 48 63 4d f4                 	movslq	-0xc(%rbp), %rcx
10000089a: 48 8b 04 c8                 	movq	(%rax,%rcx,8), %rax
10000089e: 48 89 45 e8                 	movq	%rax, -0x18(%rbp)
1000008a2: 48 83 7d e8 00              	cmpq	$0x0, -0x18(%rbp)
1000008a7: 74 16                       	je	0x1000008bf <_removeList+0x4f>
1000008a9: 48 8b 45 e8                 	movq	-0x18(%rbp), %rax
1000008ad: 48 8b 78 08                 	movq	0x8(%rax), %rdi
1000008b1: e8 9e 01 00 00              	callq	0x100000a54 <_strlen+0x100000a54>
1000008b6: 48 8b 7d e8                 	movq	-0x18(%rbp), %rdi
1000008ba: e8 95 01 00 00              	callq	0x100000a54 <_strlen+0x100000a54>
1000008bf: eb 00                       	jmp	0x1000008c1 <_removeList+0x51>
1000008c1: 8b 45 f4                    	movl	-0xc(%rbp), %eax
1000008c4: 83 c0 ff                    	addl	$-0x1, %eax
1000008c7: 89 45 f4                    	movl	%eax, -0xc(%rbp)
1000008ca: eb bd                       	jmp	0x100000889 <_removeList+0x19>
1000008cc: 48 8b 45 f8                 	movq	-0x8(%rbp), %rax
1000008d0: 48 8b 38                    	movq	(%rax), %rdi
1000008d3: e8 7c 01 00 00              	callq	0x100000a54 <_strlen+0x100000a54>
1000008d8: 48 8b 7d f8                 	movq	-0x8(%rbp), %rdi
1000008dc: e8 73 01 00 00              	callq	0x100000a54 <_strlen+0x100000a54>
1000008e1: 48 c7 45 f8 00 00 00 00     	movq	$0x0, -0x8(%rbp)
1000008e9: 31 c0                       	xorl	%eax, %eax
1000008eb: 48 83 c4 20                 	addq	$0x20, %rsp
1000008ef: 5d                          	popq	%rbp
1000008f0: c3                          	retq
1000008f1: 66 66 66 66 66 66 2e 0f 1f 84 00 00 00 00 00	nopw	%cs:(%rax,%rax)

0000000100000900 <_main>:
100000900: 55                          	pushq	%rbp
100000901: 48 89 e5                    	movq	%rsp, %rbp
100000904: 48 83 ec 30                 	subq	$0x30, %rsp
100000908: 48 8b 05 f9 06 00 00        	movq	0x6f9(%rip), %rax       ## 0x100001008 <_strlen+0x100001008>
10000090f: 48 8b 00                    	movq	(%rax), %rax
100000912: 48 89 45 f8                 	movq	%rax, -0x8(%rbp)
100000916: c7 45 e4 00 00 00 00        	movl	$0x0, -0x1c(%rbp)
10000091d: e8 de fd ff ff              	callq	0x100000700 <_generateList>
100000922: 48 89 45 d8                 	movq	%rax, -0x28(%rbp)
100000926: 48 83 7d d8 00              	cmpq	$0x0, -0x28(%rbp)
10000092b: 75 1a                       	jne	0x100000947 <_main+0x47>
10000092d: 48 8d 3d 75 01 00 00        	leaq	0x175(%rip), %rdi       ## 0x100000aa9 <_strlen+0x100000aa9>
100000934: b0 00                       	movb	$0x0, %al
100000936: e8 25 01 00 00              	callq	0x100000a60 <_strlen+0x100000a60>
10000093b: c7 45 e4 01 00 00 00        	movl	$0x1, -0x1c(%rbp)
100000942: e9 d4 00 00 00              	jmp	0x100000a1b <_main+0x11b>
100000947: 48 8b 7d d8                 	movq	-0x28(%rbp), %rdi
10000094b: e8 00 fd ff ff              	callq	0x100000650 <_printTasks>
100000950: 48 8b 05 6d 01 00 00        	movq	0x16d(%rip), %rax       ## 0x100000ac4 <_strlen+0x100000ac4>
100000957: 48 89 45 eb                 	movq	%rax, -0x15(%rbp)
10000095b: 8b 05 6b 01 00 00           	movl	0x16b(%rip), %eax       ## 0x100000acc <_strlen+0x100000acc>
100000961: 89 45 f3                    	movl	%eax, -0xd(%rbp)
100000964: 8a 05 66 01 00 00           	movb	0x166(%rip), %al        ## 0x100000ad0 <_strlen+0x100000ad0>
10000096a: 88 45 f7                    	movb	%al, -0x9(%rbp)
10000096d: 48 8d 7d eb                 	leaq	-0x15(%rbp), %rdi
100000971: 48 8b 05 98 06 00 00        	movq	0x698(%rip), %rax       ## 0x100001010 <_strlen+0x100001010>
100000978: 48 8b 10                    	movq	(%rax), %rdx
10000097b: be 0d 00 00 00              	movl	$0xd, %esi
100000980: e8 c9 00 00 00              	callq	0x100000a4e <_strlen+0x100000a4e>
100000985: 48 8d 7d eb                 	leaq	-0x15(%rbp), %rdi
100000989: 48 8d 35 41 01 00 00        	leaq	0x141(%rip), %rsi       ## 0x100000ad1 <_strlen+0x100000ad1>
100000990: e8 d7 00 00 00              	callq	0x100000a6c <_strlen+0x100000a6c>
100000995: c6 44 05 eb 00              	movb	$0x0, -0x15(%rbp,%rax)
10000099a: 8b 05 33 01 00 00           	movl	0x133(%rip), %eax       ## 0x100000ad3 <_strlen+0x100000ad3>
1000009a0: 89 45 d4                    	movl	%eax, -0x2c(%rbp)
1000009a3: 48 8b 7d d8                 	movq	-0x28(%rbp), %rdi
1000009a7: 48 8d 35 29 01 00 00        	leaq	0x129(%rip), %rsi       ## 0x100000ad7 <_strlen+0x100000ad7>
1000009ae: e8 4d fb ff ff              	callq	0x100000500 <_addTask>
1000009b3: 48 8b 7d d8                 	movq	-0x28(%rbp), %rdi
1000009b7: 48 8d 35 27 01 00 00        	leaq	0x127(%rip), %rsi       ## 0x100000ae5 <_strlen+0x100000ae5>
1000009be: e8 3d fb ff ff              	callq	0x100000500 <_addTask>
1000009c3: 48 8b 7d d8                 	movq	-0x28(%rbp), %rdi
1000009c7: 48 8d 75 eb                 	leaq	-0x15(%rbp), %rsi
1000009cb: e8 30 fb ff ff              	callq	0x100000500 <_addTask>
1000009d0: 48 8b 7d d8                 	movq	-0x28(%rbp), %rdi
1000009d4: 48 8d 75 d4                 	leaq	-0x2c(%rbp), %rsi
1000009d8: e8 23 fb ff ff              	callq	0x100000500 <_addTask>
1000009dd: 48 8b 7d d8                 	movq	-0x28(%rbp), %rdi
1000009e1: e8 6a fc ff ff              	callq	0x100000650 <_printTasks>
1000009e6: 48 8d 3d e4 00 00 00        	leaq	0xe4(%rip), %rdi        ## 0x100000ad1 <_strlen+0x100000ad1>
1000009ed: b0 00                       	movb	$0x0, %al
1000009ef: e8 6c 00 00 00              	callq	0x100000a60 <_strlen+0x100000a60>
1000009f4: 48 8b 7d d8                 	movq	-0x28(%rbp), %rdi
1000009f8: be 01 00 00 00              	movl	$0x1, %esi
1000009fd: e8 8e fd ff ff              	callq	0x100000790 <_removeTask>
100000a02: 48 8b 7d d8                 	movq	-0x28(%rbp), %rdi
100000a06: e8 45 fc ff ff              	callq	0x100000650 <_printTasks>
100000a0b: 48 8b 7d d8                 	movq	-0x28(%rbp), %rdi
100000a0f: e8 5c fe ff ff              	callq	0x100000870 <_removeList>
100000a14: c7 45 e4 00 00 00 00        	movl	$0x0, -0x1c(%rbp)
100000a1b: 8b 45 e4                    	movl	-0x1c(%rbp), %eax
100000a1e: 89 45 d0                    	movl	%eax, -0x30(%rbp)
100000a21: 48 8b 05 e0 05 00 00        	movq	0x5e0(%rip), %rax       ## 0x100001008 <_strlen+0x100001008>
100000a28: 48 8b 00                    	movq	(%rax), %rax
100000a2b: 48 8b 4d f8                 	movq	-0x8(%rbp), %rcx
100000a2f: 48 39 c8                    	cmpq	%rcx, %rax
100000a32: 75 09                       	jne	0x100000a3d <_main+0x13d>
100000a34: 8b 45 d0                    	movl	-0x30(%rbp), %eax
100000a37: 48 83 c4 30                 	addq	$0x30, %rsp
100000a3b: 5d                          	popq	%rbp
100000a3c: c3                          	retq
100000a3d: e8 00 00 00 00              	callq	0x100000a42 <_strlen+0x100000a42>

Disassembly of section __TEXT,__stubs:

0000000100000a42 <__stubs>:
100000a42: ff 25 b8 05 00 00           	jmpq	*0x5b8(%rip)            ## 0x100001000 <_strlen+0x100001000>
100000a48: ff 25 ca 05 00 00           	jmpq	*0x5ca(%rip)            ## 0x100001018 <_strlen+0x100001018>
100000a4e: ff 25 cc 05 00 00           	jmpq	*0x5cc(%rip)            ## 0x100001020 <_strlen+0x100001020>
100000a54: ff 25 ce 05 00 00           	jmpq	*0x5ce(%rip)            ## 0x100001028 <_strlen+0x100001028>
100000a5a: ff 25 d0 05 00 00           	jmpq	*0x5d0(%rip)            ## 0x100001030 <_strlen+0x100001030>
100000a60: ff 25 d2 05 00 00           	jmpq	*0x5d2(%rip)            ## 0x100001038 <_strlen+0x100001038>
100000a66: ff 25 d4 05 00 00           	jmpq	*0x5d4(%rip)            ## 0x100001040 <_strlen+0x100001040>
100000a6c: ff 25 d6 05 00 00           	jmpq	*0x5d6(%rip)            ## 0x100001048 <_strlen+0x100001048>
100000a72: ff 25 d8 05 00 00           	jmpq	*0x5d8(%rip)            ## 0x100001050 <_strlen+0x100001050>
