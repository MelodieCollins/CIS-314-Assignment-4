#include <stdio.h>

long fact(long x) {
	if(x <= 1) {
		return 1;
	}

	//store x onto stack as px
	long px = x;
	//fx recursive until x = 1
	//push new instances on stack by calling fact()
	long fx = fact(x - 1);
	//muliply px by answer from recursive call
	return px * fx;
}

int main() {
	printf("fact(6): %ld\n", fact(6L)); //720
	printf("fact(5): %ld\n", fact(5L)); //120
	printf("fact(4): %ld\n", fact(4L)); //24
	printf("fact(3): %ld\n", fact(3L)); //6
	printf("fact(2): %ld\n", fact(2L)); //2
	printf("fact(1): %ld\n", fact(1L)); //1
	printf("fact(0): %ld\n", fact(0L)); //1
}
