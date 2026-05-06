//////////////////////////////////////////////////////////////
// Generelised Data Structure Library
//////////////////////////////////////////////////////////////

/*
-----------------------------------------------------------------------------------------------------
|    Type            |  Name of class for node     |    Name of class for Functionality  |          |
|--------------------|-----------------------------|-------------------------------------|-----------
|  Singly Lineaar    |      SinglyLLLnode          |          SinglyLLL                  |   Done   |
|  Singly Circular   |      SinglyCLLnode          |          SinglyCLL                  |   Done   |
|  Doubly Linear     |      DoublyLLLnode          |          DoublyLLL                  |   Done   |
|  Doubly Circular   |      DoublyCLLnode          |          DoublyCLL                  |   Done   |
|  Stack             |       Stacknode             |          Stack                      |   Done   |
|  Queue             |       Queuenode             |          Queue                      |   Done   |
-----------------------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////
//      Singly Linear Linked List using generic approach
///////////////////////////////////////////////////////////////////////

#pragma pack (1)
template <class T>
class SinglyLLLnode
{
    public: 
        T data;
        SinglyLLLnode<T> * next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyLLL
{
    private:        
        SinglyLLLnode<T> * first;
        int iCount;

    public:
        SinglyLLL();

        void InsertFirst(T);     
        void InsertLast(T);       
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T, int);
        void DeleteAtPos(int);
};

template <class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"Object of SinglyLL gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     InsertFirst
//  Inputt :            Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Diksha Kadu Vispute
//  Date :              06/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertFirst(T no)   
{
    SinglyLLLnode<T> * newn = NULL;
    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     InsertLast
//  Inputt :            Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if(this->iCount == 0)   
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

    this->iCount++;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     DeleteFirst
//  Inputt :            nothing
//  Output :            Nothing
//  Description :       Used to delete node at first position
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)       
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;
        delete temp;
    }

    this->iCount--;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     DeleteLast
//  Inputt :            nothing
//  Output :            Nothing
//  Description :       Used to delete node at last position
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)    
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;   
    }

    this->iCount--;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     Display
//  Inputt :            nothing
//  Output :            Nothing
//  Description :       Used to display elements in linked list
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: Display()
{
    SinglyLLLnode<T> * temp = NULL;

    temp = this->first;

    int iCnt = 0;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)       
    {
        cout<<" | " << temp->data << " | -> ";
        temp = temp->next;
    }

    cout<< "NULL\n";
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     Count
//  Inputt :            nothing
//  Output :            Nothing
//  Description :       Used to count elements in linked list
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLLL<T> :: Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     InsertAtPos
//  Inputt :            data of node, position of node
//  Output :            Nothing
//  Description :       Used to insert element at given position
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertAtPos(T no, int pos)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    int iCnt = 0;

    if((pos < 1 ) || (pos > this->iCount+1))
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }

    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);
        
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     DeleteAtPos
//  Inputt :            position of node
//  Output :            Nothing
//  Description :       Used to delete element at given position
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * target = NULL;

    int iCnt = 0;

    if((pos < 1 ) || (pos > this->iCount))
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }

    else if(pos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;

        delete target;

        this->iCount--;
    }
}

///////////////////////////////////////////////////////////////////////
//      Doubly Linear Linked List using generic approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode * next;
        DoublyLLLnode * prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template <class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> * first;
        int iCount;

    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template <class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Linked list gets created\n";

    this->first = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     InsertFirst
//  Inputt :            Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    DoublyLLLnode<T> * newn = NULL;
    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }

    this->iCount++;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     InsertLast
//  Inputt :            Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    DoublyLLLnode<T> * temp = NULL;
    DoublyLLLnode<T> * newn = NULL;
    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }

    this->iCount++;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     InsertAtPos
//  Inputt :            data of node, position of node
//  Output :            Nothing
//  Description :       Used to insert element at given position
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: InsertAtPos(T no,int pos)
{
    DoublyLLLnode<T> * temp = NULL;
    DoublyLLLnode<T> * newn = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount+1))
    {
        printf("Invalid position\n");
        return;
    }
    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        newn->prev = temp;
        temp->next = newn;

        this->iCount++;
    }
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     DeleteFirst
//  Inputt :            nothing
//  Output :            Nothing
//  Description :       Used to delete node at first position
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(this->first == NULL)                 
    {
        return;
    }
    else if(this->first->next == NULL)      
    {
        delete this->first;
        this->first = NULL;
    }
    else                                    
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }

    this->iCount--;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     DeleteLast
//  Inputt :            nothing
//  Output :            Nothing
//  Description :       Used to delete node at last position
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: DeleteLast()
{
    DoublyLLLnode<T> * temp = NULL;

    if(this->first == NULL)                 
    {
        return;
    }
    else if(this->first->next == NULL)      
    {
        delete this->first;
        this->first = NULL;
    }
    else                                    
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     DeleteAtPos
//  Inputt :            position of node
//  Output :            Nothing
//  Description :       Used to delete element at given position
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    DoublyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount))
    {
        printf("Invalid position\n");
        return;
    }
    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     Display
//  Inputt :            nothing
//  Output :            Nothing
//  Description :       Used to display elements in linked list
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLnode<T> * temp = NULL;
    temp = this->first;

    cout<<"\nNULL<=>";

    while(temp != NULL)
    {
        cout<<" | "<<temp->data<<" |<=>";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     Count
//  Inputt :            nothing
//  Output :            Nothing
//  Description :       Used to count elements in linked list
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////
//      Singly Circular Linked List using generic approach
///////////////////////////////////////////////////////////////////////

template <class T>
struct SinglyCLLnode
{
    T data;
    struct SinglyCLLnode<T> *next;
};

template <class T>
class SinglyCLL
{
    private:
        struct SinglyCLLnode<T> * first;
        struct SinglyCLLnode<T> * last;
        int iCount;

    public:
        SinglyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"Inside constructor of SinglyCLL\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     Insertfirst
//  Inputt :            Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)   // if(iCount == 0)
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;

        last->next = first;
    }

    iCount++;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     InsertLast
//  Inputt :            Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)   // if(iCount == 0)
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;

        last->next = first;
    }

    iCount++;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     DeleteFirst
//  Inputt :            nothing
//  Output :            Nothing
//  Description :       Used to delete node at first position
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last->next;

        last->next = first;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     DeleteLast
//  Inputt :            nothing
//  Output :            Nothing
//  Description :       Used to delete node at last position
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    struct SinglyCLLnode<T> * temp = NULL;

    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        temp = first;

        while(temp -> next != last)
        {
            temp = temp -> next;
        }

        delete last;
        last = temp;

        last->next = first;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     Display
//  Inputt :            nothing
//  Output :            Nothing
//  Description :       Used to display elements in linked list
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    struct SinglyCLLnode<T> * temp = first;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    } while (temp != last ->next);
    
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     Count
//  Inputt :            nothing
//  Output :            Nothing
//  Description :       Used to count elements in linked list
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     DeleteAtPos
//  Inputt :            position of node
//  Output :            Nothing
//  Description :       Used to delete element at given position
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * target = NULL;
    
    int i = 0;
    
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp->next = target->next;
        delete target;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     InsertAtPos
//  Inputt :            Data of node, position of node
//  Output :            Nothing
//  Description :       Used to insert element at given position
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * newn = NULL;

    int i = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct SinglyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;

        temp = first;

        for(i = 1; i < pos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next = newn;

        iCount++;
    }
}

///////////////////////////////////////////////////////////////////////
//      Doubly Circular Linked List using generic approach
///////////////////////////////////////////////////////////////////////

template <class T>
struct DoublyCLLnode
{
    T data;
    struct DoublyCLLnode<T> * next;
    struct DoublyCLLnode<T> * prev;
};

template<class T>
class DoublyCLL
{
    private:
        struct DoublyCLLnode<T> * first;
        struct DoublyCLLnode<T> * last;
        int iCount;

    public:
        DoublyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T no, int pos);
        void DeleteAtPos(int pos);
};

template <class T>
DoublyCLL<T> :: DoublyCLL()
{
    cout<<"Inside Constructor of DoublyCLL\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     Insertfirst
//  Inputt :            Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    struct DoublyCLLnode<T> * newn = NULL;
    newn = new struct DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    
    last->next = first;
    first->prev = last;

    iCount++;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     InsertLast
//  Inputt :            Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    struct DoublyCLLnode<T> * newn = NULL;
    newn = new struct DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }
    
    last->next = first;
    first->prev = last;

    iCount++;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     DeleteFirst
//  Inputt :            nothing
//  Output :            Nothing
//  Description :       Used to delete node at first position
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: DeleteFirst()
{
    if(iCount == 0)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;

        last->next = first;
        first->prev = last;
    }

    iCount--;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     DeleteLast
//  Inputt :            nothing
//  Output :            Nothing
//  Description :       Used to delete node at last position
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: DeleteLast()
{
    if(iCount == 0)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete last->next;

        last->next = first;
        first->prev = last;
    }

    iCount--;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     Display
//  Inputt :            nothing
//  Output :            Nothing
//  Description :       Used to display elements in linked list
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: Display()
{
    struct DoublyCLLnode<T> * temp = NULL;
    temp = first;

    cout<<"<=>";

    do
    {
        cout<<" | "<<temp->data<<" |<=>";
        temp = temp->next;

    } while (temp != last->next);

    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     Count
//  Inputt :            nothing
//  Output :            Nothing
//  Description :       Used to count elements in linked list
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCLL<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     InsertAtPos
//  Inputt :            data of node, position of node
//  Output :            Nothing
//  Description :       Used to insert element at given position
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: InsertAtPos(T no, int pos)
{
    struct DoublyCLLnode<T> * temp = NULL;
    struct DoublyCLLnode<T> * newn = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        temp = first;
        newn = new struct DoublyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->next->prev = newn;
        
        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     DeleteAtPos
//  Inputt :            position of node
//  Output :            Nothing
//  Description :       Used to delete element at given position
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    struct DoublyCLLnode<T> * temp = NULL;
    struct DoublyCLLnode<T> * target = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;

        temp->next->prev = temp;
        delete target;

        iCount--;
    }  
}

///////////////////////////////////////////////////////////////////////
//      Stack using generic approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T> * next;

        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class Stack
{
    private:
        Stacknode<T> * first;
        int iCount;

    public:
        Stack();

        void push(T);          
        T pop();                
        T peep();
        void Display();
        int Count();
};

template<class T>
Stack<T>:: Stack()
{
    cout<<"Stack gets created successfully\n";

    this->first = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     push
//  Inputt :            data of node
//  Output :            Nothing
//  Description :       Used to insert an element in stack
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T> :: push(T no)           
{
    Stacknode<T> * newn = NULL;
    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     pop
//  Inputt :            nothing
//  Output :            Nothing
//  Description :       Used to remove an element from stack
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template<class T>
T Stack<T> :: pop()
{
    T Value = 0;
    Stacknode<T> * temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;
    return Value;
}   

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     peep
//  Inputt :            nothing
//  Output :            Nothing
//  Description :       Used to display top element in stack
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template<class T>
T Stack<T> :: peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;

    return Value;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     Display
//  Inputt :            Nothing
//  Output :            Nothing
//  Description :       Used to display elements in stack 
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T> :: Display()
{
    Stacknode<T> * temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     Count
//  Inputt :            nNthing
//  Output :            Nothing
//  Description :       Used to count elements in stack 
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template<class T>
int Stack<T> :: Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////
//      Queue using generic approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T> * next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class Queue
{
    private:
        Queuenode<T> * first;
        Queuenode<T> * last;
        int iCount;

    public:
        Queue();

        void enqueue(T);           
        T dequeue();               
        void Display();
        int Count();
};

template <class T>
Queue<T> :: Queue()
{
    cout<<"Queue gets created successfully\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     enqueue 
//  Inputt :            data of node
//  Output :            Nothing
//  Description :       Used to insert an element in queue 
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void Queue<T> :: enqueue(T no)           
{
    Queuenode<T> * newn = NULL;
    Queuenode<T> * temp = this->first;

    newn = new Queuenode<T>(no);

    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = this->last->next;
    }

    this->iCount++;
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     dequeue 
//  Inputt :            nothing
//  Output :            Nothing
//  Description :       Used to remove an element from queue 
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
T Queue<T> :: dequeue()
{
    T Value = 0;
    Queuenode<T> * temp = this->first;

    if((this->first == NULL) && (this->last == NULL))
    {
        cout<<"Queue is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;
    return Value;
}   

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     Display 
//  Inputt :            Nothing
//  Output :            Nothing
//  Description :       Used to Display elements in queue 
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
void Queue<T> :: Display()
{
    Queuenode<T> * temp = this->first;

    if((this->first == NULL) && (this->last == NULL))
    {
        cout<<"Queue is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }

    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////
//      
//  Function Name :     Count 
//  Inputt :            Nothing
//  Output :            Nothing
//  Description :       Used to count elements in queue 
//  Author :            Diksha Kadu Vispute
//  Date :              10/01/2026
//
///////////////////////////////////////////////////////////////////////

template <class T>
int Queue<T> :: Count()
{
    return this->iCount;
}

/////////////////////////////////    End of Library    ///////////////////////////////////////

int main()
{
    SinglyLLL<int> *obj = new SinglyLLL<int>();
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();

    iRet = obj->Count();
    cout<<"Numbers of nodes are : "<<iRet<<"\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);

    obj->Display();

    iRet = obj->Count();
    cout<<"Numbers of nodes are : "<<iRet<<"\n";

    obj->DeleteFirst();

    obj->Display();

    iRet = obj->Count();
    cout<<"Numbers of nodes are : "<<iRet<<"\n";

    obj->DeleteLast();

    obj->Display();

    iRet = obj->Count();
    cout<<"Numbers of nodes are : "<<iRet<<"\n";

    obj->InsertAtPos(105,4);

    obj->Display();

    iRet = obj->Count();
    cout<<"Numbers of nodes are : "<<iRet<<"\n";

    obj->DeleteAtPos(4);

    obj->Display();

    iRet = obj->Count();
    cout<<"Numbers of nodes are : "<<iRet<<"\n";

    delete obj;

    ///////////////////////////////////////////////////////////////////////////

    DoublyLLL<char> *dobj = new DoublyLLL<char>();

    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');

    dobj->Display();

    cout<<"Number of elements are : "<< dobj ->Count()<<"\n";

    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');

    dobj->Display();

    cout<<"Number of elements are : "<< dobj ->Count()<<"\n";

    dobj->DeleteFirst();

    dobj->Display();

    cout<<"Number of elements are : "<< dobj ->Count()<<"\n";

    dobj->DeleteLast();

    dobj->Display();

    cout<<"Number of elements are : "<< dobj ->Count()<<"\n";

    dobj->InsertAtPos('$',4);

    dobj->Display();

    cout<<"Number of elements are : "<< dobj ->Count()<<"\n";

    dobj->DeleteAtPos(4);

    dobj->Display();

    cout<<"Number of elements are : "<< dobj ->Count()<<"\n";

    delete dobj;

    ///////////////////////////////////////////////////////////////////////////

    SinglyCLL<int> *scobj  = new SinglyCLL<int>();

    scobj->InsertFirst(51);
    scobj->InsertFirst(21);
    scobj->InsertFirst(11);
    
    scobj->InsertLast(101);
    scobj->InsertLast(111);
    scobj->InsertLast(121);
    
    scobj->InsertAtPos(105,5);

    scobj->Display();

    cout<<"Number of elements are : "<<scobj->Count()<<"\n";

    scobj->DeleteAtPos(5);

    scobj->Display();

    cout<<"Number of elements are : "<<scobj->Count()<<"\n";

    scobj->DeleteFirst();

    scobj->Display();

    cout<<"Number of elements are : "<<scobj->Count()<<"\n";

    scobj->DeleteLast();

    scobj->Display();

    cout<<"Number of elements are : "<<scobj->Count()<<"\n";

    ///////////////////////////////////////////////////////////////////////////

    DoublyCLL<int> * dcobj = new DoublyCLL<int>();

    dcobj->InsertFirst(51);
    dcobj->InsertFirst(21);
    dcobj->InsertFirst(11);

    dcobj->Display();

    cout<<"Number of nodes are : "<<dcobj->Count()<<"\n";

    dcobj->InsertLast(101);
    dcobj->InsertLast(111);
    dcobj->InsertLast(121);

    dcobj->Display();

    cout<<"Number of nodes are : "<<dcobj->Count()<<"\n";

    dcobj->DeleteFirst();

    dcobj->Display();

    cout<<"Number of nodes are : "<<dcobj->Count()<<"\n";

    dcobj->DeleteLast();

    dcobj->Display();

    cout<<"Number of nodes are : "<<dcobj->Count()<<"\n";

    dcobj->InsertAtPos(105,4);

    dcobj->Display();

    cout<<"Number of nodes are : "<<dcobj->Count()<<"\n";

    dcobj->DeleteAtPos(4);

    dcobj->Display();

    cout<<"Number of nodes are : "<<dcobj->Count()<<"\n";

    ///////////////////////////////////////////////////////////////////////////////////

    Stack<char> * sobj = new Stack<char>();

    sobj->push('a');
    sobj->push('b');
    sobj->push('c');
    sobj->push('d');

    sobj->Display();
    cout<<"number of elements in stack are : "<<sobj->Count()<<"\n";

    cout<<"Return Value of peep is : "<<sobj->peep()<<"\n";

    sobj->Display();
    cout<<"number of elements in stack are : "<<sobj->Count()<<"\n";

    cout<<"popped element is : "<<sobj->pop()<<"\n";

    sobj->Display();
    cout<<"number of elements in stack are : "<<sobj->Count()<<"\n";

    cout<<"popped element is : "<<sobj->pop()<<"\n";

    sobj->Display();
    cout<<"number of elements in stack are : "<<sobj->Count()<<"\n";

    sobj->push('e');

    sobj->Display();
    cout<<"number of elements in stack are : "<<sobj->Count()<<"\n";

    delete sobj;

    ////////////////////////////////////////////////////////////////////////////

    Queue<double> * qobj = new Queue<double>();

    qobj->enqueue(11.56789);
    qobj->enqueue(21.56789);
    qobj->enqueue(51.56789);
    qobj->enqueue(101.56789);

    qobj->Display();
    cout<<"number of elements in queue are : "<<qobj->Count()<<"\n";

    cout<<"removed element is : "<<qobj->dequeue()<<"\n";

    qobj->Display();
    cout<<"number of elements in queue are : "<<qobj->Count()<<"\n";

    cout<<"removed element is : "<<qobj->dequeue()<<"\n";

    qobj->Display();
    cout<<"number of elements in queue are : "<<qobj->Count()<<"\n";

    qobj->enqueue(121.56789);

    qobj->Display();
    cout<<"number of elements in queue are : "<<qobj->Count()<<"\n";

    delete qobj;

    return 0;
}