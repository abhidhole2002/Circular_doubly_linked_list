#include<iostream>
using namespace std;

class dlist
{
    int data;
    dlist* head;
    dlist* next;
    dlist* prev;

    public:

    dlist(int data)
    {
        this->data = data;
        this->head = NULL;
        this->next = NULL;
        this->prev = NULL;   
    }

    void add_tail(int x)
    {
        dlist* newn = new dlist(x);
        newn->next = NULL;
        newn->prev = NULL;

        if(head == NULL)
        {
            head = newn;
            newn->next = head;
            newn->prev = head;
        }

        else
        {
            dlist* temp;
            for(temp = head;temp->next!=head;temp = temp->next){}
            newn->next = head;
            newn->prev = temp;
            temp->next = newn;
        }
    }

    void delete_head()
    {
        if(head->next == head)
        {
            delete head;
            head = NULL;
        }

        else
        {
            dlist* temp = head;
            dlist* ptr = head;
            for(;temp->next!=head;temp = temp->next)
            {}

            head = head->next;
            temp->next = head;
            head->prev = temp;

            delete ptr ;
            ptr = NULL;
        }
    }

    void delete_tail()
    {
        if(head->next==head)
        {
            delete head;
            head = NULL;
        }

        else
        {
            dlist *temp = head;

            for(;temp->next->next!=head;temp=temp->next){}

            dlist* del = temp->next;
            temp->next = head;
            head->prev = temp;

            delete del;
            del = NULL;
        }    
    }

    void print()
    {
        dlist* temp = head;

        do
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        } while (temp!=head);
        
    }
};
 
int main()
{
    dlist list(0);
    list.add_tail(10);
    list.add_tail(11);
    list.add_tail(12);
    list.add_tail(13);
    list.add_tail(14);

    list.print();
    cout<<endl;

    list.delete_head();
    list.print();

    cout<<endl;

    list.delete_tail();
    list.print();
 
}