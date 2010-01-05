/**
 * stl template test
 *
 * @date 20091107
 */

#include <vector>
#include <list>
#include <iostream>

template <template <typename U, typename A = std::allocator<U> > class T>
class C {
public:
	C(int i) {
		coll_.push_back(i);
	}
	void print() {
		std::cout << *coll_.begin() << std::endl;
	}

private:
	T<int> coll_;
};

#if 0
template <class T>
class C {
public:
	C(int i) {
		coll_.push_back(i);
	}
	void print() {
		std::cout << *coll_.begin() << std::endl;
	}

private:
	T coll_;
};
#endif

int main(int argc, char* argv[])
{
	C<std::list> c(1);
	c.print();

	return 0;
}
