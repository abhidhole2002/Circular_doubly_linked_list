#include<iostream>
using namespace std;

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

    void print()
    {
        dlist* temp = head;
        do
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        } while (temp!=head);    
    }


    void delete_value(int x)
    {
        

        if(head->data == x)
        {
            dlist* temp = head;
            for(;temp->next!=head;temp = temp->next){}
            head = head->next;
            temp->next = head;
            head->prev = temp;    
        }

        else
        {
            dlist* temp = head;
            for(;temp->next!=head;temp = temp->next)
            {
                if(temp->next->data == x)
                {
                    dlist* node = temp->next;
                    temp->next = temp->next->next;
                    temp->next->next->prev = temp;

                    delete node;
                    node = NULL;
                    
                    return;
                }
            }
        }    
    }

    void del_by_pos(int pos)
    {
        if(pos == 1)
        {
            dlist* temp = head;
            for(;temp->next!=head;temp = temp->next){}
            head = head->next;
            temp->next = head;
            head->prev = temp; 
        }

        else
        {
            dlist* temp = head;

            for(int i=1;i<pos-1;i++)
            {
                temp = temp->next;
            }

            dlist* node = temp->next;
            temp->next = temp->next->next;
            temp->next->next->prev = temp;

            delete node;
            node = NULL;
        }
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
    list.delete_value(14);
    list.print();
    cout<<endl;
    list.del_by_pos(4);
    list.print();
 
 
}