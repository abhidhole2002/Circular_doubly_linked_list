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

    void sort()
    {
        dlist* curr = head;
        dlist* temp = NULL;

        do 
        {
            for(temp = curr->next;temp!=head;temp = temp->next)
            {
                if(curr->data < temp->data)
                {
                    int td = temp->data;
                    temp->data = curr->data;
                    curr->data = td;
                }
            }
            curr = curr->next;
        }while(curr!=head);
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

    int size;
    cout<<"enter size of node = ";
    cin>>size;

    int a[size];

    cout<<"enter elements : ";
    for(int i = 0;i<size;i++)
    {
        cin>>a[i];
    }

    cout<<"Nodes of list = ";
    for(int i=0;i<size;i++)
    {
        list.add_tail(a[i]);
    }

    list.print();
    cout<<endl;
    list.sort();
    list.print();
 
 
}