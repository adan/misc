/**
 * array pointer test
 *
 * @date 20091208
 */

#include <stdio.h>

int main(int argc, char* argv[])
{
	int a[10] = {0, 1, 2};
	printf("%p, %p\n", a, &a);

	return 0;
}
