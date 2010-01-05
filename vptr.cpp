/**
 * vptr test - class Both : public Non_v, public V
 *
 * @date 20090909
 */

#include <cstdio>

class Non_v {
public:
	int foo_;
};

class V {
public:
	virtual ~V() {}
	virtual void bar() {}

public:
	int bar_;
};

class Both : public Non_v, public V {
public:
	int baz_;
};

class Both_v : public V, public Non_v {
public:
	int baz_;
};

int main(int argc, char* argv[])
{
	// "Both" and "Both_v" have the same object model.
	Both b; b.foo_ = 1; b.bar_ = 2; b.baz_ = 3;
	Both_v v; v.foo_ = 1; v.bar_ = 2; v.baz_ = 3;
	int i;
	printf("Both: %d\n", sizeof(Both));
	for (i = 0; i < sizeof(Both) / sizeof(int); ++i) {
		int* p = reinterpret_cast<int*>(&b);
		printf("%p,", p[i]);
	}
	printf("\n");
	printf("Both_v: %d\n", sizeof(Both_v));
	for (i = 0; i < sizeof(Both_v) / sizeof(int); ++i) {
		int* p = reinterpret_cast<int*>(&v);
		printf("%p,", p[i]);
	}
	printf("\n");

	return 0;
}
