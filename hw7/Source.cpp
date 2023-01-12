#include <iostream>
#include <exception>
#include "IntegerArray.h"
using namespace std;

int main ()
{
	int containerLength = -1;

	IntegerArray badRange(containerLength);

	containerLength = 5;

	IntegerArray container(containerLength);

	container.fill(0);

	container.getData();
	
	container.getElem(7);

	container.getElem(4);


	return 0;
}