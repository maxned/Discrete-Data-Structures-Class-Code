
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	uint64_t x, y, f, k;

	while (cin >> f) {

		k = floor((-1 + sqrt(1 + 8*f))/2);
		x = (k * (k + 3))/2 - f;
		y = f - (k * (k + 1))/2;
		cout << x << " " << y << endl;
	}

    return 0;
}
