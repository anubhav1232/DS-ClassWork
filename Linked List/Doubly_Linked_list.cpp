#include <iostream>
using namespace std;

struct node
{
    int value;
    struct node * prev;
    struct node * next;
};

class dll
{
    struct node * start;
    struct node * save;
    struct node * copy_;
    struct node * new_node;
    struct node * ptr;
    struct node * tail;

public:

    dll()
    {
        start = NULL;
        save = NULL;
        copy_ = NULL;
    }

    void create_dll(int num)
    {
        while(num != -1)
        {
            if(start == NULL)
            {
                new_node = new node;
                new_node -> value = num;
                new_node -> prev = NULL;
                new_node -> next = NULL;
                start = new_node;
            }
            else
            {
                new_node = new node;
                new_node -> value = num;
                new_node -> prev = NULL;
                new_node -> next = start;
                start -> prev = new_node;
                start = new_node;
            }
            cin >> num;
        }
    }
    void create_dll_opp(int num)
    {
        while(num != -1)
        {
            if(start == NULL)
            {
                new_node = new node;
                new_node -> value = num;
                new_node -> prev = NULL;
                new_node -> next = NULL;
                start = new_node;
                save = new_node;
            }
            else
            {
                new_node = new node;
                new_node -> value = num;
                new_node -> prev = save;
                new_node -> next = NULL;
                save -> next = new_node;
                save = new_node;
            }
            cin >> num;
        }
    }
    void insert_beg(int num)
    {
        ptr = start;
        new_node = new node;
        new_node -> value = num;
        new_node -> next = start;
        new_node -> prev = NULL;
        start -> prev = new_node;
        start = new_node;
    }
    void insert_end(int num)
    {
        ptr = start;
        while(ptr -> next != NULL)
        {
            ptr = ptr -> next;
        }
        new_node = new node;
        new_node ->value = num;
        new_node ->prev = ptr;
        new_node ->next = NULL;
        ptr -> next = new_node;
    }
    void insert_after(int given,int num)
    {
        ptr = start;
        while(ptr != NULL)
        {
            if(ptr -> value == given)
                break;
            ptr = ptr-> next;
        }
        if(ptr -> next == NULL)
            insert_end(num);
        else{
            new_node = new node;
            new_node -> value = num;
            new_node -> next = ptr -> next;
            new_node -> prev = ptr;
            ptr -> next -> prev = new_node;
            ptr -> next = new_node;
        }
    }
    void insert_before(int given,int num)
    {
        ptr = start;
        while(ptr != NULL)
        {
            if(ptr -> value == given)
                break;
            ptr = ptr-> next;
        }
        if(ptr -> prev = NULL)
            insert_beg(num);
        else{
            new_node = new node;
            new_node -> value = num;
            new_node -> next = ptr;
            new_node -> prev = ptr -> prev;
            ptr -> prev -> next = new_node;
            ptr -> prev = new_node;
        }
    }
    void insert_given_pos(int num,int pos)
    {
        ptr = start;
        int count = 1;
        if(pos == 1)
            insert_beg(num);
        else {
            while (ptr != NULL) {
                if (count == pos)
                    break;
                ptr = ptr->next;
                count++;
            }
            if (ptr->next == NULL)
                insert_end(num);
            else {
                new_node = new node;
                new_node->value = num;
                new_node->next = ptr;
                new_node->prev = ptr->prev;
                ptr->prev->next = new_node;
                ptr->prev = new_node;
            }
        }
    }
    void del_beg()
	{
  		ptr=start;
    	if (ptr -> next==NULL)
    	{
    	    start=NULL;
    	    delete ptr;
    	}
    	else
    	{
    		start=ptr -> next;
     		ptr -> next -> prev=NULL;
    		ptr -> next=NULL;
   			delete ptr;
    	}
	}
	void del_end()
	{
    	tail = start;
    	while (tail->next != NULL)
    	{
       		tail=tail->next;
    	}
    	ptr=tail;
    	if (tail->prev==NULL)
        	start=NULL;
    	else {
    		ptr -> prev->next=NULL;
    		tail=ptr->prev;
    		ptr->prev=NULL;
    	}
    	delete ptr;
	}
	void del_given(int num)
	{
    	ptr=start;
   		while (ptr != NULL)
    	{
        	if (ptr->value==num)
        	{
           		break;
        	}
            	ptr=ptr->next;
    	}
    	if (ptr->next==NULL)
    	{
        	del_end();
    	}
    	else if (ptr->prev==NULL)
    	{
        	del_beg();
    	}
    	else{
        	ptr->prev->next=ptr->next;
        	ptr->next->prev=ptr->prev;
        	ptr->prev=NULL;
        	ptr->next=NULL;
        	delete ptr;
    	}
	}
    void show() {
        cout << endl << endl;
        ptr = start;
        while (ptr != NULL) {
            cout << ptr->value << endl;
            ptr = ptr->next;
        }
    }
};

int main()
{
    int n , num , given;
    char a ;
    dll obj1;
    bool created = false;
    cout << "Hello user to this program for operations with linked list" << endl << "Select any of the following operations using index number of the option" << endl;
    cout << "1. Create a linked list" << endl <<"2. Display the linked list" << endl <<"3. insert an element to the list" << endl;
    cout << "4. Deleting an Element" << endl;
    cout << "Enter -1 for termination/ completion of any function / program";
    cin >> n;
    while (n != -1)
    {
        switch (n)
        {
            case 1:
            {
                cout << "Enter how you want to create the list" << endl;
                cout << "b for insertion at beginning" << endl;
                cout << "e for insertion at the end" << endl;
                cin >> a;
                if(a == 'b' || a == 'B') {
                    cin >> num;
                    obj1.create_dll(num);
                    created = true;
                }
                else if(a == 'e' || a == 'E')
                {
                    cin >> num;
                    obj1.create_dll_opp(num);
                    created = true;
                }
                else
                {
                    cout << "invalid option. Try again" << endl;
                }
            }
            case 2:
            {
                if(created)
                    obj1.show();
                else
                    cout << "list not created";
            }
            case 3:
            {
                cout << "enter the following option for insertion" << endl;
                cout << "b for insertion at beginning" << endl;
                cout << "e for insertion at the end" << endl;
                cout << "a for after given element" << endl;
                cout << "g for before given element" << endl;
                cout << "p for insertion of element at desired position" << endl;
                cin >> a;
                if (a == 'b') {
                    cin >> num;
                    obj1.insert_beg(num);
                } else if (a == 'e') {
                    cin >> num;
                    obj1.insert_end(num);
                } else if (a == 'a') {
                    cin >> given;
                    cin >> num;
                    obj1.insert_after(given, num);
                } else if (a == 'g') {
                    cin >> given;
                    cin >> num;
                    obj1.insert_before(given, num);
                } else if (a == 'p') {
                    cin >> given;
                    cin >> num;
                    obj1.insert_after(given, num);
                } else {
                    cout << "no matching option";
                }
            }
            case 4:
            {
            	char j;
            	cout<<"press f to delete first element"<<endl<<"press l to delete last element"<<endl<<"press s to delete a specific element"<<endl;
            	cin>>j;
            	if(j=='f')
                	obj1.del_beg();
            	else if(j=='l')
                	obj1.del_end();
            	else if(j=='s')
            	{
                	cout<<"enter the number you want to delete"<<endl;
                	cin>>num;
                	obj1.del_given(num);
            	}
        	}
        }
		cout << "1. Create a linked list" << endl <<"2. Display the linked list" << endl <<"3. insert an element to the list" << endl;
   		cout << "4. Deleting an Element" << endl;
  		cout << "Enter -1 for termination/ completion of any function / program";
   		cin >> n;
    }
    return 0;
}
