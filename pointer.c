/**
 * pointer test
 *
 * @date 20091029
 */

#include <stdio.h>

void foo()
{
	char* p = "abcde";
	char a[] = "abcde";
	printf("%x\n%x\n", p, a);
}

void change(char** p, char v)
{
	*p = &v;
}

void p()
{
	char* p = NULL;
	char a = 'a', b = 'b';

	p = &a;
	change(&p, b);
	printf("%c, %x, %x\n", *p, &b, p);
}

/**
 * "const char** p" only consts the char, not any pointer
 * "char* const* p" consts the char*, i.e., pointer to char. But the **p (char) can be modified.
 */
#ifdef CONST_CHAR
void modify(const char** p)
#else
void modify(char* const* p)
#endif // #ifdef CONST_CHAR
{
#ifdef CONST_CHAR
	*p = "another";
#else
	**p = 'm';
#endif // #ifdef CONST_CHAR
}

void const_test()
{
	const char* p = "string";
	char array[] = "array";
	char* const cp = array;
#ifdef CONST_CHAR
	modify(&p);
	printf("%s\n", p);
#else
	modify(&cp);
	printf("%s\n", cp);
#endif // #ifdef CONST_CHAR
}

int main(int argc, char* argv[])
{
	foo();
	p();
	const_test();

	return 0;
}
