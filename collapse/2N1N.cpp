
#include <iostream>

using namespace std;

int main()
{
	uint64_t x, y, f;

	while (cin >> x && cin >> y) {
		f = ((x + y) * (x + y + 1)) / 2 + y;
		cout << f << endl;
	}

    return 0;
}
