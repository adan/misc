/**
 * base derive test
 *
 * @date 20091109
 */

#include <string>
#include <iostream>

template <typename D>
class B {
public:
	B() {
		D* p = static_cast<D*>(this);
		p->foo();
	}
};

class D : public B<D> {
public:
	void foo() {
		std::cout << "D::foo" << std::endl;
		std::cout << v_.length() << std::endl;
	}

private:
	std::string v_;
};

int main(int argc, char* argv[])
{
	D d;
	return 0;
}
