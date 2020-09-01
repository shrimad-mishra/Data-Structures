#include<iostream>

using namespace std;

class node
{
    public:
        int data;
        node * next;
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
            s->next = head;
            if(head==NULL)
            {
                head = s;
                tail = s;
            }
            else
            {
                tail->next = s;
                s->next = head;
                tail = s;
            }
        }

        void display()
        {
            node * s = head;
            if(s==NULL)
            {
                cout<<"List is empty"<<endl;
                return ;
            }
            do
            {
                cout<<s->data<<" ";
                s = s->next;
            } while (s->next!=head->next);

            cout<<endl;
        }
};

int main()
{
    int data,n,i;

    cout<<"Enter the number of the data in teh linked list"<<endl;
    cin>>n;

    linked_list l;
    cout<<"Enter the data in the linked list"<<endl;
    for(i = 0; i < n; i++)
    {
        cin>>data;
        l.insert(data);
    }

    cout<<"Here is the data in the linked list"<<endl;
    l.display();

    return 0;
}