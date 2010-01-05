/**
 * init test
 *
 * @date 20091224
 */

struct Test {
	int a;
	int b;
};

Test a = {1, 2}, b = {3, 4};

int main(int argc, char* argv[])
{
	Test array[2] = {a, b};

	return 0;
}
