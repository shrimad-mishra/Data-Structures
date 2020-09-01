#include<iostream>

using namespace std;

class node
{
    public:
        int data;
        node * next;
        node * prev;
};

class linked_list
{
    private:
        node * head;
        node * tail;

    public:
        linked_list()
        {
            head = NULL;
            tail = NULL;
        }

        node * createnode()
        {
            node * s;
            s = new node;
            return s;
        }

        void insert(int data)
        {
            node * s;
            s = createnode();
            
            s->data = data;
            s->prev = NULL;
            s->next = NULL;

            if(head==NULL)
            {
                head = s;
                tail = s;
            }
            else
            {
                s->prev = tail;
                tail->next = s;
                tail = s;
            }
        }

        void insert_beg()
        {
            int data ;
            cout<<"Enter the data to insert in the begning"<<endl;
            cin>>data;
            node * s;
            s = createnode();
            s->data = data;
            s->prev = NULL;
            s->next = head;
            head->prev = s; 
            head = s;
        }

        void insert_end()
        {
            int data;
            
            cout<<"Enter the data too insert in the end"<<endl;
            cin>>data;
            node *s, *p;
            s = head;
            while(s->next!=NULL)
            {
                s = s->next;
            }
            p = createnode();
            p->data = data;
            p->prev = s;
            p->next = NULL;
            s->next = p;
        }

        void insert_random()
        {
            int data, pos;
            
            cout<<"Enter the position to insert the data"<<endl;
            cin>>pos;

            cout<<"Enter the data to insert at "<<pos<<" in the list"<<endl;
            cin>>data;

            node *p, *s;
            s = head;
            p = createnode();
            p->data = data;
            p->next = NULL;

            if(pos==1)
            {
                p->next = head;
                p->prev = NULL;
                head->prev = p;
                head = p;
                return ;
            }

            for(int i = 1; i < pos-1; i++)
            {
                s = s->next;
            }
            p->prev = s;
            p->next = s->next;
            s->next = p;
        }

        void del_beg()
        {
            node * s;
            s = head;
            head = s->next;
            head->prev = NULL;
            cout<<s->data<<" is deleted from the list"<<endl;
            delete(s);
        }

        void del_end()
        {
            node * s = head;
            while(s->next->next!=NULL)
            {
                s = s->next;
            }

            node * p;
            p = s->next;
            
            cout<<s->next->data<<" is delted from the list"<<endl;
            s->next = NULL;
            delete(p);
        }

        void del_random()
        {
            node *s, *p;
            int pos;
            
            cout<<"Enter the position to delete the data"<<endl;
            cin>>pos;

            if(pos==1)
            {
                del_beg();
                return ;
            }

            s = head;

            for(int i = 1; i < pos-1; i++)
            {
                s = s->next;
            }
            p = s->next;
            p->next->prev = s;
            s->next = p->next;
    
            cout<<p->data<<" is deleted from the list"<<endl;

            delete(p);
        }

        void search()
        {
            node * s = head;
            int data,c;

            c = 0;

            cout<<"Enter the data to search in the list"<<endl;
            cin>>data;

            while(s!=NULL)
            {
                if(s->data==data)
                {
                    c = 1;
                }
                s = s->next;
            }

            if(c==1)
            {
                cout<<"Data is prsenet in the list"<<endl;
            }
            else
            {
                cout<<"Data is not present in the list"<<endl;
            }

        }

        void insert_loop()
        {
            int pos;

            cout<<"Enter the position to insert the loop"<<endl;
            cin>>pos;

            node * s;
            s=head;

            for(int i = 0; i < pos; i++)
                s = s->next;
            
            tail->next = s;
        }

        void check()
        {
            node *slow, *fast;
            slow = head;
            fast = head;

            while(slow && fast && fast->next)
            {
                fast = fast->next->next;
                slow = slow->next;
                if(slow==fast)
                {
                    cout<<"Loop is present"<<endl;
                    exit(0);
                }
            }
            cout<<"Loop is not present"<<endl;
        }

        void del_loop()
        {
            node *slow, *fast;
            slow = head;
            fast = head;

            while(slow && fast && fast->next)
            {
                fast = fast->next->next;
                slow = slow->next;
                if(slow==fast)
                {
                    break;
                }
            }
            node * s;
            s = head;
            while(s!=slow)
            {
                s = s->next;
            }
            s->next = NULL;

        }

        void display()
        {
            node * s;
            s = head;
            if(s==NULL)
            {
                cout<<"List is empty "<<endl;
                return ;
            }
            while(s!=NULL)
            {
                cout<<s->data<<" ";
                s = s->next;
            }

            cout<<endl;
        }
};

int main()
{
    int i,n;
    linked_list l;
    cout<<"Enter the number of the elements in the list"<<endl;
    cin>>n;
    cout<<"Enter the data in the list"<<endl;
    int data;
    for(i = 0; i < n; i++)
    {
        cin>>data;
        l.insert(data);
    }

    cout<<"Data in the list is shown below"<<endl;
    l.display();

    l.insert_beg();
    cout<<"List after inserting items in the begning"<<endl;
    l.display();

    l.insert_end();
    cout<<"List after inserting items in the end"<<endl;
    l.display();

    l.del_beg();
    cout<<"List after deleting items from the begning"<<endl;
    l.display();

    l.del_end();
    cout<<"List after deleting items in the end"<<endl;
    l.display();

    l.insert_random();
    cout<<"List after deleting items in the end"<<endl;
    l.display();
    
    l.del_random();
    cout<<"List after deleting items in the end"<<endl;
    l.display();

    l.search();

    l.insert_loop();

    l.check();

    l.del_loop();

    l.check();

    return 0;
}