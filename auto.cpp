/**
 * auto test compiler
 *
 * @date 20091117
 */

#include <vector>

int main(int argc, char* argv[])
{
	std::vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	for (auto i = v.begin(); i != v.end(); ++i) {
	}

	return 0;
}
