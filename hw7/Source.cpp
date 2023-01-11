#include <iostream>
#include <exception>
#include "IntegerArray.h"
using namespace std;

int main ()
{
	int containerLength = -1;


	try
	{
		IntegerArray* container =  dynamic_cast<IntegerArray*>(container(containerLength));
	}
	catch(const bad_cast& e)
	{
		cout << e.what()<< endl;
	}

	return 0;
}