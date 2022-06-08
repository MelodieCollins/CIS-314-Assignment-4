#include <stdio.h>

/*long loop(long x, long y)
//x in %rdi, y in %rsi, result in %rdx, mask in %rax

loop:
	movq %rsi, %rcx        // %rcx = y
	movl $1, %eax          // %eax = 1 (set lower bits of mask)
	movl $0, %edx          // %edx = 0 (set lower bits of result)
.L2:
	testq %rax, %rax       // set ZF = 1 if mask == 0
	je .L4                 // when equal, jump to label .L4
	movq %rax, %r8         // %r8 = mask
	andq %rdi, %r8         // %r8 = %r8 & x
	orq %r8, %rdx          // result = %r8 | result
	salq %cl, %rax         // shift last 8 bits of mask left by y 
	jmp .L2                // jump to label .L2
.L4:
	movq %rdx, %rax        // set %rax = result
	ret */

long loop(long a, long b) {
	long result = 0;
	for(long mask = 1; mask != 0; mask <<= b) {
		result |= (mask&a);
	}
	return result;
}

int main(){
	printf("loop(1,5): %ld\n", loop(1L,5L)); //1
	printf("loop(2,4): %ld\n", loop(2L,4L)); //0
	printf("loop(3,3): %ld\n", loop(3L,3L)); //1
	printf("loop(4,2): %ld\n", loop(4L,2L)); //4
	printf("loop(5,1): %ld\n", loop(5L,1L)); //5
}
