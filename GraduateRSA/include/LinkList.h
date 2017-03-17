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
     //   cout<<"\t a new LinkList \n";
    }

    ~LinkList()
    {
        destroy();
    }

    LinkList<DataType>& append(DataType newData);
    LinkList<DataType>& prepend(DataType newData);
    // insert a node after the location node
    // location is between [0,length]
    bool insert(int location, DataType newData);
    bool remove(int location);

    int indexOf(DataType data) const;
    DataType get(int location) const;
    bool set(int location, DataType newData);


    void destroy();

    int getLength() const
    {
        return length;
    }
    void display() const
    {
        cout<<"******** display a LinkList *********\n";
        cout<<"\t length: "<<length<<endl;
        LinkNode<DataType>* p = head;
        for(p=p->next; p!=NULL; p=p->next)
        {
            cout<<p->data<<" ";
        }
        cout<<"\n********* display end ******"<<endl;
    }

private:
    LinkNode<DataType>* operator[](int location) const;

    LinkNode<DataType>* head;
    int length;
};


template<typename DataType>
LinkNode<DataType>* LinkList<DataType>::operator[](int location) const
{
    if(location<0||location>=length) return NULL;
    LinkNode<DataType> *p = head->next;
    for(int i=0; i<location; i++)
    {
        p=p->next;
    }
    return p;
}



template<typename DataType>
LinkList<DataType>& LinkList<DataType>::append(DataType newData)
{
    insert(length, newData);
    return *this;
}

template<typename DataType>
LinkList<DataType>& LinkList<DataType>::prepend(DataType newData)
{
    insert(0,newData);
    return *this;
}

template<typename DataType>
bool LinkList<DataType>::insert(int location, DataType newData)
{
    if( location<0 || location>length)
    {
        cerr<<"bad location!"<<endl;
        return false;
    }

    LinkNode<DataType> *p = head;
    for(int i=0; i<location; i++)
    {
        p = p->next;
    }
    LinkNode<DataType> *q = p->next;
    p->next = new LinkNode<DataType>(newData,q);
    length++;
    return true;
}


template<typename DataType>
void LinkList<DataType>::destroy()
{
    LinkNode<DataType> *p, *q;
    p =  head;
    for(p=p->next; p!=NULL; p=p->next)
    {
        q = p;
        delete q;
//        cout<<"delete a node "<<endl;
    }
    delete head;
}

template<typename DataType>
int LinkList<DataType>::indexOf(DataType data) const
{
    LinkNode<DataType> *p;
    int index = 0;
    for(p = head->next; p!= NULL; p=p->next)
    {
        if(p->data ==data) return index;
        index++;
    }
    return -1;
}

template<typename DataType>
DataType LinkList<DataType>::get(int location) const
{
    return (*this)[location]->data;
}

template<typename DataType>
bool LinkList<DataType>::set(int location, DataType newData)
{
    LinkNode<DataType> *p = (*this)[location];
    if(p==NULL) return false;
    p->data = newData;
    return true;
}

template<typename DataType>
bool LinkList<DataType>::remove(int location)
{
    if(location<0 || location>=length) return false;
    LinkNode<DataType> *p,*q;
    p = head;
    for(int i=0; i<location; i++)
    {
        p = p->next;
    }
    q = p->next;
    p->next = q->next;
    delete q;
    length--;
    return true;
}

#endif // LINKLIST_H_INCLUDED
