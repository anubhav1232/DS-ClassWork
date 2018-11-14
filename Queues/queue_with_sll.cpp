#include<iostream>
using namespace std;

class q_ll
{
    struct node
    {
        int value;
        struct node*  next;
    };
    struct node* front;
    struct node* new_node;
    struct node* ptr;
    struct node* rear;
    struct node* temp;
    struct node* copy_;
    int count;
public:
    q_ll()
    {
        front=NULL;
        count = 0;
    }
    void enqueue(int num)
    {
        if(front==NULL)
        {

            new_node = new node;
            new_node->value = num;
            new_node->next = front;
            front = new_node;
            rear = new_node;
            count++;
        }
        else
        {
            new_node = new node;
            new_node->value = num;
            new_node->next = NULL;
            rear->next = new_node;
            rear = new_node;
            count++;
        }
    }
    void dequeue()
    {
        if(front != rear) {
            temp = front;
            cout << front -> value << endl;
            front = temp -> next;
            temp -> next = NULL;
            delete temp;
        }
        else if(front == NULL){
            cout << endl << "UNDERFLOW" << endl;
        }
        else{
            temp = front;
            cout << front -> value << endl;
            delete temp;
            front = NULL;
            rear = NULL;
        }
    }
    void show()
    {
        cout << endl << endl;
        if(front == NULL)
        	cout << "UNDERFLOW" << endl;
        while(front!=NULL)
        {
            dequeue();
        }
        cout << endl;
    }
};

int main()
{
    int n , num , given;
    char a ;
    q_ll obj1;
    int created = false;
    cout << "Hello user to this program for operations with queue using linked list" << endl;
    cout << "Select any of the following operations using index number of the option" << endl;
    cout << "1. Insertion of element into queue -> enqueue" << endl <<"2. Display the linked list" << endl << "3. Delete an element -> Dequeue" << endl;
    cout << "Enter -1 for termination/ completion of any function / program" << endl;
    cin >> n;
    while (n != -1)
    {
        switch (n)
        {
            case 1:{
                cin >> num;
                obj1.enqueue(num);
                created = true;
                break;
            }
            case 2:{
                if(created)
                    obj1.show();
                else
                    cout << "UNDERFLOW" << endl;
                break;
            }
            case 3:{
                obj1.dequeue();
                break;
            }
            default:{
                cout << "invalid input "<< endl;
            }
        }
        cout << "Select any of the following operations using index number of the option" << endl;
        cout << "1. Insertion of element into queue -> enqueue" << endl <<"2. Display the linked list" << endl << "3. Delete an element -> Dequeue" << endl;
        cout << "Enter -1 for termination/ completion of any function / program" << endl;
        cin >> n;
    }
    return 0;
}
