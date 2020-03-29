#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*Extend Euclidean Algorithm*/
int main() {
	int a, b;
	printf("Please enter two numbers : ");
	scanf("%d %d", &a, &b);

	/*Initialization*/
	int r1=a, r2=b,s1=1, s2=0, t1=0, t2=1;

	int r, s, t, q;
	while (r2 > 0) {
		q = r1 / r2;
		r = r1 - q*r2;
		r1 = r2;
		r2 = r;

		s = s1 - q*s2;
		s1 = s2;
		s2 = s;

		t = t1 - q * t2;
		t1 = t2;
		t2 = t;
	}
	printf("gcd(%d,%d) : %d\n", a, b, r1);
	printf("\n s*a + t*b = gcd(%d,%d) : %d*%d + %d*%d = %d\n",a,b,s1,a,t1,b,r1);
	return 0;
}