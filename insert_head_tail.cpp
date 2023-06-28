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

    void add_head(int x)
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
            head = newn;
        }
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

    void print()
    {
        dlist* temp = head;

        do 
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        while(temp!=head);
    }

};
 
int main()
{
    dlist list(0);

    list.add_head(10);
    list.add_head(11);
    list.add_head(12);
    list.add_head(13);
    list.print();

    cout<<endl;

    dlist list1(0);

    list1.add_tail(10);
    list1.add_tail(11);
    list1.add_tail(12);
    list1.add_tail(13);
    list1.print();

}