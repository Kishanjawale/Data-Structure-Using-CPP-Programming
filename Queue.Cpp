#include<iostream>
using namespace std;

const int EMPTY_QUEUE= -1; 
const int ELEMENT_NOT_FOUND=-2;
const int QUEUE_IS_NOT_EMPTY=1;

struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE; 

class QueueImplementation
{
    private:
        PNODE Head;
        int count;

    public:
        QueueImplementation();
        int CountNodes();
        void DisplayQueue();
        int  XEnqueue(int iNO);
        int XDequeue();  
        int XGetFirstElement(); 
        int XGetLastElement();
        int XIsEmpty();
};

QueueImplementation::QueueImplementation()
{
    Head = NULL;
    count = 0;
}

int QueueImplementation::CountNodes()
{
    return count;
}

void QueueImplementation::DisplayQueue()
{
    PNODE temp = Head;
    cout << "->";
    while (temp != NULL)
    {
        cout << "|" << temp->data << "|";
        temp = temp->next;
    }
    cout << "->";
}

int QueueImplementation::XEnqueue(int iNO)
{
    PNODE newn = new NODE;
    newn->data = iNO;
    newn->next = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    count++;
}

int QueueImplementation:: XGetFirstElement()
{
    int iFirstElement=0;

    if (Head == NULL)
    {
        return EMPTY_QUEUE;
    }
    else
    {
        iFirstElement=Head->data;
        return iFirstElement;
    }
    return ELEMENT_NOT_FOUND;
} 


int QueueImplementation::XDequeue()
{
    if (Head == NULL)
    {
        return EMPTY_QUEUE;
    }
    else if (Head->next == NULL)
    {
        // Only one element in the queue
        delete Head;
        Head = NULL;
    }
    else
    {
        PNODE temp = Head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    count--;
}



int QueueImplementation::XGetLastElement()
{
    if (Head == NULL)
    {
        return EMPTY_QUEUE;
    }
    else
    {
        PNODE temp = Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        int iLastElement=temp->data;
        return iLastElement;
    }
    return ELEMENT_NOT_FOUND;
}



int QueueImplementation:: XIsEmpty()
{
   if (Head == NULL)
    {
        return EMPTY_QUEUE;
    }    
    return QUEUE_IS_NOT_EMPTY;
} 
