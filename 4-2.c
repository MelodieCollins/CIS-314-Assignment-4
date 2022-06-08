#include <stdio.h>

/*long sum(long from, long to){
	long result = 0;

	increment:
		result += from;
		++from;
		if(from <= to){
			goto increment;
		}
		else{
			return result;
		}
}*/

long sum(long from, long to){
	//Declare and intialize result var - *do not modify*.
	long result = 0;
	
	//Ensure that argument *from* is in %rdi,
	//argument *to* is in %rsi, *result* is in %rax - *do not
	//modify*.
	__asm__("movq %0, %%rdi # from in rdi;" :: "r" (from));
	__asm__("movq %0, %%rsi # to in rsi;" :: "r" (to));
	__asm__("movq %0, %%rax # result in rax;" :: "r" (result));

	//Your x86-64 code goes below - comment each instruction...
	__asm__(
		".L2:;"
			"addq %rdi, %rax;" //# result += from
			"addq $1, %rdi;" //# ++from
			"cmpq %rsi, %rdi;" //# compare from:to
			"jle .L2;" //# if <=, goto .L2
	);

	//Ensure that *result* is in %rax for return - *do not modify*.
	__asm__("movq %%rax, %0 #result in rax;" : "=r" (result));
	return result;
}

int main(){
	printf("sum(1, 6): %ld\n", sum(1L,6L)); //21
	printf("sum(3, 5): %ld\n", sum(3L,5L)); //12
	printf("sum(5, 3): %ld\n", sum(5L,3L)); //5
}
