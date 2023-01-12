#pragma once
#include <exception>
using namespace std;

class IntegerArray
{
private:
	int _IALength;
	int * _IAdata;
public:

	IntegerArray() = default;
	~IntegerArray()
	{
		delete[] _IAdata;
	}
	IntegerArray(int length);

	void copy(int array[]);
	int& getElem(int index);
	void fill(int start);
	void getData();
	void clear();
	void setNewLength(int newLength);
	void insertElem(int elem, int index);
	void addFirstElem(int elem);
	void addLastElem(int elem);
	void removeElem(int index);
	



};