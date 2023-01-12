#include <iostream>
#include "IntegerArray.h"

IntegerArray::IntegerArray(int length) : _IALength{length}
{
    try
    {
        _IAdata = new int[length];
    }
    catch(const bad_array_new_length& e)
    {
        cout << "Exception: " << e.what()<< endl;
    }
    
}



int& IntegerArray::getElem(int index)
{
    try
    {
        if (index >= _IALength)
        {
            throw range_error("bad_range");
        }
        else
        {
            cout << _IAdata[index] << endl;
            return _IAdata[index];
        }
    }
    catch (const range_error& e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    
}

void IntegerArray::fill(int start)
{
    for (int i = 0; i < _IALength; i++)
    {
        _IAdata[i] = start++;
    }
}

void IntegerArray::getData()
{
    for (int i = 0; i < _IALength; i++)
    {
        cout << _IAdata[i] << endl;
    }
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
    {
        return;
    }

    if (newLength <= 0)
    {
        clear();
        return;
    }

    int* data{ new int[newLength] };

    int elementsToCopy = 0;

    if (_IALength > 0)
    {
        if (newLength > _IALength)
        {
            elementsToCopy = newLength;
        }
        else
        {
            elementsToCopy = _IALength;
        }
    };

        for (int index{ 0 }; index < elementsToCopy; ++index)
        {
            data[index] = _IAdata[index];
        }
 

    delete[] _IAdata;

    _IAdata = data;
    _IALength = newLength;
}

void IntegerArray::insertElem(int elem, int index)
{
    try
    {
        if (index >= _IALength)
        {
            throw range_error("range_error");
        }
        else
        {
            _IAdata[index] = elem;
            return;
        }
    }
    catch (const range_error& e)
    {
        cout << "Exception: " << e.what() << endl;
    }
    
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

    try
    {
        if (index < 0 || index >= _IALength)
        {
            throw range_error("bad_range");
        }
    }
    catch (const range_error& e)
    {
        cout << "Exception: " << e.what() << endl;
        return;
    }

    if (_IALength == 1)
    {
        clear();
        return;
    }

   
    int* data = new int[_IALength - 1];


    for (int before = 0; before < index; ++before)
    {
        data[before] = _IAdata[before];
    }

    for (int after = index + 1; after < _IALength; ++after)
    {
        data[after - 1] = _IAdata[after];
    }

    delete[] _IAdata;
    _IAdata = data;
    --_IALength;
}

void IntegerArray::searchElem(int elem)
{
    int elemIndex;
    for (elemIndex = 0; elemIndex < _IALength; elemIndex++)
    {
        if (_IAdata[elemIndex] == elem)
        {
            cout << "Element " << elem << " found at index: " << elemIndex << endl;
            return;
        }
    }

    cout << "Element " << elem << " is not present in the array" << endl;
}

