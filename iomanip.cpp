/**
 * iomanip header file test
 *
 * @date 20090808
 */

#include <iostream>
#include <iomanip> // setfill, setw

int main(int argc, char* argv[])
{
	// std::hex requires iostream, but not iomanip
	std::cout << std::setfill('x') << std::setw(8) << std::hex << 15 << std::endl;

	return 0;
}
