#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE; 
class SinglyLinearLinkedList
{
    private:
        PNODE Head;
        int count;

    public:
        SinglyLinearLinkedList();
        int CountNodes();
        void DisplayLinkedList();
        void InsertAtFirst(int iNO);
        void InsertAtLast (int iNO);
        void InsertAtPos(int iPos,int data);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};
SinglyLinearLinkedList::SinglyLinearLinkedList()
{
    Head=NULL;
    count=0;
}

int SinglyLinearLinkedList::CountNodes()
{
    return count;
}

void SinglyLinearLinkedList::DisplayLinkedList()
{
    PNODE temp = Head;
    while (temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|";
        temp=temp->next;
    }
    cout<<"NULL";
}
void SinglyLinearLinkedList::InsertAtFirst(int iNO)
{
    PNODE newn =NULL;
    newn= new NODE;
    
    newn->data=iNO;
    newn->next=NULL;

    if(Head==NULL)
    {

        Head=newn;
    }
    else
    {
        newn->next=Head;
        Head=newn;
    }
    count++;

    
}

void SinglyLinearLinkedList::InsertAtLast(int iNO)
{
    PNODE newn =NULL;
    newn= new NODE;
    
    newn->data=iNO;
    newn->next=NULL;

    if(Head==NULL)
    {

        Head=newn;
    }
   
    else
    {
        
        PNODE temp = Head;
        while (temp->next != NULL)
        {
            temp= temp->next;
        }
        temp->next =newn;

    }
    count++;
}


void SinglyLinearLinkedList::InsertAtPos(int iPos,int iNO)
{
    
    int iSize=CountNodes();
    
    if(iPos < 1 || iPos > iSize+1)
    {

        cout<<"Invalid Position ...."<<endl;
    }
    else if(iPos==1)
    {
        InsertAtFirst(iNO);
            return;
    }
    else if(iPos == iSize + 1 )
    {
        InsertAtLast(iNO);
        return;
    }
   
    else
    {
        PNODE newn =NULL;
        newn= new NODE;
    
        newn->data=iNO;
        PNODE temp = Head;
        newn->next=NULL;

        
        for(int iCnt=1;iCnt < iPos-1 ;iCnt++)
        {
            temp= temp ->next;
        }   
        newn->next=temp->next;
        temp->next=newn;
    }
    count++;
}
void SinglyLinearLinkedList::DeleteFirst()
{
    if(Head==NULL)
    {
        cout<<"Linked List is already empty.."<<endl;
        return ;
    }
    else
    {
        PNODE temp= Head;
        Head= Head->next;
        delete temp;

    }
    count --;
}

void SinglyLinearLinkedList::DeleteLast()
{
    if(Head==NULL)
    {
        cout<<"Linked List is already empty..";
        return;
    }
    else
    {
        PNODE temp=Head;
        while(temp->next!= NULL)
        {
            temp=temp->next;
        }
        delete(temp->next);
        temp->next=NULL;
    }
    count--;
}

void SinglyLinearLinkedList::DeleteAtPos(int iPos)
{
    int iSize=0;
    iSize=CountNodes();

    if(iPos< 1 || iPos >iSize+1  )
    {
        cout<<"Invalide Position Entered....";
        return;
    }
    else if(iPos==1)
    {
        DeleteFirst();
        return ;
    }
    else if(iPos == iSize+1)
    {
        DeleteLast();
        return;
    }
    else
    {
        PNODE temp=Head;
        for(int i=1;i<iPos-1;i++)
        {   
            temp=temp->next;
        }
        PNODE tempDel=temp->next;
        temp->next=temp->next->next;
        delete(tempDel);
    }
    count--;
}


int main()
{
    SinglyLinearLinkedList SLL;
    SLL.InsertAtFirst(300);
    SLL.InsertAtFirst(200);
    SLL.InsertAtFirst(150);
    SLL.InsertAtFirst(100);
//    SLL.DisplayLinkedList();
    SLL.InsertAtLast(400);
    SLL.InsertAtLast(500);
    SLL.InsertAtLast(600);
    SLL.DisplayLinkedList();
    cout<<endl;

    int count=SLL.CountNodes();
    cout<<"Number of nodes:"<<count<<endl;
    cout<<"New Insert at pos"<<endl;

    SLL.InsertAtPos(3,66666);

    SLL.DisplayLinkedList();
    SLL.DeleteAtPos(3);
    
    SLL.DisplayLinkedList();
    return 0;

}