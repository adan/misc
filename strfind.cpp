/**
 * string find test
 *
 * @date 20090827
 */

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	if (argc < 3) {
		std::cerr << "Usage: " << argv[0] << " separator pattern" << std::endl;
		return 1;
	}
	std::string s(argv[1]);
	std::string p(argv[2]);
	std::string::size_type pre = 0, cur = 0;
	for (; cur != std::string::npos; pre = cur, ++pre) {
		cur = p.find(s, pre);
		std::cout << p.substr(pre, cur - pre) << std::endl;
	}
	std::cout << "pre: " << pre << std::endl;

	return 0;
}
