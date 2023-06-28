#include<iostream>
using namespace std;

class dlist
{
    int data;
    dlist* head = NULL;
    dlist* next = NULL;
    dlist* prev = NULL;

    public:

    void add_tail(int x)
    {
        dlist* newn = new dlist();
        newn->data = x;
        newn->next = NULL;
        newn->prev = NULL;

        if(head == NULL)
        {
            head = newn;
            newn->prev = head;
            newn->next = head;
        }

        else
        {
            dlist* temp = head;
            for(;temp->next!=head;temp = temp->next){}
            newn->next = head;
            newn->prev = temp;
            temp->next = newn;
        }
    }

    int search(int x)
    {
        dlist* temp = head;

        do 
        {
            if(temp->data == x)
            {
                return 1;
            }
            temp = temp->next;
        }while(temp!=head);

        return -1;
    }

    void print()
    {
        dlist* temp = head;
        do 
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp!=head);
    }
};

 
int main()
{
    dlist list;

    list.add_tail(10);
    list.add_tail(11);
    list.add_tail(12);
    list.add_tail(13);
    list.print();
    cout<<endl;
    cout<<list.search(14);
 
 
 
 
 
}