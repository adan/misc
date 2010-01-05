/**
 * non derivable test
 *
 * @date 20091020
 */

#include <iostream>

namespace non_derivable {
class Non_derivable_helper {
protected:
	Non_derivable_helper(int) {}
};
}

class Non_derivable : virtual private non_derivable::Non_derivable_helper {
public:
	Non_derivable() : Non_derivable_helper(0) {
	}
};

class Bug : virtual public non_derivable::Non_derivable_helper {
public:
	Bug() : Non_derivable_helper(0) {
	}
};

class My : public Non_derivable, public Bug {
public:
	My() : Non_derivable_helper(1) {}
};

int main(int argc, char* argv[])
{
	My my;

	return 0;
}
