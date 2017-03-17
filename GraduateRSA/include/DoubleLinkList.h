#ifndef DOUBLELINKLIST_H_INCLUDED
#define DOUBLELINKLIST_H_INCLUDED


using namespace std;
template<typename DataType>
class DoubleLinkList;


template<typename DataType>
class DoubleLinkNode
{
    DoubleLinkNode(DataType _data, DoubleLinkNode<DataType>* _prior=NULL, DoubleLinkNode<DataType>* _next = NULL )
    :   data(_data),
        next(_next),
        prior(_prior)
    {}

    DoubleLinkNode()
    :
        prior(NULL),
        next(NULL)
    {}


    friend DoubleLinkList<DataType>;
    DataType data;
    DoubleLinkNode<DataType>* next;
    DoubleLinkNode<DataType>* prior;
};



template<typename DataType>
class DoubleLinkList
{
public:
    DoubleLinkList()
    :   length(0)
    {
        head = new DoubleLinkNode<DataType>();
     //   cout<<"\t a new LinkList \n";
    }

    ~DoubleLinkList()
    {
        destroy();
    }

    DoubleLinkList<DataType>& append(DataType newData);
    DoubleLinkList<DataType>& prepend(DataType newData);
    // insert a node after the location node
    // location is between [0,length]
    bool insert(int location, DataType newData);
   // bool remove(int location);

   // int indexOf(DataType data) const;
   // DataType get(int location) const;
  //  bool set(int location, DataType newData);


    void destroy();

    int getLength() const
    {
        return length;
    }
    void display() const
    {
        cout<<"******** display a DoubleLinkList *********\n";
        cout<<"\t length: "<<length<<endl;
        DoubleLinkNode<DataType>* p = head;
        for(p=p->next; p!=NULL; p=p->next)
        {
            cout<<p->data<<" ";
        }
        cout<<"\n********* display end ******"<<endl;
    }

private:
    DoubleLinkNode<DataType>* operator[](int location) const;

    DoubleLinkNode<DataType>* head;
    int length;
};

template<typename DataType>
DoubleLinkNode<DataType>* DoubleLinkList<DataType>::operator[](int location) const
{
    if(location<0||location>=length) return NULL;
    DoubleLinkNode<DataType> *p = head->next;
    for(int i=0; i<location; i++)
    {
        p=p->next;
    }
    return p;
}

template<typename DataType>
DoubleLinkList<DataType>& DoubleLinkList<DataType>::append(DataType newData)
{
    insert(length, newData);
    return *this;
}

template<typename DataType>
DoubleLinkList<DataType>& DoubleLinkList<DataType>::prepend(DataType newData)
{
    insert(0,newData);
    return *this;
}

template<typename DataType>
bool DoubleLinkList<DataType>::insert(int location, DataType newData)
{
    if( location<0 || location>length)
    {
        cerr<<"bad location!"<<endl;
        return false;
    }

    DoubleLinkNode<DataType> *p = head;
    for(int i=0; i<location; i++)
    {
        p = p->next;
    }
    DoubleLinkNode<DataType> *q = p->next;
    p->next = new DoubleLinkNode<DataType>(newData,p,q);
    length++;
    return true;
}

template<typename DataType>
void DoubleLinkList<DataType>::destroy()
{
    DoubleLinkNode<DataType> *p, *q;
    p =  head;
    for(p=p->next; p!=NULL; p=p->next)
    {
        q = p;
        delete q;
//        cout<<"delete a node "<<endl;
    }
    delete head;
}


#endif // DOUBLELINKLIST_H_INCLUDED
