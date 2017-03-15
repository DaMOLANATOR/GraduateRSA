#ifndef SEQLIST_H_INCLUDED
#define SEQLIST_H_INCLUDED

#include <iostream>
using namespace std;

template<typename DataType>
class SeqList
{
public:
    SeqList(int size=defaultSize)
    {
        if(size>0)
        {
            maxSize = size;
            length = 0;
            elements = new DataType[maxSize];
            for(int i=0; i<maxSize; i++)
            {
                elements[i]  = NULL;
            }
        }
    }

    ~SeqList()
    {
        delete[] elements;
    }

    bool insertElement(DataType data);  // insert the data into the tail
    bool deleteElement(int location);
    DataType getElement(int location);
    bool changeElement(int location , DataType newData);

    int getLength()
    {
        return length;
    }
    void display()
    {
        cout<<"******** display a SeqList *********\n";
        for(int i=0; i<length; i++)
        {
            cout<<elements[i]<<" ";
        }
        cout<<"\n********* display end ******"<<endl;
    }
private:
    static const int defaultSize=10;
    DataType* elements;
    int maxSize;
    int length;
};


template<typename DataType>
bool SeqList<DataType>::insertElement(DataType data)
{
    int currentIndex = length;
    if(length>=maxSize)
    {
        return false;
    }
    else
    {
        elements[currentIndex] = data;
        length++;
        return true;
    }
}


// location is between [0,length-1]
template<typename DataType>
DataType SeqList<DataType>::getElement(int location)
{
    if(location<0 || location>=length)
    {
        cerr<<"invalid argument for getElement function"<<endl;
        return 0;
    }
    return elements[location];
}

// location is between [0,length-1]
template<typename DataType>
bool SeqList<DataType>::deleteElement(int location)
{
    if(location<0 || location>=length)
    {
        return false;
    }
    for(int i=location; i<length; i++)
    {
        elements[i] = elements[i+1];
    }
    length--;
    return true;
}


template<typename DataType>
bool SeqList<DataType>::changeElement(int location,DataType newData)
{
    if(location<0 ||location>=length)
    {
        return false;
    }
    elements[location]  =newData;
    return true;
}



#endif // SEQLIST_H_INCLUDED
