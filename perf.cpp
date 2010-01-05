/**
 * performance test
 *
 * @date 20091231
 */

#include <iostream>

void write(int i)
{
	std::cout << i << " " << i * 2 << "\n";
}

void write_e(int i)
{
	std::cout << i << " " << i * 2 << std::endl;
}

void write_c(int i)
{
	printf("%d %dc", i, i * 2);
}

void write_n(int i)
{
	printf("%d %d\n", i, i * 2);
}

int main(int argc, char* argv[])
{
	if (argc > 1) {
		int i, n = atoi(argv[1]);
		if (argc == 2) {
			for (i = 0; i < n; ++i) {
				write(i);
			}
		}
		else if (argv[2][1] == 'e') {
			for (i = 0; i < n; ++i) {
				write_e(i);
			}
		}
		else if (argv[2][1] == 'c') {
			for (i = 0; i < n; ++i) {
				write_c(i);
			}
		}
		else if (argv[2][1] == 'n') {
			for (i = 0; i < n; ++i) {
				write_n(i);
			}
		}
	}
	return 0;
}
