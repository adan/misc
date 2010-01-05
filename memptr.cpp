/**
 * member pointer test
 *
 * @date 20090903
 */

#include <iostream>

class Foo {
public:
	void bar() {
	}
	void bar(int n) {
	}
};

template <typename T, typename F>
void foo(T* c, F f)
{
	(c->*f)();
}

int main(int argc, char* argv[])
{
	typedef void (Foo::*Func)();
	Foo f;
	foo<Foo, Func>(&f, &Foo::bar); // Must explicit template arguments if overloaded.
	//foo(&f, &Foo::bar);

	return 0;
}
