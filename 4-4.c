#include <stdio.h>
#define N 4
typedef long array_t[N][N];

/*.L10:
  movq	(%rax), %rcx        // t1 = *(a+i+i*N)
  movq	(%rdx), %rsi        // t2 = *(a+i+i*N)
  movq	%rsi, (%rax)        // *(a+i+i*N) = t2
  movq	%rcx, (%rdx)        // *(a+i+i*N) = t1
  addq	$8, %rax            // (a+i+i*N) += 8 bytes (move to next column)
  addq	$32, %rdx           // (a+i+i*N) += N*8 bytes (move to next row)
  cmpq	%r9, %rax           // compare j to N*8
  jne  .L10 */              // jump to label .L10 when j not equal N*8

//optimize this function to match x86-64 above when compiled w/ -Og
void transpose(array_t a) {
	/*for (long i = 0; i < N; ++i) {
		for (long j = 0; j < i; ++j) {
			long t1 = a[i][j];
			long t2 = a[j][i];
			a[i][j] = t2;
			a[j][i] = t1;
		}
	}*/

	long *ar = (long*)a;
	for(long i = 0L; i < N; ++i) {
		//*x = a[i][i]
		long *x = ar + i + (i*N);
		//*y = a[i][i]
		long *y = x;
		for (long j = i; j != N; ++j) {
			long t1 = *y;
			long t2 = *x;
			*y = t2;
			*x = t1;
			//move x 1 index to the right (one column)
			x = x + 1;
			//move y down 1 index (one row) by moving N to the right
			y = y + N;
		}
	
	}
}

int main() {
	long a[N][N] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	transpose(a);
	for(long i = 0L; i < N; i++){
		for(long j = 0L; j < N; j++){
			printf("%3ld ", a[i][j]);
		}
		printf("\n");
	}
}
