/**
 * time test
 *
 * @date 20091126
 */

#include <iostream>
#include <ctime>

int main(int argc, char* argv[])
{
	time_t _time;
	time(&_time);
	std::cout << _time << std::endl;

	struct tm* _tm = localtime(&_time);
	std::cout << _tm->tm_year << '-' << _tm->tm_mon << '-' << _tm->tm_mday
		<< ' ' << _tm->tm_hour << ':' << _tm->tm_min << ':' << _tm->tm_sec << std::endl;
	_tm->tm_year = 70;
	_tm->tm_mon = 0;
	_tm->tm_mday = 1;
	_tm->tm_hour = 8;
	_tm->tm_min = 0;
	_tm->tm_sec = 0;
	std::cout << mktime(_tm) << std::endl;

	return 0;
}
