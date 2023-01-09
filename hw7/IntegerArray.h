#pragma once

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
	void clear();
	void setNewLength(int newLength);
	void insertElem(int elem, int index);
	void addFirstElem(int elem);
	void addLastElem(int elem);
	void removeElem(int index);
	



};