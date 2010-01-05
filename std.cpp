/**
 * std:: test
 * In vs2008, the distance and advance can be used without "std::",
 * so we will test in g++.
 *
 * Argument Dependent Lookup.
 *
 * @date 20091118
 */

#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

int main(int argc, char* argv[])
{
	int a[] = {0, 1, 2};
	int* p = std::find(a, a + sizeof(a) / sizeof(a[0]), 1);
	std::cout << std::distance(a, p) << std::endl;

	std::vector<int> v;
	std::vector<int>::iterator pos = find(v.begin(), v.end(), 1);
	size_t i = distance(v.begin(), pos);
	std::vector<int>::iterator another = v.begin();
	advance(another, i);

	return 0;
}
