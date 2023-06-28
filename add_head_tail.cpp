#include<iostream>
using namespace std;

class cdlist
{
    int data;
    cdlist* head;
    cdlist* next;
    cdlist* prev;

    public:
    
    cdlist(int data)
    {
        this->data = data;
        this->head = NULL;
        this->next = NULL;
        this->prev = NULL;
    }

    void addhead(int x)
    {
        cdlist* newn = new cdlist(x);
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
            cdlist* temp;
            for(temp = head;temp->next!=head;temp= temp->next){}
            newn->next = head;
            newn->prev = temp->next;
            temp->next = newn;
            head = newn;
        }
    }


     void addtail(int x)
    {
        cdlist* newn = new cdlist(x);
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
            cdlist* temp;

            for(temp = head;temp->next!=head;temp= temp->next)
            {}

            newn->next = head;
            newn->prev = temp->next;
            temp->next = newn;
        }
    }

    void print()
    {
        cdlist* temp = head;
        int c = 0;
        for(;(c==0 || temp!=head);temp = temp->next)
        {
            cout<<temp->data<<" ";
            c++;
        }
    }

    void print2()
    {
        cdlist* temp = head;
        while(true)
        {
            cout<<temp->data<<" ";
            temp = temp->next;

            if(temp == head)
            {
                break;
            }
        }  
    }

    int gethead()
    {
        return head->data;
    }

    int gettail()
    {
        cdlist* temp = head;
        for(;temp->next!=head;temp = temp->next){}
        return temp->data;

    }

    


    void delete_head()
    {
            if(head->next==head)
            {
                delete head;
                head = NULL;
            }

            else
            {
                cdlist *temp = head;
                cdlist* ptr = head;

                for(;temp->next!=head;temp=temp->next){}
                head = head->next;
                head->prev = temp;
                temp->next=head;

                delete ptr;
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
            cdlist *temp = head;

            for(;temp->next->next!=head;temp=temp->next){}

            cdlist* del = temp->next;
            temp->next = head;
            head->prev = temp;

            delete del;
            del = NULL;
        }    
    }

    void add_at_any(int x,int pos)
    {
        cdlist* newn = new cdlist(x);
        newn->next = NULL;
        newn->prev = NULL;

        cdlist* temp = head;

        if(pos == 1)
        {
            for(;temp->next!=head;temp= temp->next){}
            newn->next = head;
            newn->prev = temp->next;
            temp->next = newn;
            head = newn;
            return;
        }

        for(int i=1;i<pos-1;i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next = newn;
        newn->next->prev = newn;
    }


    void delete_node(int x)
    {
        if(head->data == x)
        {
            if(head->next==head)
            {
                delete head;
                head = NULL;
            }

            else
            {
                cdlist *temp = head;
                cdlist* ptr = head;

                for(;temp->next!=head;temp=temp->next){}
                head = head->next;
                head->prev = temp;
                temp->next=head;

                delete ptr;
                ptr = NULL;
            }
            return;
        }

        cdlist* temp = head;
        for(;temp->next!=NULL;temp = temp->next)
        {
            if(temp->next->data == x)
            {
                cdlist* del = temp->next;
                temp->next = temp->next->next;
                temp->next->next->prev = temp;
                
                delete del;
                del = NULL;
                return;
            }
        }
    }

    void delany(int num)
    {
            if(head->data== num)
            {
                delete_head();
                return;
            }

            else
            {
                cdlist *temp = head;
                cdlist *p = head;

                while(temp->data!=num)
                {
                    p = temp;
                    temp=temp->next;
                }

                p->next = temp->next;
                temp->next->prev = p;
                delete temp;
                temp = NULL;
            }
    }


    void del_pos(int pos)
    {
        if(pos == 1)
        {
            if(head->next==head)
            {
                delete head;
                head = NULL;
            }

            else
            {
                cdlist *temp = head;
                cdlist* ptr = head;

                for(;temp->next!=head;temp=temp->next){}
                head = head->next;
                head->prev = temp;
                temp->next=head;

                delete ptr;
                ptr = NULL;
            }  
            return;
        }

        else
        {
            cdlist* temp = head;

            for(int i=1;i<pos-1;i++)
            {
                temp = temp->next;
            }

            cdlist* del = temp->next;
            temp->next = temp->next->next;
            if(temp->next!=NULL)
            {
                temp->next->prev = temp;
            }

            delete del;
            del = NULL;
        }
    }

    int findmid()
    {
        cdlist* slow = head;
        cdlist* fast = head;

        while(fast->next!=head && fast->next->next!=head)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }

    int count()
    {
        int cnt = 1;
        for(cdlist* temp = head;temp->next!=head;temp = temp->next)
        {
            cnt++;
        }
        return cnt;
    }

    void nth_min_max(int x)
    {
        cdlist* curr = head;
        cdlist* temp = NULL;
        int c = 0;
        int res = 0;

        for(;(curr!=head || c==0);curr = curr->next)
        {
            for(temp = curr->next;temp!=head;temp = temp->next)
            {
                if(temp->data > curr->data)
                {
                    int td = temp->data;
                    temp->data = curr->data;
                    curr->data = td;
                }
            }

            c++;

            if(c == x)
            {
                res = temp->data;
            }
        }
        cout<<" min max = "<<res<<endl;
    }


    void add_mul()
    {
        cdlist* temp = head;

        int add = 0;
        int mul = 1;
        int c=0;

        /*for(;(c==0 || temp!=head);temp = temp->next)
        {
            add = add + temp->data;
            mul = mul * temp->data;
            c++;
        }*/

        do
        {
            add = add + temp->data;
            mul = mul * temp->data;
            temp = temp->next;
        
        } while(temp!=head);
        

        cout<<"ADD = "<< add<<endl;
        cout<<"MUL = "<< mul<<endl;
    }


    int search(int x)
    {
        cdlist* temp = head;

        do
        {
            if(temp->data == x)
            {
                return 1;
            }
            temp = temp->next;
        } while (temp!=head);

        return -1;
        
    }


    void sort()
    {
        cdlist* temp = head;
        cdlist* curr = NULL;

        do
        {
            for(curr = temp->next;curr!=head;curr = curr->next)
            {
                if(temp->data > curr->data)
                {
                    int td = temp->data;
                    temp->data = curr->data;
                    curr->data = td;
                }
            }

            temp = temp->next;

        } while (temp!=head);
        
    }

    


};
 
int main()
{
    cdlist list(0);
    list.addhead(10);
    list.addhead(11);
    list.addhead(12);
    list.addhead(13);
    list.addhead(14);
    list.addtail(9);
    list.addtail(8);
    list.addtail(7);
    list.addtail(6);
    list.addtail(14);
    list.print();
    cout<<endl;
    list.print2();

    cout<<endl;

    list.delete_head();
    list.print2();
    cout<<endl;
    list.delete_tail();
    list.print2();
    cout<<endl<<list.gethead();
    cout<<endl<<list.gettail();
    cout<<endl;
    list.add_at_any(1000,8);
    list.print2();

    cout<<endl;
    //list.delany(1000);
    //list.print2();
    cout<<endl;
    list.delete_node(13);
    list.print2();
    cout<<endl;
    list.delany(12);
    list.print2();
    cout<<endl;

    list.del_pos(6);
    list.print2();
    cout<<endl<<list.findmid()<<endl;
    cout<<endl<<list.count()<<endl;
    list.nth_min_max(1);
    cout<<endl;
    list.add_mul();

    cout<<list.search(5)<<endl;
    list.sort();
    list.print2();
    
}