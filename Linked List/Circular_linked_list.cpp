#include<iostream>
using namespace std;

class cll
{
    struct node
    {
        int value;
        struct node*  next;
    };
    struct node* start;
    struct node* new_node;
    struct node* ptr;
    struct node* save;
    struct node* temp;
    struct node* copy_;
public:
    cll()
    {
        start=NULL;
    }
    void create_ll_b(int num)
    {
        while(num!=-1)
        {
        	if(start==NULL){
            	new_node = new node;
            	new_node->value = num;
            	new_node->next = start;
            	save = new_node;
            	start = new_node;
        	}
        	else{
        		new_node = new node;
        		new_node -> value = num;
        		new_node -> next = start;
        		start = new_node;
        		
        	}
        	cin >> num;
        }
        save -> next = start;
    }
    void create_ll_f(int num)
    {
        while(num!=-1)
        {
            if(start==NULL)
            {

                new_node = new node;
                new_node->value = num;
                new_node->next = start;
                start = new_node;
                save = new_node;
            }
            else
            {
                new_node = new node;
                new_node->value = num;
                new_node->next = NULL;
                save->next = new_node;
                save = new_node;
            }
            cin >> num;
        }
        save ->next = start;
    }
    void insert_beg(int no) {
        ptr = start;
        do{
            if(ptr->next == start){
                break;
            }
            ptr = ptr->next;
        }while(ptr != start);
        new_node = new node;
        new_node->value = no;
        new_node->next = start;
        start = new_node;
        ptr -> next = new_node;
    }
    void insert_end(int num)
    {
        ptr = start;
        do{
            if(ptr->next == start){
                break;
            }
            ptr = ptr->next;
        }while(ptr != start);
        new_node=new node;
        new_node->value=num;
        new_node->next= start;
        save->next=new_node;
        save=new_node;
    }
    void insert_after(int given,int num)
    {   
			copy_==NULL;
        	ptr=start;
        	while(ptr->next!=save->next)
        	{
            	if(ptr->value==given)
            	{
                break;
            	}
            	ptr=ptr->next;
        	}
        	if(ptr->next==save->next)
        	{
        		insert_end(num);
        	}
        	else if(ptr->next == start -> next)
        	{
        		insert_beg(num);
        	}
        	else{
        		new_node=new node;
        		new_node->value=num;
        		new_node->next=ptr->next;
        		ptr->next=new_node;
        	}
    }
    void insert_before(int given,int num)
    {   
			copy_==NULL;
        	ptr=start;
        	while(ptr->next!=save->next)
        	{
            	if(ptr->value==given)
            	{
                break;
            	}
            	copy_=ptr;
            	ptr=ptr->next;
        	}
        	if(ptr->next == start -> next)
        	{
        		insert_beg(num);
        	}
        	else{
        		new_node=new node;
        		new_node->value=num;
        		new_node->next=ptr;
        		copy_->next=new_node;
        	}
    }
    void insert_pos(int pos,int num){
    	int count = 0;
    	if(pos == 0)
    	{
    		insert_beg(num);
    	}
    	else if(pos!=0)
    	{
    		ptr = start;
    		copy_=NULL;
    		while(ptr->next!=save->next)
    		{
    			if(pos==count)
    				break;
    			pos++;
    			copy_=ptr;
    			ptr = ptr->next;
    		}
    		if(ptr -> next == save -> next)
    		{
    			insert_end(num);
    		}
    		else
    		{
    			new_node = new node;
    			new_node -> value = num;
    			new_node -> next = ptr;
    			copy_ -> next = new_node;
    		}
    	}
    }
    void insert_sort(int num){
    	
    }
    void delete_first()
    {
        ptr = start;
        save = start;
    }
    void show()
    {
        cout << endl << endl;
        ptr = start;
        do{
            if(ptr->next == start){
               cout << ptr ->value << " " ;
                break;
            }
            cout << ptr ->value <<" ";
            ptr = ptr->next;
        }while(ptr != start);
        ptr = ptr-> next;
        cout << ptr -> value << " ";
    }
};
/*int main()
{
    int no;
    cll obj1;
    /*obj1.create_ll_back();
    obj1.show();
    cout << endl << "Enter the number u wish to add to the list at the start " << endl;
    cin >> no;
    obj1.insertion_beg(no);
    obj1.show();
    cout << endl << "Enter the number u wish to add to the list at the end " << endl;
    cin >> no;
    obj1.insert_end(no);
    obj1.show();
	obj1.create_ll_b();
	obj1.show();
	obj1.insert_after(1,1);
	obj1.insert_after(3,6);
	obj1.insert_after(5,7);
	obj1.show();
    return 0;
}*/
int main()
{
    int n , num , given;
    char a ;
    cll obj1;
    flag created = false;
    cout << "Hello user to this program for operations with circular linked list" << endl;
    cout << "Select any of the following operations using index number of the option" << endl;
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
                    obj1.create_ll_b(num);
                    created = true;
                }
                else if(a == 'e' || a == 'E')
                {
                    cin >> num;
                    obj1.create_ll_f(num);
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
                cout << "enter the option for deletion"
            }
        }

    }
    return 0;
}
