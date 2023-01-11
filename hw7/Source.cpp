#include <iostream>
#include <exception>
#include "IntegerArray.h"
using namespace std;

int main ()
{
	int containerLength = -1;


	try
	{
		IntegerArray container(containerLength);
	}
	catch(const bad_array_new_length& e)
	{
		cout << e.what()<< endl;
	}

	return 0;
}