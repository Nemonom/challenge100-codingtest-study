#include <iostream> 

using namespace std;

int result{ 0 }, mapSize{ 0 }, x{ 0 }, y{ 0 };

void func(const int& size, const int& h, const int& v)
{
	if (h == x && v == y)
	{
		cout << result;
		return;
	}

	if (h <= x && x < h + size && v <= y && y < v + size)
	{
		func(size / 2, h, v);
		func(size / 2, h + size / 2, v);
		func(size / 2, h, v + size / 2);
		func(size / 2, h + size / 2, v + size / 2);
	}
	else
		result += size * size;
};

int main()
{
	cin >> mapSize >> y >> x;

	func(1 << mapSize, 0, 0);

	return 0;
}
