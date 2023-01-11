#include "IntegerArray.h"

IntegerArray::IntegerArray(int length) : _IALength{length}
{
    _IAdata = new int[length];

    /*if (length >= 0)
    {
    }
    else
    {
        throw;
    }*/
}

void IntegerArray::copy(int array[])
{
    int arrSize = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < arrSize; i++)
    {
        _IAdata[i] = array[i];
    }
}

int& IntegerArray::getElem(int index)
{
	return _IAdata[index];
}


void IntegerArray::clear()
{
    delete[] _IAdata;

    _IAdata = nullptr;
    _IALength = 0;
}

void IntegerArray::setNewLength(int newLength)
{
    if (newLength == _IALength)
        return;

    if (newLength <= 0)
    {
        clear();
        return;
    }

    int* data{ new int[newLength] };

    if (_IALength > 0)
    {
        int elementsToCopy{ (newLength > _IALength) ? _IALength : newLength };

        for (int index{ 0 }; index < elementsToCopy; ++index)
        {
            data[index] = _IAdata[index];
        }
    }

    delete[] _IAdata;

    _IAdata = data;
    _IALength = newLength;
}

void IntegerArray::insertElem(int elem, int index)
{
    _IAdata[index] = elem;
}

void IntegerArray::addFirstElem(int elem)
{
    int* bufferData = new int[_IALength+1];

    bufferData[0] = elem;

    for (int i = 1; i <= _IALength; i++)
    {
        bufferData[i] = _IAdata[i - 1];
    }

    delete[] _IAdata;
    _IAdata = bufferData;
    _IALength++;
}

void IntegerArray::addLastElem(int elem)
{
    int* bufferData = new int[_IALength + 1];

    bufferData[_IALength] = elem;

    for (int i = 0; i < _IALength; i++)
    {
        bufferData[i] = _IAdata[i];
    }

    delete[] _IAdata;
    _IAdata = bufferData;
    _IALength++;
}

void IntegerArray::removeElem(int index)
{
    _IAdata[index] = 0; //err
}

