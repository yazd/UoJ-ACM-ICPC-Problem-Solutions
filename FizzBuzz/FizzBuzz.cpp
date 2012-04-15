#include <iostream>
#include <fstream>

using namespace std;

int main() {

	ifstream in;
	in.open("FizzBuzz.in");

	if (!in) {
		cout << "Error: can't read file!\n";
		return 1;
	}

	unsigned int count;
	in >> count;

	for(unsigned int i = 1; i <= count; i++) {
		
		if (i % 3 == 0)
			if (i % 5 == 0)
				cout << "FizzBuzz\n";
			else
				cout << "Fizz\n";
		else if (i % 5 == 0)
			cout << "Buzz\n";
		else
			cout << i << "\n";
		
	}

	return 0;

}
