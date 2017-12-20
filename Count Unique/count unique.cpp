
#include <iostream>
#include <set>

using namespace std;

int main()
{
	char input[999];
	set<int> numberSet;

	while (cin >> input) {

		for (int i = 0; input[i] != '\0'; i++) {
			numberSet.insert(input[i] - '0');
		}

		cout << numberSet.size() << endl;

		numberSet.clear();
	}

    return 0;
}
