#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>

int main() {
	printf("Smallest char: %hhd\n", CHAR_MIN);
	printf("Biggest char: %hhd\n", CHAR_MAX);
	printf("Biggest unsigned char: %hhu\n\n", UCHAR_MAX);

	printf("Smallest short: %hd\n", SHRT_MIN);
	printf("Biggest short: %hd\n", SHRT_MAX);
	printf("Biggest unsigned short: %hu\n\n", USHRT_MAX);

	printf("Smallest int: %d\n", INT_MIN);
	printf("Biggest int: %d\n", INT_MAX);
	printf("Biggest unsigned int: %u\n\n", UINT_MAX);

	printf("Smallest long: %ld\n", LONG_MIN);
	printf("Biggest long: %ld\n", LONG_MAX);
	printf("Biggest unsigned long: %lu\n\n", ULONG_MAX);

	printf("Smallest long long: %lld\n", LLONG_MIN);
	printf("Biggest long long: %lld\n", LLONG_MAX);
	printf("Biggest unsigned long long: %llu\n\n", ULLONG_MAX);

	printf("One byte = %d bits on this system.\n\n", CHAR_BIT);

	printf("float has a size of %zd bytes.\n", sizeof(float));
	printf("float precison = %d digits\n", FLT_DIG);
	printf("float epsilon = %.10E\n", FLT_EPSILON);
	printf("Smallest normal float: %.10E\n", FLT_MIN);
	printf("Largest normal float: %.10E\n\n", FLT_MAX);

	printf("double has a size of %zd bytes.\n", sizeof(double));
	printf("double precison = %d digits\n", DBL_DIG);
	printf("float epsilon = %.10lE\n", DBL_EPSILON);
	printf("Smallest double: %.10lE\n", DBL_MIN);
	printf("Largest double: %.10lE\n\n", DBL_MAX);

	printf("long double has a size of %zd bytes.\n", sizeof(long double));
	printf("long double precison = %d digits\n", LDBL_DIG);
	printf("float epsilon = %.10LE\n", LDBL_EPSILON);
	printf("Smallest long double: %.10LE\n", LDBL_MIN);
	printf("Largest long double: %.10LE\n\n", LDBL_MAX);

	system("pause");
	return 0;
}