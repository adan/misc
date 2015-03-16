/**
 * greatest common divisor
 *
 * @date 20091229
 */

#include <cassert>
#include <cstdlib>
#include <cstdio>

int even(int n)
{
	return n & 0x01 ? 0 : 1;
}

void make_sure_no_less(int& x, int& y)
{
	if (x < y) {
		int tmp = x;
		x = y;
		y = tmp;
	}
}

int gcd(int x, int y)
{
	make_sure_no_less(x, y);
	if (!y) {
		return x;
	}
	else {
		if (even(x)) {
			if (even(y)) {
				return gcd(x >> 1, y >> 1) << 1;
			}
			else {
				return gcd(x >> 1, y);
			}
		}
		else {
			if (even(y)) {
				return gcd(x, y >> 1);
			}
			else {
				return gcd(y, x - y);
			}
		}
	}
	return x;
}

/**
 * not recursive gcd
 */
int nr_gcd(int x, int y)
{
	int n = 1;
	make_sure_no_less(x, y);
	while (y) {
		if (even(x)) {
			if (even(y)) {
				x >>= 1; y >>= 1; n <<= 1;
			}
			else {
				x >>= 1;
				make_sure_no_less(x, y);
			}
		}
		else {
			if (even(y)) {
				y >>= 1;
			}
			else {
				x -= y;
				make_sure_no_less(x, y);
			}
		}
	}
	return x * n;
}

int main(int argc, char* argv[])
{
	if (argc < 3) {
		fprintf(stderr, "Usage: %s num1 num2\n", argv[0]);
	}
	else if (argc == 3) {
		printf("%d\n", gcd(atoi(argv[1]), atoi(argv[2])));
	}
	else {
		printf("%d\n", nr_gcd(atoi(argv[1]), atoi(argv[2])));
	}
	return 0;
}
