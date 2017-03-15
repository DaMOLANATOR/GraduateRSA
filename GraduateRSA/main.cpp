#include <iostream>
#include <cstdlib>
#include <ctime>

#include "SeqList.h"

using namespace std;

int main()
{
    SeqList<int> list(10);
    for(int i=0; i<10; i++)
    {
        list.insertElement(i*10);
    }
    list.display();

    for(int i=0; i<list.getLength(); i++)
    {
        cout<<"get "<<i<<" element: "<<list.getElement(i)<<endl;
    }

    srand(time(0));
    int deleteLocation = rand()%list.getLength();
    list.deleteElement(deleteLocation);
    cout<<"deleteLocation: "<<deleteLocation<<endl;
    list.display();

    list.changeElement(rand()%list.getLength(), rand());
    list.display();
}
