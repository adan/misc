/**
 * operator test
 *
 * @20091030
 */

#include <iostream>

class C {
public:
	int*& operator[](size_t i) {
		return data_[i];
	}
	int* const& operator[](size_t i) const {
		return data_[i];
	}

private:
	int* data_[10];
};

int main(int argc, char* argv[])
{
	int i = 0;
	C c;
	c[0] = &i;

	return 0;
}
