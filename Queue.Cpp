#include<iostream>
using namespace std;

const int EMPTY_QUEUE= -1; 
const int ELEMENT_NOT_FOUND=-2;


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
        cout << "Queue is already empty.." << endl;
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
        cout << "Queue is already empty.." << endl;
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

int main()
{
    QueueImplementation QI;
    int count = QI.CountNodes();

    QI.XEnqueue(300);
    QI.XEnqueue(200);
    QI.XEnqueue(150);
    QI.XEnqueue(100);
    QI.XEnqueue(400);
    QI.XEnqueue(500);
    QI.XEnqueue(600);

    count = QI.CountNodes();
    cout << "Number of nodes: " << count << endl;
    QI.DisplayQueue();

    cout << endl;

    QI.XDequeue();
    QI.XDequeue();

    count = QI.CountNodes();
    cout << "Number of nodes: " << count << endl;
    QI.DisplayQueue();

    int inO;
    inO=QI.XGetFirstElement();
    cout<<endl<<"FIRST NUMBER IS:"<<inO;

    return 0;
}
