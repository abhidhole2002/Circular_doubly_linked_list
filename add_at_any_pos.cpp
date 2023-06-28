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
            newn->prev = temp->next;
            temp->next = newn;
        }
    }

    void add_at_any_pos(int x,int pos)
    {
        dlist* newn = new dlist(x);
        newn->next = NULL;
        newn->prev = NULL;

        dlist* temp = head;

        if(pos == 1)
        {
            for(;temp->next!=head;temp = temp->next){}
            newn->next = head;
            newn->prev = temp;
            temp->next = newn;
            head = newn;
        }

        else
        {
            for(int i = 1;i<pos-1;i++)
            {
                temp = temp->next;
            }

            newn->next = temp->next;
            newn->prev = temp;
            temp->next = newn;
            temp->next->prev = newn;
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

    int gethead()
    {
        return head->data;
    }

    int gettail()
    {
        dlist* temp = head;
        for(;temp->next!=head;temp = temp->next){}
        return temp->data;
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

    list.add_at_any_pos(100,1);
    list.print();
    cout<<endl<<list.gethead();
    cout<<endl<<list.gettail()<<endl;

}