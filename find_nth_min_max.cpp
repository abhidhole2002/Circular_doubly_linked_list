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
            newn->next = head;
            newn->prev = head;
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

    void nth_min_max(int x)
    {
        dlist* temp = head;
        dlist* curr = NULL;
        int c = 0;
        int res = 0;

        //for(;(c == 0 || temp!=head);temp = temp->next)
        do
        {
            for(curr = temp->next;curr!=head;curr = curr->next)
            {
                if(temp->data < curr->data)
                {
                    int td = temp->data;
                    temp->data = curr->data;
                    curr->data = td;
                }
            }
            c++;

            if(c==x)
            {
                res = temp->data;
            }

            temp = temp->next;
        }while(temp!=head);

        cout<<res<<endl;
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

    list.nth_min_max(4);
 
 
}