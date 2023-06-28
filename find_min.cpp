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

    int count()
    {
        int c = 0;
        dlist* temp = head;
        do
        {
            c++;
            temp = temp->next;

        }while(temp!=head);
        return c;
    }

    void mid()
    {
        dlist* slow = head;
        dlist* fast = head;

        while(fast->next!=head && fast->next->next!=head)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if(count()%2 == 0)
        {
            cout<<"MID = "<<slow->next->data<<endl;
        }
        else
        {
            cout<<"MID = "<<slow->data<<endl;
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
    list.add_tail(15);
    list.print();
    cout<<endl;
    list.mid();
    cout<<endl;
    
 
 
}