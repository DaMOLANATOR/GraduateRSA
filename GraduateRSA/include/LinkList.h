#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

using namespace std;
template<typename DataType>
class LinkList;


template<typename DataType>
class LinkNode
{
    LinkNode()
    {
        next = NULL;
    }
    LinkNode(DataType item, LinkNode<DataType>* nextNode = NULL)
    {
        data = item;
        next = nextNode;
    }
    friend LinkList<DataType>;
    DataType data;
    LinkNode<DataType>* next;
};



template<typename DataType>
class LinkList
{
public:
    LinkList()
    :   length(0)
    {
        head = new LinkNode<DataType>();
        cout<<"\t a new LinkList \n";
    }

    ~LinkList()
    {
        destroy();
    }

    LinkList<DataType>* append(DataType newData);
    void destroy();

    int getLength()
    {
        return length;
    }
    void display()
    {
        cout<<"******** display a LinkList *********\n";
        LinkNode<DataType>* p = head;
        for(p=p->next; p!=NULL; p=p->next)
        {
            cout<<p->data<<" ";
        }
        cout<<"\n********* display end ******"<<endl;
    }

private:
    LinkNode<DataType>* head;
    int length;
};





template<typename DataType>
LinkList<DataType>* LinkList<DataType>::append(DataType newData)
{
    LinkNode<DataType>* p = head;
    for(; p->next!=NULL; p=p->next);
    p->next= new LinkNode<DataType>(newData);
    length++;

    return this;
}

template<typename DataType>
void LinkList<DataType>::destroy()
{
    LinkNode<DataType> *p, *q;
    p = q = head;
    for(p=p->next; p!=NULL; p=p->next)
    {
        q = p;
        delete q;
        cout<<"delete a node "<<endl;
    }
    delete head;
}




#endif // LINKLIST_H_INCLUDED
