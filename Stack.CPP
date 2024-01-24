//Implementing stack using linked list .
#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE; 


class StackImplementation
{
    private:
        PNODE Head;
        int count;

    public:
        StackImplementation();
        int CountNodes();
        void DisplayStack();
        void Push(int iNO);
        void Pop();
        int Peak();       

};
StackImplementation::StackImplementation()
{
    Head=NULL;
    count=0;
}
int StackImplementation::Peak()
{
    PNODE temp= Head;
    int last_Element = temp->data;
    return last_Element;
}


int StackImplementation::CountNodes()
{
    return count;
}

void StackImplementation::DisplayStack()
{
    PNODE temp = Head;
    while (temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|";
        temp=temp->next;
    }
    cout<<"NULL";
}
void StackImplementation::Push(int iNO)
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

void StackImplementation::Pop()
{
    if(Head==NULL)
    {
        cout<<"Stack is already empty.."<<endl;
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


int main()
{
    StackImplementation SI;
    int count=SI.CountNodes();
    SI.Push(50);
    SI.Push(40);
    SI.Push(30);
    SI.Push(20);
    count=SI.CountNodes();
    SI.DisplayStack();
    cout<<endl;
    cout<<"Number of Elements in Stack :"<<count<<endl;
    
    cout<<endl;
    SI.Pop();
    SI.Pop();
    count=SI.CountNodes();
    cout<<"Number of Elements in Stack :"<<count<<endl;
    int last_Element=SI.Peak();
    
    cout<<"Top or Peadk element from the stack is "<<last_Element<<endl;
    SI.DisplayStack();
    return 0;

}