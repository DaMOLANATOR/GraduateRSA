#include <iostream>
#include <cstdlib>
#include <ctime>

#include "SeqList.h"
#include "LinkList.h"

using namespace std;

void SeqListTest()
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

void LinkListTest()
{
    LinkList<int>* list = new LinkList<int>;
    list->append(1)->append(2)->append(3);
    cout<<"length: "<<list->getLength()<<endl;
    list->display();
    delete list;
}


int main()
{
    LinkListTest();
}
