/**
 * double for-loop
 *
 * @date 20091205
 */

#include <stdio.h>

int main(int argc, char* argv[])
{
	int count;
	double d, stop = 0.01, delta = 1e-6;

	for (d = 0.0, count = 0; d < stop; d += delta, ++count) {
	}
	printf("%lf, %d\n", d, count);
	for (d = 0.0, count = 0; d <= stop; d += delta, ++count) {
	}
	printf("%lf, %d\n", d, count);
	for (count = 0, d = 0.0; count < 10000; ++count, d += delta) {
	}
	printf("%lf, %d\n", d, count);
	if (d < stop) {
		printf("%lf < %lf\n", d, stop);
	}
	int* p = (int*)&d;
	printf("%lf: %x%x\n", d, p[1], p[0]);
	d += delta;
	p = (int*)&d;
	printf("%lf: %x%x\n", d, p[1], p[0]);
	int* q = (int*)&stop;
	printf("%lf: %x%x\n", stop, q[1], q[0]);

	return 0;
}
