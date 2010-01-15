/**
 * strtok test
 *
 * @date 20100115
 */

#include <stdio.h>
#include <string.h>

void test_common()
{
	char s[] = "common#test; token";
	// after:  "common\000test\000 token"
	char d[] = " ;#";
	char* r;

	r = strtok(s, d);
	for (; r;) {
		printf("\"%s\"\n", r);
		r = strtok(NULL, d);
	}
}

void test_first_delimiter()
{
	char s[] = "#delimiter index zero";
	// after:  "#delimiter\000index\000zero";
	char d[] = " ;#";
	char* r;

	r = strtok(s, d);
	for (; r;) {
		printf("\"%s\"\n", r);
		r = strtok(NULL, d);
	}
}

void test_last_delimiter()
{
	char s[] = "end#with delimiter;";
	// after:  "end\000with\000delimiter\000"
	char d[] = " ;#";
	char* r;

	r = strtok(s, d);
	for (; r;) {
		printf("\"%s\"\n", r);
		r = strtok(NULL, d);
	}
}

int main(int argc, char* argv[])
{
	test_common();
	test_first_delimiter();
	test_last_delimiter();
	return 0;
}
