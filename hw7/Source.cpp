#include <iostream>
#include <exception>
#include "IntegerArray.h"
using namespace std;

int main ()
{

	int containerLength = -1;

	cout << "Check length: " << endl;
	IntegerArray badRange(containerLength);


	containerLength = 5;

	IntegerArray container(containerLength);

	container.fill(0);


	cout << endl << "Check removal: " << endl;

	container.removeElem(-5);

	container.removeElem(2);

	container.getData();

	IntegerArray buff(0);


	cout << endl << "Check search: " << endl;

	buff.searchElem(3);

	buff.searchElem(2);


	return 0;
}